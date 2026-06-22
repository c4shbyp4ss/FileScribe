#ifndef CONFIG_H
#define CONFIG_H

/*
 * Configurações globais do FileSlicer.
 * Centralizar essas constantes aqui evita que arquivos diferentes
 * fiquem com valores "fora de sincronia" no futuro.
 */

/* Caminho do diretório onde as partes divididas são salvas */
#define DIR_OUTPUT    "./data/parts/"

/* Tamanho máximo de um caminho de arquivo digitado pelo usuário */
#define MAX_PATH_LEN  256

/* Tamanho máximo de uma linha lida do arquivo de entrada */
#define MAX_LINE_LEN  4096

#endif /* CONFIG_H */
