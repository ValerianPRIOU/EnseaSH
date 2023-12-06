//
// Created by valeprio54 on 29/11/23.
//

#ifndef ENSEASH_FONCTIONS_H
#define ENSEASH_FONCTIONS_H

#endif //ENSEASH_FONCTIONS_H

#define MAXSIZE 1024

#define msg_welcome "\nBienvenue dans le Shell ENSEA. \nPour quitter, tappez 'exit'. \n"
#define msg_prompt "enseash % "
#define msg_exit "Bye bye ...\n"

#define PROMPT_EXIT "enseash [exit:%d] %"
#define PROMPT_SIGN "enseash [sign:%d] %"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <bits/time.h>
#include <fcntl.h>

int eval(char *);
void bienvenue();
void prompt();
void endProg();
void execute();

void q1();
void q2();
void q3();
void q4();
void q5();