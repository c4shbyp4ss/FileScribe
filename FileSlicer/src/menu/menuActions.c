#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu/menuActions.h"
#include "menu/menuDisplay.h"
#include "slicer/slicer.h"
#include "operational/operational.h"
#include "config/config.h"

void acaoDividir(void) {
    char input_path[MAX_PATH_LEN];
    char lines_str[64];
    int lines_per_part;

    cleanScreen();
    exibirCabecalho("DIVIDIR ARQUIVO");

    printf("\nCaminho do arquivo de entrada: ");
    fgets(input_path, sizeof(input_path), stdin);
    input_path[strcspn(input_path, "\n")] = '\0';

    printf("Linhas por parte: ");
    fgets(lines_str, sizeof(lines_str), stdin);
    lines_per_part = atoi(lines_str);

    if (lines_per_part <= 0) {
        exibirErro("Numero de linhas invalido.");
        screenWait();
        return;
    }

    exibirInfo("Processando...");

    int result = sliceFile(input_path, lines_per_part, DIR_OUTPUT);

    if (result == 0) {
        char msg[256];
        snprintf(msg, sizeof(msg), "Arquivo dividido com sucesso! Resultado em: %s", DIR_OUTPUT);
        exibirSucesso(msg);
    } else {
        exibirErro("Falha ao processar. Verifique o caminho do arquivo.");
    }

    screenWait();
}
