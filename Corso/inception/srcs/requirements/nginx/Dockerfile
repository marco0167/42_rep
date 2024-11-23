FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y nginx

RUN apt-get install -y openssl

COPY ./configurations/nginx.conf /etc/nginx/nginx.conf

COPY ./configurations/entrypoint.sh ./entrypoint.sh

RUN chmod +x ./entrypoint.sh

RUN mkdir -p /var/www/wordpress

RUN chown -R www-data:www-data /var/www/wordpress

ENTRYPOINT ["./entrypoint.sh"]
