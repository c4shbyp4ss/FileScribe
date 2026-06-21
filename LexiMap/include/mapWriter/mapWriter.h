#ifndef MAP_WRITER_H
#define MAP_WRITER_H

#include "config/word.h"

/* Escreve cada palavra e sua contagem em 'path', uma por linha. */
void writeWordMap(const char *path, Word list[], int total);

#endif /* MAP_WRITER_H */
