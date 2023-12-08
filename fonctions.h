//
// Created by uplink on 08/12/23.
//

#ifndef ENSEASH_FONCTIONS_H
#define ENSEASH_FONCTIONS_H

#endif //ENSEASH_FONCTIONS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <bits/time.h>
#include <fcntl.h>

#define MAXSIZE 1024

#define msg_welcome "\nBievenue dans le Shell ENSEA. \nPour quitter, tappez 'exit'. \n"
#define msg_prompt "enseash % "
#define msg_exit "Bye bye ...\n"

#define PROMPT_EXIT "enseash [exit:%d] %% "
#define PROMPT_SIGN "enseash [sign:%d] %% "

#define PROMPT_EXIT_TIME "enseash [exit:%d|%.2fms] %% "
#define PROMPT_SIGN_TIME "enseash [sign:%d|%.2fms] %% "

void bienvenue();
void prompt();
void endProg();
void execute(char command[MAXSIZE]);
void print(char *string);

void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();