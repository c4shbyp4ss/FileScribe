#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "removingItems/removingItems.h"

int removingItems(char array[][2][MAX_STR_LEN], int tma, int indice) {
    if (indice < 0 || indice >= tma) return -1;
    if (array[indice][0][0] == '\0') return -1; /* já está vazio */

    memset(array[indice][0], 0, MAX_STR_LEN);
    memset(array[indice][1], 0, MAX_STR_LEN);
    return 0;
}
