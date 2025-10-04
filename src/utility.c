#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void write(char string[]) {
    for (int i = 0; string[i]; i++) {
        printf("%c", string[i]);
        fflush(stdout);
        Sleep(MS);
    }
}


void introduceWorld() {
    write("Welcome to Elarion.\n");
    write("You have found yourself in a world unknown.\n");
    write("Everything you were is lost. You must start anew.\n\n");
}


void drawDiceSix(int number) {
    char xxxxxxxxx[] = "+-------+\n";
    char x_______x[] = "|       |\n";
    char x_o_____x[] = "| o     |\n";
    char x___o___x[] = "|   o   |\n";
    char x_____o_x[] = "|     o |\n";
    char x_o___o_x[] = "| o   o |\n";

    switch (number) {
        case 1:
            printf(xxxxxxxxx); printf(x_______x);
            printf(x___o___x); printf(x_______x);
            printf(xxxxxxxxx); break;
        case 2:
            printf(xxxxxxxxx); printf(x_o_____x);
            printf(x_______x); printf(x_____o_x);
            printf(xxxxxxxxx); break;
        case 3:
            printf(xxxxxxxxx); printf(x_o_____x);
            printf(x___o___x); printf(x_____o_x);
            printf(xxxxxxxxx); break;
        case 4:
            printf(xxxxxxxxx); printf(x_o___o_x);
            printf(x_______x); printf(x_o___o_x);
            printf(xxxxxxxxx); break;
        case 5:
            printf(xxxxxxxxx); printf(x_o___o_x);
            printf(x___o___x); printf(x_o___o_x);
            printf(xxxxxxxxx); break;
        case 6:
            printf(xxxxxxxxx); printf(x_o___o_x);
            printf(x_o___o_x); printf(x_o___o_x);
            printf(xxxxxxxxx); break;
    }
}


void rollDiceSix() {
    int num = 1 + rand() % 6;
    drawDiceSix(num);
    printf("You rolled a %d!\n", num);
}
