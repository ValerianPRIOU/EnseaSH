//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void q7() {

    int fdo_dm;

    struct timespec start;
    struct timespec end;
    double duration;

    char *args[MAXSIZE];
    int arg_count = 0;

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

            char *token = strtok(command, " \t\n");

            while(token != NULL){

                if(strcmp(token, "<") == 0){
                    token = strtok(NULL, " \t\n");
                    int fd_in = open(token, O_RDONLY);
                    dup2(fd_in, STDIN_FILENO);
                    close(fd_in);
                }

                else if(strcmp(token,">") == 0){
                    token = strtok(NULL, " \t\n");
                    int fd_out = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                    dup2(fd_out, STDOUT_FILENO);
                    close(fd_out);
                }

                else{
                    args[arg_count++] = token;
                }

                token = strtok(NULL, " \t\n");
            }

            args[arg_count] = NULL;

            execvp(args[0], args);

            exit(EXIT_SUCCESS);

        }

        else if (pid > 0) {

            wait(&status);

            clock_gettime(CLOCK_MONOTONIC, &end);
            duration = (end.tv_sec - start.tv_sec)/1e3 + (end.tv_nsec - start.tv_nsec)/1e6;

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