#ifndef WORD_H
#define WORD_H

#include "config/config.h"

typedef struct {
    char text[MAX_WORD_LEN];
    int count;
} Word;

#endif /* WORD_H */
