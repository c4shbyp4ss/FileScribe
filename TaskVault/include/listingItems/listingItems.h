#ifndef LISTINGITEMS_H
#define LISTINGITEMS_H

#include <stdio.h>

/*
 * Lista o conteúdo de um arquivo já aberto, numerando cada tarefa
 * encontrada e ignorando as linhas separadoras ("====...").
 */
void listingItems(FILE *file);

#endif
