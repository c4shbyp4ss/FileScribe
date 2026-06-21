#include <stdio.h>
#include "menu/menu.h"
#include "menu/menuDisplay.h"
#include "menu/menuActions.h"
#include "startingList/startingList.h"
#include "persistence/persistence.h"
#include "operational/operational.h"
#include "config/config.h"

void runMenu(void) {
    char listaTarefas[SIZE_LIST][2][MAX_STR_LEN];

    startingList(listaTarefas, SIZE_LIST);
    carregarLista(DIR_FILE, listaTarefas, SIZE_LIST);

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
                acaoInserir(listaTarefas);
                break;

            case '2':
                acaoRemover(listaTarefas);
                break;

            case '3':
                acaoListar();
                break;

            case '0':
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
                screenWait();
                break;
        }

    } while (opcao != '0');
}
