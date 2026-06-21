#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addToList/addToList.h"

int addToList(char array[][2][MAX_STR_LEN], int tma, const char *categoria, const char *tarefa) {
    for (int i = 0; i < tma; i++) {
        if (array[i][0][0] == '\0') {
            strncpy(array[i][0], categoria, MAX_STR_LEN - 1);
            strncpy(array[i][1], tarefa, MAX_STR_LEN - 1);
            array[i][0][MAX_STR_LEN - 1] = '\0';
            array[i][1][MAX_STR_LEN - 1] = '\0';
            return 0;
        }
    }
    return -1; /* lista cheia */
}
