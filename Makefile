all: serveur client



serveur: serveur.o

	gcc -o serveur -lnsl serveur.o

serveur.o: serveur.c

	gcc -c serveur.c



client: client.o

	gcc -o client -lnsl client.o

client.o: client.c

	gcc -c client.c


