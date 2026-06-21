#include <stdio.h>
#include <string.h>
#include "menu/menuDisplay.h"

/* Largura total da caixa (em "colunas" visuais, incluindo as bordas) */
#define LARGURA_CAIXA 42

/* Caracteres de borda dupla (Unicode box-drawing) */
#define CANTO_SUP_ESQ   "\u2554" /* ╔ */
#define CANTO_SUP_DIR   "\u2557" /* ╗ */
#define CANTO_INF_ESQ   "\u255A" /* ╚ */
#define CANTO_INF_DIR   "\u255D" /* ╝ */
#define MEIO_ESQ        "\u2560" /* ╠ */
#define MEIO_DIR        "\u2563" /* ╣ */
#define LINHA_HORIZ     "\u2550" /* ═ */
#define LINHA_VERT      "\u2551" /* ║ */

static void imprimirLinhaBorda(const char *esquerda, const char *direita) {
    printf("%s", esquerda);
    for (int i = 0; i < LARGURA_CAIXA - 2; i++) {
        printf("%s", LINHA_HORIZ);
    }
    printf("%s\n", direita);
}

static void imprimirLinhaTexto(const char *texto, int centralizado) {
    int espacoDisponivel = LARGURA_CAIXA - 4; /* 2 bordas + 1 espaço de respiro de cada lado */
    int tamanho = (int)strlen(texto);
    if (tamanho > espacoDisponivel) tamanho = espacoDisponivel;

    int espacosEsquerda = centralizado ? (espacoDisponivel - tamanho) / 2 : 0;
    int espacosDireita = espacoDisponivel - tamanho - espacosEsquerda;

    printf("%s ", LINHA_VERT);
    for (int i = 0; i < espacosEsquerda; i++) printf(" ");
    printf("%.*s", tamanho, texto);
    for (int i = 0; i < espacosDireita; i++) printf(" ");
    printf(" %s\n", LINHA_VERT);
}

void exibirCabecalho(const char *titulo) {
    imprimirLinhaBorda(CANTO_SUP_ESQ, CANTO_SUP_DIR);
    imprimirLinhaTexto(titulo, 1);
    imprimirLinhaBorda(CANTO_INF_ESQ, CANTO_INF_DIR);
}

void exibirMenuPrincipal(void) {
    imprimirLinhaBorda(CANTO_SUP_ESQ, CANTO_SUP_DIR);
    imprimirLinhaTexto("TASKVAULT", 1);
    imprimirLinhaBorda(MEIO_ESQ, MEIO_DIR);
    imprimirLinhaTexto("1 - Inserir tarefa", 0);
    imprimirLinhaTexto("2 - Remover tarefa", 0);
    imprimirLinhaTexto("3 - Listar tarefas", 0);
    imprimirLinhaTexto("0 - Sair", 0);
    imprimirLinhaBorda(CANTO_INF_ESQ, CANTO_INF_DIR);
    printf("\n>: ");
}
