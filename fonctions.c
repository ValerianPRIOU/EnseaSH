//
// Created by uplink on 08/12/23.
//

#include "fonctions.h"

void bienvenue(){
    char buffer[] = msg_welcome;
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
}

void prompt(){
    char buffer[] = msg_prompt;
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
}

void endProg(){
    char buffer[] = msg_exit;
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
    exit(EXIT_SUCCESS);
}

void execute(char command[MAXSIZE]){
    execlp(command,command,NULL);
    exit(EXIT_SUCCESS);
}

void print(char *string){

    if(write(STDOUT_FILENO, string, strlen(string)) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

}