#ifndef CONFIG_H
#define CONFIG_H

/*
 * Configurações globais do TaskVault.
 * Centralizar essas constantes aqui evita que arquivos diferentes
 * fiquem com valores "fora de sincronia" no futuro.
 */

/* Caminho do arquivo onde a lista de tarefas é persistida em disco */
#define DIR_FILE "./data/teste.txt"

/* Quantidade máxima de tarefas que a lista em memória pode armazenar */
#define SIZE_LIST 20

/* Tamanho máximo (em caracteres, incluindo o '\0') de cada campo (categoria/tarefa) */
#define MAX_STR_LEN 100

#endif /* CONFIG_H */
