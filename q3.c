//
// Created by valeprio54 on 29/11/23.
//

#include "fonctions.h"

void endProg(){
    write(STDOUT_FILENO, msg_exit, strlen(msg_exit));
    exit(EXIT_SUCCESS);
}

void execute(char commande[MAXSIZE]){
    execlp(commande,commande, NULL);
    exit(EXIT_SUCCESS);
}

void q3() {
    int nbChar;
    int status;
    char command[MAXSIZE];

    bienvenue();
    prompt();


    while(1){
        nbChar = read(STDIN_FILENO, command, MAXSIZE);
        command[nbChar-1] = '\0';

        if(strcmp(command, "exit")==0 || strcmp(command,"")==0){
            endProg();
        }

        pid_t pid= fork();
        if (pid == 0){ // child code
            execute(command);
        }
        else if (pid > 0){
            wait(&status);
            prompt();
        }
    }
}

