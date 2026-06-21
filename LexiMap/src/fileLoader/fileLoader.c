#include <stdio.h>
#include <stdlib.h>
#include "fileLoader/fileLoader.h"

char *loadFileContent(const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *) malloc(size + 1);
    if (content == NULL) {
        fclose(file);
        return NULL;
    }

    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}
