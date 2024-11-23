FROM debian:bullseye

# Update and upgrade the system
RUN apt-get update && apt-get upgrade -y

# Install the required packages
RUN apt-get install -y nginx openssl

# Copy the nginx configuration file
COPY ./configurations/nginx.conf /etc/nginx/nginx.conf

# Copy the entrypoint shell script into the container
COPY ./configurations/entrypoint.sh ./entrypoint.sh

# Ensure the entrypoint script is executable
RUN chmod +x ./entrypoint.sh

# Create the WordPress directory
RUN mkdir -p /var/www/wordpress

# Change the owner of the WordPress directory to www-data
RUN chown -R www-data:www-data /var/www/wordpress

# Define the entry point script to run when the container starts
ENTRYPOINT ["./entrypoint.sh"]
