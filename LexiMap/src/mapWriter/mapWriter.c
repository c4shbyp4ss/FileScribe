#include <stdio.h>
#include "mapWriter/mapWriter.h"

void writeWordMap(const char *path, Word list[], int total) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(file, "%s - %d\n", list[i].text, list[i].count);
    }

    fclose(file);
}
