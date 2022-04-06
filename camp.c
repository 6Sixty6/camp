/* 
CAMP
SixSixtySix anusO1
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *scanner(void *vargp) {
    //scanner here
    return NULL;
}

int main(int argc, char **argv) {
    printf("SixSixtySix anusO1\n");
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, scanner, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
