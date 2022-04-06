/* 
CAMP
SixSixtySix anusO1
*/
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

void *multithreading(void *vargp) {
    struct hostent * host;
    int err, i, sock, start, end;
    char hostname[666];
    struct sockaddr_in sa;
    printf("ip address: ");
    scanf("%s", & hostname);
    printf("\nport number to start on: ");
    scanf("%d", & start);
    printf("port number to end on: ");
    scanf("%d", & end);
    strncpy((char * ) & sa, "", sizeof sa);
    sa.sin_family = AF_INET;
    if (isdigit(hostname[0])) {
        sa.sin_addr.s_addr = inet_addr(hostname);
    } else if ((host = gethostbyname(hostname)) != 0) {
        strncpy((char * ) & sa.sin_addr, (char * ) host -> h_addr, sizeof sa.sin_addr);
    } else {
        herror(hostname);
        exit(2);
    }
    printf("starting port scan... \n");
    for (i = start; i <= end; i++) {
        sa.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("\nsocket");
            exit(1);
        }
        err = connect(sock, (struct sockaddr * ) & sa, sizeof sa);
        if (err < 0) {
            fflush(stdout);
        } else {
            printf("%-5d open\n", i);
        }
        close(sock);
    }
    printf("\r");
    fflush(stdout);
}

int main(int argc, char ** argv) {
    printf("SixSixtySix anusO1\n");
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, multithreading, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
