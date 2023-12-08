//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void q5() {

    struct timespec start;
    struct timespec end;
    double duration;

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

        clock_gettime(CLOCK_MONOTONIC, &start);

        pid_t pid = fork();

        if (pid == 0) {
            execute(command);
        }

        else if (pid > 0) {

            wait(&status);

            clock_gettime(CLOCK_MONOTONIC, &end);
            duration = (end.tv_sec - start.tv_sec)/1e3 + (end.tv_nsec - start.tv_nsec)/1e6; // computes the duration the program took to run, in ms.

            if(WIFEXITED(status)){
                sprintf(command, PROMPT_EXIT_TIME, WIFEXITED(status),duration);
            }

            else if (WIFSIGNALED(status)){
                sprintf(command, PROMPT_SIGN_TIME, WTERMSIG(status),duration);
            }

            print(command);
        }

    }

}