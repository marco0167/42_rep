FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y curl

RUN apt-get install -y php php7.4-fpm php-mysql

RUN apt-get install -y mariadb-client

RUN apt-get install -y netcat

COPY ./configurations/entrypoint.sh /

RUN  chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
