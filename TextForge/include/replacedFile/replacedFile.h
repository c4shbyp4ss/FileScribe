#ifndef REPLACED_FILE_H
#define REPLACED_FILE_H

#include <stdio.h>

/*
 * Lê oldFile linha a linha, substitui todas as ocorrências de oldWord
 * por newWord e grava o resultado em newFile.
 * Ambos os arquivos são fechados ao final.
 */
void replacedFile(FILE *newFile, FILE *oldFile,
                  const char *oldWord, const char *newWord);

#endif /* REPLACED_FILE_H */
