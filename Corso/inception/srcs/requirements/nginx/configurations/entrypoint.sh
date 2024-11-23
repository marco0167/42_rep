#!/bin/bash

# Create the SSL directory if it doesn't exist
mkdir -p /etc/nginx/ssl

# Generate the SSL certificate
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/nginx/ssl/inception.key \
  -out /etc/nginx/ssl/inception.crt \
  -subj "/C=IT/ST=RM/L=RM/O=42/OU=42/CN=mcoppola.42.fr/UID=Marcolozzo"

# Start the Nginx server in the foreground
nginx -g 'daemon off;'
