#ifndef FILE_LOADER_H
#define FILE_LOADER_H

/*
 * Lê o conteúdo inteiro do arquivo apontado por 'path' e devolve em
 * uma string alocada dinamicamente (o chamador é responsável por
 * liberar com free()). Retorna NULL se o arquivo não puder ser aberto.
 */
char *loadFileContent(const char *path);

#endif /* FILE_LOADER_H */
