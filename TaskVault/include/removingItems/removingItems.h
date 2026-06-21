#ifndef REMOVINGITEMS_H
#define REMOVINGITEMS_H

#include "config/config.h"

/*
 * Remove (limpa) a tarefa no índice informado.
 *
 * Retorna 0 em caso de sucesso, ou -1 se o índice for inválido
 * (fora dos limites) ou já estiver vazio.
 */
int removingItems(char array[][2][MAX_STR_LEN], int tma, int indice);

#endif
