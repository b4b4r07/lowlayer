#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("before fork: ");
    fflush(stdout);
    if (fork() == 0)
        printf("child\n");
    else
        printf("parent\n");
}
