#include <stdio.h>
#include "menu/menu.h"
#include "menu/menuDisplay.h"
#include "menu/menuActions.h"
#include "operational/operational.h"

void runMenu(void) {
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
                acaoDividir();
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
