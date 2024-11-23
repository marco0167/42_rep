#!/bin/bash

#---------------------------------------------------#
#                   WP Installation                 #
#---------------------------------------------------#

# Install WP-CLI
echo "[======== Installing WP-CLI ========]"
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
echo "[======== WP-CLI Installed Successfully ========]"

# Set up WordPress Directory
echo "[======== Setting Up WordPress Directory ========]"
cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress
echo "[======== WordPress Directory Configured ========]"

#---------------------------------------------------#
#                 MariaDB Connectivity              #
#---------------------------------------------------#

# Function to check if MariaDB container is up
ping_mariadb_container() {
    nc -zv mariadb 3306 > /dev/null
    return $?
}

# Wait for MariaDB to be available
echo "[======== Checking MariaDB Status ========]"
start_time=$(date +%s)
end_time=$((start_time + 20))

while [ $(date +%s) -lt $end_time ]; do
    if ping_mariadb_container; then
        echo "[======== MARIADB IS UP AND RUNNING ========]"
        break
    else
        echo "[======== WAITING FOR MARIADB TO START... ========]"
        sleep 1
    fi
done

if [ $(date +%s) -ge $end_time ]; then
    echo "[======== MARIADB IS NOT RESPONDING ========]"
    exit 1
fi

#---------------------------------------------------#
#                  WP Configuration                 #
#---------------------------------------------------#

# Download and set up WordPress
echo "[======== Downloading WordPress Core ========]"
wp core download --allow-root

echo "[======== Configuring WordPress ========]"
wp core config --dbhost=mariadb:3306 --dbname="$MYSQL_DB" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --allow-root

echo "[======== Installing WordPress ========]"
wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_N" --admin_password="$WP_ADMIN_P" --admin_email="$WP_ADMIN_E" --allow-root

echo "[======== Creating a New User ========]"
wp user create "$WP_U_NAME" "$WP_U_EMAIL" --user_pass="$WP_U_PASS" --role="$WP_U_ROLE" --allow-root
echo "[======== WordPress Installation Completed ========]"

#---------------------------------------------------#
#                 PHP Configuration                 #
#---------------------------------------------------#

# Adjust PHP-FPM settings
echo "[======== Configuring PHP-FPM ========]"
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf

# Ensure PHP-FPM directory exists
mkdir -p /run/php

# Start PHP-FPM service
echo "[======== Starting PHP-FPM Service ========]"
/usr/sbin/php-fpm7.4 -F
