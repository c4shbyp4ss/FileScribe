#include <stdio.h>
#include <string.h>
#include "menu/menuActions.h"
#include "menu/menuDisplay.h"
#include "addToList/addToList.h"
#include "removingItems/removingItems.h"
#include "listingItems/listingItems.h"
#include "persistence/persistence.h"
#include "operational/operational.h"

void acaoInserir(char listaTarefas[][2][MAX_STR_LEN]) {
    char categoriaTarefa[MAX_STR_LEN];
    char nomeTarefa[MAX_STR_LEN];

    cleanScreen();
    exibirCabecalho("INSERIR TAREFA");

    printf("\nNome da categoria: ");
    fgets(categoriaTarefa, sizeof(categoriaTarefa), stdin);
    categoriaTarefa[strcspn(categoriaTarefa, "\n")] = '\0';

    printf("Nome da tarefa: ");
    fgets(nomeTarefa, sizeof(nomeTarefa), stdin);
    nomeTarefa[strcspn(nomeTarefa, "\n")] = '\0';

    if (addToList(listaTarefas, SIZE_LIST, categoriaTarefa, nomeTarefa) == 0) {
        salvarLista(DIR_FILE, listaTarefas, SIZE_LIST);
        printf("\nTarefa adicionada com sucesso!\n");
    } else {
        printf("\nLista cheia! Não foi possível adicionar a tarefa.\n");
    }

    screenWait();
}

void acaoRemover(char listaTarefas[][2][MAX_STR_LEN]) {
    cleanScreen();
    exibirCabecalho("REMOVER TAREFA");

    FILE *temp = fopen(DIR_FILE, "r");
    if (!temp) {
        printf("\nNenhuma tarefa encontrada.\n");
        screenWait();
        return;
    }

    printf("\n");
    listingItems(temp);
    fclose(temp);

    int indice = 0;
    printf("\nSelecione o índice para remover\n>: ");
    if (scanf("%d", &indice) != 1) {
        cleanBuffer();
        printf("\nEntrada inválida.\n");
        screenWait();
        return;
    }
    cleanBuffer();

    if (removingItems(listaTarefas, SIZE_LIST, indice - 1) == 0) {
        salvarLista(DIR_FILE, listaTarefas, SIZE_LIST);
        printf("\nTarefa removida!\n");
    } else {
        printf("\nÍndice inválido.\n");
    }

    screenWait();
}

void acaoListar(void) {
    cleanScreen();
    exibirCabecalho("LISTA DE TAREFAS");

    FILE *temp = fopen(DIR_FILE, "r");
    if (!temp) {
        printf("\nNenhuma tarefa encontrada.\n");
        screenWait();
        return;
    }

    printf("\n");
    listingItems(temp);
    fclose(temp);

    screenWait();
}
