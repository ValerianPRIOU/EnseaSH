//
// Created by valeprio54 on 29/11/23.
//

#include "fonctions.h"

void lecture() {

    char buffer[256];
    int nb_octet = read(STDIN_FILENO, buffer, 64); //nb_octet récupère le nombre d'octets réellement lus par read().
    char *cmd = malloc(nb_octet - 1);//malloc alloue dynamiquement de la mémoire, dans ce cas pour la création d'un tableau assez grand pour contenir ce qui est tappé en entrée
    strncpy(cmd,buffer,(nb_octet - 1));//Ici, on copie ce qui a été tappé en entrée dans le tableau de caractères cmd.
    execlp("ls","ls",NULL);

}