//
// Created by valeprio54 on 29/11/23.
//

#include "fonctions.h"

void bienvenue(){

    char buffer[] = "\nBienvenue dans le Shell ENSEA. \nPour quitter, tappez 'exit'. \n";
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);

}

void prompt(){

    char buffer[] = "enseash %\n";
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);

}