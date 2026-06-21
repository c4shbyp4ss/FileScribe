#ifndef ADDTOLIST_H
#define ADDTOLIST_H

#include "config/config.h"

/*
 * Adiciona uma nova tarefa na primeira posição livre do array.
 *
 * Retorna 0 em caso de sucesso, ou -1 se a lista já estiver cheia.
 */
int addToList(char array[][2][MAX_STR_LEN], int tma, const char *categoria, const char *tarefa);

#endif
