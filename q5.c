//
// Created by valeprio54 on 06/12/23.
//

#include "fonctions.h"

struct timespec start;
struct timespec end;
double duration; //time est déjà pris

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

        clock_gettime(CLOCK_MONOTONIC, &start);

        pid_t pid = fork();
        if (pid == 0) { // child code

            execute(command);

        } else if (pid > 0) {

            wait(&status);

            clock_gettime(CLOCK_MONOTONIC, &end);
            duration = (end.tv_sec - start.tv_sec)/1e3 + (end.tv_nsec - start.tv_nsec)/1e6;

            if (WIFEXITED(status)) {
                sprintf(command,PROMPT_EXIT_TIME, WIFEXITED(status),duration);
                //write(STDOUT_FILENO, PROMPT_EXIT, sizeof(PROMPT_EXIT) - 1);
                //printf(PROMPT_EXIT,status);
            }

            else if (WIFSIGNALED(status)) {
                sprintf(command,PROMPT_SIGN_TIME, WTERMSIG(status),duration);
                //write(STDOUT_FILENO, PROMPT_SIGN, sizeof(PROMPT_SIGN) - 1);
                //printf(PROMPT_SIGN,status);
            }

            print(command);
        }
    }
}

