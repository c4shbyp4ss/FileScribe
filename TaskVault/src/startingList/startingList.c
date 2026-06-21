#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "startingList/startingList.h"

void startingList(char array[][2][MAX_STR_LEN], int tma) {
    for (int i = 0; i < tma; i++) {
        memset(array[i][0], 0, MAX_STR_LEN);
        memset(array[i][1], 0, MAX_STR_LEN);
    }
}
