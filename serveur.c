/**

 * serveur.c

 */

// On importe des fichiers.h n?c?ssaires ? l'application
#include <stdio.h>      // Fichier contenant les en-t?tes des fonctions standard d'entr?es/sorties
#include <stdlib.h>     // Fichier contenant les en-t?tes de fonctions standard telles que malloc()
#include <string.h>     // Fichier contenant les en-t?tes de fonctions standard de gestion de cha?nes de caract?res
#include <unistd.h>     // Fichier d'en-t?tes de fonctions de la norme POSIX (dont gestion des fichiers : write(), close(), ...)
#include <sys/types.h>      // Fichier d'en-t?tes contenant la d?finition de plusieurs types et de structures primitifs (syst?me)
#include <sys/socket.h>     // Fichier d'en-t?tes des fonctions de gestion de sockets
#include <netinet/in.h>     // Fichier contenant diff?rentes macros et constantes facilitant l'utilisation du protocole IP
#include <netdb.h>      // Fichier d'en-t?tes contenant la d?finition de fonctions et de structures permettant d'obtenir des informations sur le r?seau (gethostbyname(), struct hostent, ...)
#include <memory.h>     // Contient l'inclusion de string.h (s'il n'est pas d?j? inclus) et de features.h
#include <errno.h>      // Fichier d'en-t?tes pour la gestion des erreurs (notamment perror())
#include <sys/signal.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define P 12332



int creersock(u_short port, int numeroOption, int valeurOption) {

	// On cr?e deux variables enti?res
	int sock, retour;
	int delai = 30;
	int idle = 40;
    int iterationKeepAlive = 15;
	int valReuseAddr = 1;
	// On cr?e une variable adresse selon la structure sockaddr_in (la structure est d?crite dans sys/socket.h)
	struct sockaddr_in adresse;


	sock = socket(AF_INET,SOCK_STREAM,0);

	// Si le code retourn? n'est pas un identifiant valide (la cr?ation s'est mal pass?e), on affiche un message sur la sortie d'erreur, et on renvoie -1
	if (sock<0) {
		perror ("ERREUR OUVERTURE");
		return(-1);
	}

	// On compl?te les champs de la structure sockaddr_in :
	// La famille du socket, AF_INET, comme cit? pr?c?dement
	adresse.sin_family = AF_INET;

	/* Le port auquel va se lier la socket afin d'attendre les connexions clientes. La fonction htonl()
	convertit  un  entier  long  "htons" signifie "host to network long" conversion depuis  l'ordre des bits de l'h?te vers celui du r?seau.
	*/
	adresse.sin_port = htons(port);

	/* Ce champ d?signe l'adresse locale auquel un client pourra se connecter. Dans le cas d'une socket utilis?e
	par un serveur, ce champ est initialis? avec la valeur INADDR_ANY. La constante INADDR_ANY utilis?e comme
	adresse pour le serveur a pour valeur 0.0.0.0 ce qui correspond ? une ?coute sur toutes les interfaces locales disponibles.
	*/
	adresse.sin_addr.s_addr=INADDR_ANY;


        switch(numeroOption){
    		case 0 : break;
    		case 1 : setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valeurOption, sizeof(valeurOption)); break;

    		case 2 : setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

            case 3 : setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

            case 4 : setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &idle, sizeof(int));
                     setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, &delai, sizeof(int));
                     setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, &iterationKeepAlive, sizeof(int));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

            case 5 : setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

            case 6 : setsockopt(sock, SOL_SOCKET, SO_DEBUG, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

		 	case 7 : setsockopt(sock, SOL_SOCKET, SO_DONTROUTE, &valeurOption, sizeof(valeurOption));
		             setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;

            case 8 : setsockopt(sock, SOL_SOCKET, SO_OOBINLINE, &valeurOption, sizeof(valeurOption));
                     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valReuseAddr, sizeof(valReuseAddr));break;
	}


	/*
	bind est utilis? pour lier la socket : on va attacher la socket cr?e au d?but avec les informations rentr?es dans
	la structure sockaddr_in (donc une adresse et un num?ro de port).
	Ce bind affecte une identit? ? la socket, la socket repr?sent?e par le descripteur pass? en premier argument est associ?e
	? l'adresse pass?e en seconde position. Le dernier argument repr?sente la longueur de l'adresse.
	Ce qui a pour but de  rendre la socket accessible de l'ext?rieur (par getsockbyaddr)
	*/
	retour = bind (sock,(struct sockaddr *)&adresse,sizeof(adresse));

	// En cas d'erreur lors du bind, on affiche un message d'erreur et on renvoie -1
	if (retour<0) {
		perror ("IMPOSSIBLE DE NOMMER LA SOCKET");
		return(-1);
	}

	// Au final, on renvoie sock, qui contient l'identifiant ? la socket cr?e et attach?e.
	return (sock);
}


int main (int argc, char *argv[]) {

	int numeroOption = 0;
	int valeurOption = 0;

	printf(" ---------------- Serveur ---------------- \n");

	if(argc == 3){
		numeroOption = atoi(argv[1]);
		valeurOption = atoi(argv[2]);
	}

	socklen_t longueurOption = sizeof(valeurOption);
	int newsockfd, s, sock;
	u_short port;
	char message [BUFSIZ];
	port = P;

	// On cr?e la socket
	sock = creersock(port, numeroOption, valeurOption);

	/*
	listen
	permet de dimensionner la taille de la file d'attente.
	On passe en param?tre la socket qui va ?couter, et un entier qui d?signe le nombre de connexions simultan?es autoris?es (backlog)
	*/
	listen (sock,5);

    switch(numeroOption){
        case 1 :
                if(getsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &valeurOption, &longueurOption) == 0)
                    printf("SO_REUSEADDR is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
        case 2 :
		printf("Le socket a recu %d\n", valeurOption);
                if(getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &valeurOption, &longueurOption) == 0)
                    printf("SO_RCVBUF is %s\n", (valeurOption ? "ON" : "OFF"));
                    printf("Le socket a recu %d\n", valeurOption);
                break;
        case 3 :
                if(getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &valeurOption, &longueurOption) == 0)
                    printf("SO_SNDBUF is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
        case 4 :
                if(getsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &valeurOption, &longueurOption) == 0)
                    printf("SO_KEEPALIVE is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
        case 5 :
                if(getsockopt(sock, SOL_SOCKET, SO_BROADCAST, &valeurOption, &longueurOption) == 0)
                    printf("SO_BROADCAST is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
        case 6 :
                if(getsockopt(sock, SOL_SOCKET, SO_DEBUG, &valeurOption, &longueurOption) == 0)
                    printf("SO_DEBUG is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
        case 7 :
                if(getsockopt(sock, SOL_SOCKET, SO_DONTROUTE, &valeurOption, &longueurOption) == 0)
                    printf("SO_DONTROUTE is %s\n", (valeurOption ? "ON" : "OFF"));
                break;
		case 8 :
		        if(getsockopt(sock, SOL_SOCKET, SO_OOBINLINE, &valeurOption, &longueurOption) == 0)
		            printf("SO_OOBINLINE is %s\n", (valeurOption ? "ON" : "OFF"));
		        break;
    }
	while(1){

		newsockfd = accept (sock, (struct sockaddr *) 0, (unsigned int*) 0);

		// Si l'accept se passe mal, on quitte le programme en affichant un message d'erreur.
		if (newsockfd == -1) {
			perror("Erreur accept");
			return(-1);
		}
		else
			printf("Accept ok");


		int r = fork();
		if(r == -1){
			perror("Erreur avec fork");
			return(-1);
		}
		else if(r == 0){ //Fils
			// On lit le message envoy? par la socket de communication.
			//  message contiendra la chaine de caract?res envoy?e par le r?seau,
			// s le code d'erreur de la fonction. -1 si pb et sinon c'est le nombre de caract?res lus
			while(1){
                memset(message, 0, sizeof message);
				s = read(newsockfd, message, BUFSIZ);
				if (s == -1)
					perror("Erreur avec read");
				else {
					// Si le code d'erreur est bon, on affiche le message.
					message[s] = 0;
                    printf("Lecture ok, message: %d\n", s);
					printf("Recept ok, emission message: ");

					// On demande ? l'utilisateur de rentrer un message qui va ?tre exp?di? sur le r?seau
					scanf(" %[^\n]", message);//scanf("%s", message);

					// On va ?crire sur la socket, en testant le code d'erreur de la fonction write.
					s = write(newsockfd, message, strlen(message));
					if (s == -1) {
						perror("Erreur avec write");
						return(-1);
					}
					else
						printf("Ecriture ok, message: %s\n", message);
				}
			} // End of son's while(1)

			// On referme la socket de communication
			close(newsockfd);
		} //Fin du fils
		else { //Pere

		}
	} // End of general while(1)

	// On referme la socket d'?coute.
	close(sock);

	return 0;
}
