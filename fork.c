#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;
    //pid_t val;

    fork();
    if (fork() == 0 ) {
        printf("child\n");
        sleep(1);
    } else {
        wait(&status);
        wait(&status);
        printf("parent\n");
        printf("%d\n", status);
    }
}
