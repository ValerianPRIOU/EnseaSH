//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void q3() {

    char command[MAXSIZE];
    int nb_byte;
    int status;

    bienvenue();
    prompt();

    while (1) {

        nb_byte = read(STDIN_FILENO, command, MAXSIZE);
        command[nb_byte - 1] = '\0';

        if(strcmp(command, "exit") == 0 || strcmp(command, "") == 0){
            endProg(); //ends the program if the user inputs "exit" or nothing.
        }

        pid_t pid = fork();

        if (pid == 0) {
            execute(command);
        }

        else if (pid > 0) {
            wait(&status);
            prompt();
        }

    }

}