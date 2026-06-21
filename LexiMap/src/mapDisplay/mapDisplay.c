#include <stdio.h>
#include "mapDisplay/mapDisplay.h"

void displayWordMap(FILE *file) {
    char line[256];
    int index = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%3d) %s", index, line);
        index++;
    }
}
