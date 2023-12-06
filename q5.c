//
// Created by valeprio54 on 06/12/23.
//

#include <sys/wait.h>
#include "fonctions.h"

void q5() {

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
            }

            else if (WIFSIGNALED(status)) {
                sprintf(command,PROMPT_SIGN, WTERMSIG(status));
            }

            prompt();
        }
    }
}