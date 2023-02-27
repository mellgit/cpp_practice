restart:
	sudo docker-compose up -d --force-recreate
ps:
	sudo docker ps 
pa:
	sudo docker ps -a
down:
	sudo docker-compose down
up:
	sudo docker-compose up -d
images:
	sudo docker images


exec:
	sudo docker exec -it app bash
	