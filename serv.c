#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    int sock = socket(PF_INET, SOCK_DGRAM,0);
    struct addrinfo *first_info;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    int r = getaddrinfo("localhost",argv[1], &hints,&first_info);
    if(r == 0){
        if(first_info != NULL){
            struct sockaddr *saddr=first_info->ai_addr;
            char tampon[100];
            while(1){
                strcpy(tampon,"MESSAGE ");
                strcat(tampon, "test");
                strcat(tampon, " ");
                char entier[3];
                strcat(tampon,entier);
                sendto(sock,tampon,strlen(tampon),0,saddr,(socklen_t)sizeof(struct sockaddr_in));
                sleep(1);
            }

        }
    }
    return 0;
}
