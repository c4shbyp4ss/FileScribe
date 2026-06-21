#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu/menuActions.h"
#include "menu/menuDisplay.h"
#include "fileLoader/fileLoader.h"
#include "wordTokenizer/wordTokenizer.h"
#include "alphabetSorter/alphabetSorter.h"
#include "mapWriter/mapWriter.h"
#include "mapDisplay/mapDisplay.h"
#include "operational/operational.h"
#include "config/config.h"
#include "config/word.h"

void acaoMapear(void) {
    char caminho[MAX_PATH_LEN];

    cleanScreen();
    exibirCabecalho("MAPEAR ARQUIVO");

    printf("\nCaminho do arquivo texto: ");
    fgets(caminho, sizeof(caminho), stdin);
    caminho[strcspn(caminho, "\n")] = '\0';

    char *conteudo = loadFileContent(caminho);
    if (conteudo == NULL) {
        printf("\nNao foi possivel abrir o arquivo informado.\n");
        screenWait();
        return;
    }

    static Word lista[MAX_WORDS];
    int total = tokenizeAndCount(conteudo, lista);

    sortWordsAlphabetically(lista, total);
    writeWordMap(DIR_OUTPUT, lista, total);

    printf("\n%d palavra(s) unica(s) encontrada(s).\n", total);
    printf("Resultado salvo em: %s\n", DIR_OUTPUT);

    free(conteudo);
    screenWait();
}

void acaoVerUltimoMapa(void) {
    cleanScreen();
    exibirCabecalho("ULTIMO MAPEAMENTO");

    FILE *arquivo = fopen(DIR_OUTPUT, "r");
    if (arquivo == NULL) {
        printf("\nNenhum mapeamento foi gerado ainda.\n");
        screenWait();
        return;
    }

    printf("\n");
    displayWordMap(arquivo);
    fclose(arquivo);

    screenWait();
}
