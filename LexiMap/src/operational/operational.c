#include <stdio.h>
#include <stdlib.h>
#include "operational/operational.h"

void cleanScreen(void) {
    system("clear");
}

void cleanBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void screenWait(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}
