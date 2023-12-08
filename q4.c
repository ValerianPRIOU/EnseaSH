//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void q4() {

    char command[MAXSIZE];
    int nb_byte;
    int status;

    bienvenue();
    prompt();

    while (1) {

        nb_byte = read(STDIN_FILENO, command, MAXSIZE);
        command[nb_byte - 1] = '\0';

        if(strcmp(command, "exit") == 0 || strcmp(command, "") == 0){
            endProg();
        }

        pid_t pid = fork();

        if (pid == 0) {
            execute(command);
        }

        else if (pid > 0) {

            wait(&status);

            if(WIFEXITED(status)){
                sprintf(command, PROMPT_EXIT, WIFEXITED(status)); //normal way to exit the program
            }

            else if (WIFSIGNALED(status)){
                sprintf(command, PROMPT_SIGN, WTERMSIG(status)); //something wrong happened
            }

            print(command);
        }

    }

}