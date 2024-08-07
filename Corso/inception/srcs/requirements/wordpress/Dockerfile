# FROM debian:buster

# RUN apt-get update && apt-get install -y php-fpm php-mysql wget

# # Create /run/php/ directory
# RUN mkdir -p /run/php/

# # Change PHP-FPM config to listen on port 9000
# RUN sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/' /etc/php/7.3/fpm/pool.d/www.conf

# RUN mkdir -p /var/www/html

# # Download and set up WordPress
# RUN wget https://wordpress.org/latest.tar.gz && \
#     tar -xzvf latest.tar.gz && \
#     rm latest.tar.gz && \
#     mv wordpress/* /var/www/html && \
#     rmdir wordpress

# COPY conf/wp-config.php /var/www/html/wordpress/wp-config.php

# EXPOSE 9000

# CMD ["php-fpm7.3", "-F"]
