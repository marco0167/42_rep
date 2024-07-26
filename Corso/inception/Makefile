include srcs/.env
export

all: up

up:
	docker-compose -f srcs/docker-compose.yml up -d --build

down:
	docker-compose -f srcs/docker-compose.yml down

clean: down
	docker system prune -af
	docker volume rm $$(docker volume ls -q)

.PHONY: all up down clean
