#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/operationalFunctions/operationalFunctions.h"

/* ── Largura interna da caixa (sem contar as bordas ║) ───────────────────── */
/* A largura total visível = BOX_INNER + 2 (para os dois ║)                  */

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void stripNewline(char *str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ── Helpers de desenho de caixa ─────────────────────────────────────────── */

/*
 * Os caracteres Unicode de borda dupla em UTF-8:
 *   ╔  = \xE2\x95\x94    ╗  = \xE2\x95\x97
 *   ╚  = \xE2\x95\x9A    ╝  = \xE2\x95\x9D
 *   ╠  = \xE2\x95\xA0    ╣  = \xE2\x95\xA3
 *   ═  = \xE2\x95\x90    ║  = \xE2\x95\x91
 *
 * width = número de caracteres ═ entre as bordas verticais
 */

static void printHorizontalLine(int width) {
    for (int i = 0; i < width; i++) {
        printf("\xE2\x95\x90"); /* ═ */
    }
}

void drawTop(int width) {
    printf("\xE2\x95\x94"); /* ╔ */
    printHorizontalLine(width);
    printf("\xE2\x95\x97\n"); /* ╗ */
}

void drawSeparator(int width) {
    printf("\xE2\x95\xA0"); /* ╠ */
    printHorizontalLine(width);
    printf("\xE2\x95\xA3\n"); /* ╣ */
}

void drawBottom(int width) {
    printf("\xE2\x95\x9A"); /* ╚ */
    printHorizontalLine(width);
    printf("\xE2\x95\x9D\n"); /* ╝ */
}

void drawEmptyRow(int width) {
    printf("\xE2\x95\x91"); /* ║ */
    for (int i = 0; i < width; i++) printf(" ");
    printf("\xE2\x95\x91\n"); /* ║ */
}

/*
 * Imprime texto centralizado dentro das bordas.
 * Se o texto for maior que width, ele é truncado.
 */
void drawRow(const char *text, int width) {
    int textLen = (int)strlen(text);
    if (textLen > width) textLen = width;

    int totalPad = width - textLen;
    int padLeft  = totalPad / 2;
    int padRight = totalPad - padLeft;

    printf("\xE2\x95\x91"); /* ║ */
    for (int i = 0; i < padLeft;  i++) printf(" ");
    printf("%.*s", textLen, text);
    for (int i = 0; i < padRight; i++) printf(" ");
    printf("\xE2\x95\x91\n"); /* ║ */
}

void printCentered(const char *text, int width) {
    drawRow(text, width);
}
