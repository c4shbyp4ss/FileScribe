#include <stdio.h>
#include <string.h>
#include "persistence/persistence.h"

void salvarLista(const char *path, char array[][2][MAX_STR_LEN], int tma) {
    FILE *file = fopen(path, "w");
    if (!file) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    for (int i = 0; i < tma; i++) {
        if (array[i][0][0] == '\0') continue;
        fprintf(file, "====================\n");
        fprintf(file, "Categoria: %s | Tarefa: %s\n", array[i][0], array[i][1]);
    }

    fclose(file);
}

void carregarLista(const char *path, char array[][2][MAX_STR_LEN], int tma) {
    FILE *file = fopen(path, "r");
    if (!file) return; /* arquivo ainda não existe, tudo bem */

    int i = 0;
    char linha[256];

    while (i < tma && fgets(linha, sizeof(linha), file)) {
        if (strncmp(linha, "====", 4) == 0) continue;

        /* Atenção: o "99" abaixo deve acompanhar MAX_STR_LEN - 1 do config.h */
        int campos = sscanf(linha, "Categoria: %99[^|] | Tarefa: %99[^\n]",
                             array[i][0], array[i][1]);

        if (campos != 2) continue; /* linha corrompida/inesperada: ignora com segurança */

        /* remove espaço(s) trailing da categoria (capturado pelo [^|]) */
        char *fim = array[i][0] + strlen(array[i][0]) - 1;
        while (fim > array[i][0] && *fim == ' ') *fim-- = '\0';

        i++;
    }

    fclose(file);
}
