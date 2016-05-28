#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd1, fd2;
    char ch;

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) exit(1);
    if ((fd2 = creat(argv[2], 0644)) == -1) exit(1);
    while (read(fd1, &ch, 1) != 0)
        write(fd2, &ch, 1);
}
