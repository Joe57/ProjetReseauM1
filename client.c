#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <poll.h>

int main(int argc, char *argv[]){
    int sock1 = socket(PF_INET,SOCK_DGRAM,0);
    struct sockaddr_in adress_sock1;
    adress_sock1.sin_family = AF_INET;
    adress_sock1.sin_port = htons(atoi(argv[1]));
    adress_sock1.sin_addr.s_addr=htonl(INADDR_ANY);

    int sock2 = socket(PF_INET, SOCK_DGRAM,0);
    struct addrinfo *first_info;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int r1 = bind(sock1, (struct sockaddr *)&adress_sock1, sizeof(struct sockaddr_in));
     if(r1 == 0){
         int r2 = getaddrinfo("localhost",argv[2], &hints,&first_info);
         if(r2 == 0){
            fcntl(sock1, F_SETFL, O_NONBLOCK);
            fcntl(sock2, F_SETFL, O_NONBLOCK);
            struct pollfd p[2];
            p[0].fd=sock1;
            p[0].events=POLLIN;
            p[1].fd=sock2;
            p[1].events=POLLOUT;
            char tampon[100];
            int rec1 = 0;
            int i;
            while(1){
                int ret = poll(p,2,-1);
                if(ret > 0){
                    for(i = 0; i<2; i++){
                        if(p[0].revents==POLLIN){
                            printf("etat 1\n");
                            rec1=recv(p[i].fd,tampon,100,0);
                            if(rec1>=0){
                                tampon[rec1]='\0';
                                printf("Message recu : %s\n",tampon);
                            }
                        }
                        if(p[1].revents==POLLOUT){
                            printf("etat 2\n");
                            struct sockaddr *saddr=first_info->ai_addr;
                            char *mess = malloc(sizeof(char));
                            printf("saisir le message\n");
                            scanf("%s", mess);
                            printf("%s",mess);
                            sendto(sock2,mess,strlen(mess),MSG_DONTWAIT,saddr,(socklen_t)sizeof(struct sockaddr_in));
                        }

                    }
                }
            }
        }
    }
    return 0;
}
