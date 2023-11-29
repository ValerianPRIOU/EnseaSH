#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void bienvenue(){
    char buffer[] = "\nBienvenue dans le Shell ENSEA. \nPour quitter, tappez 'exit'. \nenseash %\n";
    write(STDOUT_FILENO, buffer, sizeof(buffer) - 1);
}

int main() {

    bienvenue();

    return 0;

}
