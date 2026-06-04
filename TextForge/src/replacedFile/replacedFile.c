#include <stdio.h>
#include <stdlib.h>
#include "../../include/FileReturn/fileReturn.h"
#include "../../include/wordReplacer/wordReplace.h"
#include "../../include/replacedFile/replacedFile.h"

void replacedFile(FILE *newFile, FILE *oldFile,
                  const char *oldWord, const char *newWord) {

    char line[1024];

    while (fgets(line, sizeof(line), oldFile) != NULL) {
        char *replaced = wordReplace(line, (char *)oldWord, (char *)newWord);
        if (replaced) {
            fprintf(newFile, "%s", replaced);
            free(replaced);
        } else {
            /* fallback: grava a linha original se a alocação falhar */
            fprintf(newFile, "%s", line);
        }
    }

    fclose(newFile);
    fclose(oldFile);
}
