DATA_WORDPRESS = ~/data/wordpress 
DATA_MARIADB = ~/data/mariadb

all: up

up:
	docker compose -f ./srcs/docker-compose.yml build
	@mkdir -p $(DATA_WORDPRESS)
	@mkdir -p $(DATA_MARIADB)
	docker compose -f ./srcs/docker-compose.yml up -d
	@echo "starting containers..."

down:
	docker compose -f ./srcs/docker-compose.yml down

exec_mariadb:
	docker exec -it mariadb bash

status:
	docker compose -f ./srcs/docker-compose.yml ps

clean:
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) || true
	@sudo rm -rf $(DATA_WORDPRESS) || true
	@sudo rm -rf $(DATA_MARIADB) || true

re: clean up

prune: clean
	@docker system prune -a --volumes -f
