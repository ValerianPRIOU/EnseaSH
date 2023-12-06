//
// Created by valeprio54 on 06/12/23.
//

#include "fonctions.h"

void print(char *string) {
    if (write(STDOUT_FILENO, string, strlen(string)) == -1) { // Error management
        perror("write");
        exit(EXIT_FAILURE);
    }
}

void q4() {

    int nbChar;
    int status;
    char command[MAXSIZE];

    bienvenue();
    prompt();

    while(1) {
        nbChar = read(STDIN_FILENO, command, MAXSIZE);
        command[nbChar - 1] = '\0';

        if (strcmp(command, "exit") == 0 || strcmp(command, "") == 0) {
            endProg();
        }

        pid_t pid = fork();
        if (pid == 0) { // child code

            execute(command);

        } else if (pid > 0) {

            wait(&status);

            if (WIFEXITED(status)) {
                sprintf(command,PROMPT_EXIT, WIFEXITED(status));
                //write(STDOUT_FILENO, PROMPT_EXIT, sizeof(PROMPT_EXIT) - 1);
                //printf(PROMPT_EXIT,status);
            }

            else if (WIFSIGNALED(status)) {
                sprintf(command,PROMPT_SIGN, WTERMSIG(status));
                //write(STDOUT_FILENO, PROMPT_SIGN, sizeof(PROMPT_SIGN) - 1);
                //printf(PROMPT_SIGN,status);
            }

            print(command);
        }
    }
}

