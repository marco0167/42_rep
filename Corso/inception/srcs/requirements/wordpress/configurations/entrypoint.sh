#!/bin/bash

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress

ping_mariadb_container() {
    nc -zv mariadb 3306 > /dev/null
    return $?
}

start_time=$(date +%s)
end_time=$((start_time + 20))

while [ $(date +%s) -lt $end_time ]; do
    if ping_mariadb_container; then
        echo "[======== MARIADB UP AND RUNNING ========]"
        break
    else
        echo "[======== WAITING FOR MARIADB START... ========]"
        sleep 1
    fi
done

if [ $(date +%s) -ge $end_time ]; then
    echo "[======== MARIADB NOT RESPONDING ========]"
    exit 1
fi

wp core download --allow-root

wp core config --dbhost=mariadb:3306 --dbname="$DB_NAME" --dbuser="$DB_USER" --dbpass="$DB_PASSWORD" --allow-root

wp core install --url="mcoppola.42.fr" --title="inception" --admin_user="$WP_ADMIN_NAME" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root

wp user create "$WP_USERNAME" "$WP_USEREMAIL" --user_pass="$WP_USERPASSWORD" --role="$WP_USERROLE" --allow-root

sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf

mkdir -p /run/php

/usr/sbin/php-fpm7.4 -F
