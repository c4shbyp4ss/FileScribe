#ifndef CONFIG_H
#define CONFIG_H

/*
 * Configurações globais do LexiMap.
 * Centralizar essas constantes aqui evita que arquivos diferentes
 * fiquem com valores "fora de sincronia" no futuro.
 */

/* Caminho do arquivo onde o mapa de palavras (resultado) é salvo */
#define DIR_OUTPUT "./data/wordmap.txt"

/* Quantidade máxima de palavras únicas que conseguimos mapear */
#define MAX_WORDS 1000

/* Tamanho máximo (em caracteres, incluindo o '\0') de cada palavra */
#define MAX_WORD_LEN 100

/* Tamanho máximo de um caminho de arquivo digitado pelo usuário */
#define MAX_PATH_LEN 256

#endif /* CONFIG_H */
