#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listingItems/listingItems.h"

void listingItems(FILE *file) {
    char buffer[1024];
    int indice = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (!strcmp(buffer, "====================\n")) {
            continue;
        }
        printf("[%d] - %s", indice + 1, buffer);
        indice++;
    }
}
