#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "config/config.h"

/* Salva o conteúdo do array de tarefas no arquivo indicado por path. */
void salvarLista(const char *path, char array[][2][MAX_STR_LEN], int tma);

/* Carrega o conteúdo do arquivo indicado por path para o array de tarefas. */
void carregarLista(const char *path, char array[][2][MAX_STR_LEN], int tma);

#endif
