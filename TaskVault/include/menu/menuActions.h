#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

#include "config/config.h"

/* Trata a opção "Inserir": pede categoria/tarefa e adiciona na lista. */
void acaoInserir(char listaTarefas[][2][MAX_STR_LEN]);

/* Trata a opção "Remover": lista os itens, pede um índice e remove. */
void acaoRemover(char listaTarefas[][2][MAX_STR_LEN]);

/* Trata a opção "Listar": exibe as tarefas cadastradas. */
void acaoListar(void);

#endif
