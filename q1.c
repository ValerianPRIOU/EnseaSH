//
// Created by valeprio54 on 29/11/23.
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