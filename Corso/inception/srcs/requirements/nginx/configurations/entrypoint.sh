#!/bin/bash

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/nginx/ssl/inception.key \
  -out /etc/nginx/ssl/inception.crt \
  -subj "/C=IT/ST=RM/L=RM/O=42/OU=42/CN=mcoppola.42.fr/UID=marco0167"

nginx -g 'daemon off;'
