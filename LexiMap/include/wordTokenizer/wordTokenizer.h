#ifndef WORD_TOKENIZER_H
#define WORD_TOKENIZER_H

#include "config/word.h"

/*
 * Quebra 'text' em palavras (strtok) e preenche 'list' com cada palavra
 * única e sua respectiva contagem. Retorna o total de palavras únicas
 * encontradas. ATENÇÃO: 'text' é modificado pelo strtok.
 */
int tokenizeAndCount(char *text, Word list[]);

#endif /* WORD_TOKENIZER_H */
