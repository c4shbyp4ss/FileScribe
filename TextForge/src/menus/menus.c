#include <stdio.h>
#include <string.h>
#include "../../include/menus/menus.h"
#include "../../include/operationalFunctions/operationalFunctions.h"

/* ── Largura interna da caixa (quantidade de ═ entre as bordas ║) ─────────
   Total visível na tela: BOX_W + 2 caracteres de borda lateral.
   Valor 48 → linha total de 50 colunas.                                    */
#define BOX_W 48

/* ════════════════════════════════════════════════════════════════════════════
   TELA 1 — BOAS-VINDAS
   ════════════════════════════════════════════════════════════════════════════ */
void menuWelcome(void) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("TEXTFORGE", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Bem-vindo ao TextForge!", BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Ferramenta de substituicao de texto", BOX_W);
    drawRow("via terminal.", BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Pressione ENTER para iniciar...");
    getchar();
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 2 — DEFINIR ARQUIVOS
   ════════════════════════════════════════════════════════════════════════════ */
void menuSetFiles(char *inputPath,  int inputSize,
                  char *outputPath, int outputSize) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("DEFINIR ARQUIVOS", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("O arquivo original NAO sera modificado.", BOX_W);
    drawRow("Um novo arquivo sera gerado com o resultado.", BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Arquivo de entrada (caminho completo):\n  > ");
    fgets(inputPath, inputSize, stdin);
    stripNewline(inputPath);

    printf("\n  Nome do arquivo de saida:\n  > ");
    fgets(outputPath, outputSize, stdin);
    stripNewline(outputPath);
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 3a — DEFINIR SUBSTITUICAO
   ════════════════════════════════════════════════════════════════════════════ */
void menuSetReplacement(char *oldWord, int oldSize,
                        char *newWord, int newSize) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("SUBSTITUICAO DE TEXTO", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Defina o trecho a ser substituido", BOX_W);
    drawRow("e o novo conteudo que ira no lugar.", BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Texto/palavra que sera procurada:\n  > ");
    fgets(oldWord, oldSize, stdin);
    stripNewline(oldWord);

    printf("\n  Texto/palavra que ira substituir:\n  > ");
    fgets(newWord, newSize, stdin);
    stripNewline(newWord);
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 3b — CONFIRMACAO
   ════════════════════════════════════════════════════════════════════════════ */
int menuConfirmReplacement(const char *oldWord, const char *newWord) {
    char confirm[8];

    /* Monta as linhas com aspas para exibir dentro da caixa */
    char oldLine[BOX_W + 1];
    char newLine[BOX_W + 1];
    snprintf(oldLine, sizeof(oldLine), "\"%s\"", oldWord);
    snprintf(newLine, sizeof(newLine), "\"%s\"", newWord);

    clearScreen();

    drawTop(BOX_W);
    drawRow("CONFIRMACAO", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Substituir:", BOX_W);
    drawRow(oldLine, BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Por:", BOX_W);
    drawRow(newLine, BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Confirmar? (S/N): ");
    fgets(confirm, sizeof(confirm), stdin);
    stripNewline(confirm);

    return (confirm[0] == 'S' || confirm[0] == 's');
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 4 — PROCESSANDO
   ════════════════════════════════════════════════════════════════════════════ */
void menuProcessing(void) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("PROCESSANDO", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Lendo arquivo...", BOX_W);
    drawRow("Aplicando substituicoes...", BOX_W);
    drawRow("Gerando novo arquivo...", BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    /* O backend é chamado logo após esta tela no main.c */
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 5 — SUCESSO
   ════════════════════════════════════════════════════════════════════════════ */
void menuSuccess(const char *outputPath) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("CONCLUIDO", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Arquivo gerado com sucesso:", BOX_W);
    drawRow(outputPath, BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Pressione ENTER para continuar...");
    getchar();
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA 6 — ENCERRAMENTO
   ════════════════════════════════════════════════════════════════════════════ */
void menuGoodbye(void) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("TEXTFORGE", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Operacao finalizada com sucesso.", BOX_W);
    drawEmptyRow(BOX_W);
    drawRow("Obrigado por utilizar o TextForge!", BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Pressione ENTER para sair...");
    getchar();
}

/* ════════════════════════════════════════════════════════════════════════════
   TELA DE ERRO
   ════════════════════════════════════════════════════════════════════════════ */
void menuError(const char *message) {
    clearScreen();

    drawTop(BOX_W);
    drawRow("ERRO", BOX_W);
    drawSeparator(BOX_W);
    drawEmptyRow(BOX_W);
    drawRow(message, BOX_W);
    drawEmptyRow(BOX_W);
    drawBottom(BOX_W);

    printf("\n  Pressione ENTER para sair...");
    getchar();
}
