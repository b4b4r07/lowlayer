#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int argc;
    char cmd[80];
    char *cmdp;
    char *argv[10];
    int status;

    for (;;) {
        printf("$ ");

        if (fgets(cmd, 80, stdin) == NULL) exit(0);
        cmd[strlen(cmd)] = '\0';
        cmdp = cmd;

        for (argc = 0; ; argc++) {
            if ((argv[argc] = strtok(cmdp, " ")) == NULL) break;
            cmdp = NULL;
        }

        if (strcmp(argv[0], "exit\n") == 0) exit(0);
        if (fork() == 0) {
            execvp(argv[0], argv);
            printf("not found\n");
            exit(1);
        } else {
            wait(&status);
        }
    }
}
