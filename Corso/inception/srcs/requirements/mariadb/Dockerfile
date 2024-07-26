FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server

COPY conf/ /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/docker-entrypoint.sh

EXPOSE 3306

CMD ["/docker-entrypoint-initdb.d/docker-entrypoint.sh"]
