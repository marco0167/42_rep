FROM debian:buster

RUN apt-get update && apt-get install -y nginx openssl gettext-base

# Generate self-signed certificate
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=login.42.fr"

# Copy custom Nginx configuration
COPY conf/nginx.conf /etc/nginx/nginx.conf.template

# Remove default nginx index page
RUN rm -rf /var/www/html/*

EXPOSE 443

CMD ["/bin/sh", "-c", "envsubst '$$DOMAIN_NAME' < /etc/nginx/nginx.conf.template > /etc/nginx/nginx.conf && nginx -g 'daemon off;'"]
