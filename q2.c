//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void q2() {

    char command[MAXSIZE];
    int nb_byte;
    int status;

    bienvenue();
    prompt();

    while (1) {

        nb_byte = read(STDIN_FILENO, command, MAXSIZE);
        command[nb_byte - 1] = '\0'; //shows the end of the string.

        pid_t pid = fork();

        if (pid == 0) { //child
            execlp(command, command, NULL);
            exit(EXIT_SUCCESS);
        }

        else if (pid > 0) { //father
            wait(&status);
            prompt();
        }

    }

}