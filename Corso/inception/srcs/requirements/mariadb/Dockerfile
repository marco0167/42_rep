FROM debian:bullseye

# update and upgrade the system
RUN apt-get update && apt-get upgrade -y

# # install the required packages
RUN apt-get install -y mariadb-server

# copy file from host to container
COPY ./configurations/entrypoint.sh /entrypoint.sh

# set permissions to the file
RUN chmod +x /entrypoint.sh

# define entrypoint command to run when the container starts
ENTRYPOINT ["./entrypoint.sh"]