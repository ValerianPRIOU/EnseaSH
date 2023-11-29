//
// Created by valeprio54 on 29/11/23.
//

#include "fonctions.h";



void endProg(){
    write(STDOUT_FILENO, exit, strlen(exit));
    exit(EXIT_SUCCESS);
}


void execut(char commande[MAXSIZE]){
    execlp(commande,commande, NULL);
    exit(EXIT_FAILURE);
}






void q3() {
    int nbChar;
    int status;
    char commande[MAXSIZE];
    bienvenue();



    while(1){
        nbChar = read(STDIN_FILENO, commande, MAXSIZE);
        commande[nbChar-1] = '\0';

        if(strcmp(commande, "exit")==0 || strcmp(commande,"")==0){
            endProg();
        }

        pid_t ret= fork();
        if (ret==0){
            execut(commande);
        }
        else {
            wait(&status);
            prompt();
        }
    }
}

