#include <stdio.h>
#include "menu/menu.h"
#include "menu/menuDisplay.h"
#include "menu/menuActions.h"
#include "operational/operational.h"

void runMenu(void) {
    /*
     * 'opcao' é int (não char) de propósito: getchar() retorna um int,
     * e compará-lo com EOF como char é um bug clássico em C — em
     * plataformas onde char é unsigned a comparação nunca é verdadeira
     * e o programa entra em loop infinito quando o stdin fecha (Ctrl+D).
     */
    int opcao;

    do {
        cleanScreen();
        exibirMenuPrincipal();

        opcao = getchar();

        if (opcao == EOF) {
            printf("\nSaindo...\n");
            break;
        }

        cleanBuffer();

        switch (opcao) {
            case '1':
                acaoMapear();
                break;

            case '2':
                acaoVerUltimoMapa();
                break;

            case '0':
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                screenWait();
                break;
        }

    } while (opcao != '0');
}
