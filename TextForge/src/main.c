#include <stdio.h>
#include <string.h>

#include "../include/FileReturn/fileReturn.h"
#include "../include/replacedFile/replacedFile.h"
#include "../include/menus/menus.h"
#include "../include/operationalFunctions/operationalFunctions.h"

#define PATH_SIZE 512
#define WORD_SIZE 256

int main(void) {

    char inputPath[PATH_SIZE];
    char outputPath[PATH_SIZE];
    char oldWord[WORD_SIZE];
    char newWord[WORD_SIZE];

    /* ── Tela 1: Boas-vindas ──────────────────────────────────────────── */
    menuWelcome();

    /* ── Tela 2: Coletar caminhos dos arquivos ────────────────────────── */
    menuSetFiles(inputPath, PATH_SIZE, outputPath, PATH_SIZE);

    /* ── Tela 3a: Coletar termos da substituição ──────────────────────── */
    menuSetReplacement(oldWord, WORD_SIZE, newWord, WORD_SIZE);

    /* ── Tela 3b: Confirmação — loop até S ou N válido ────────────────── */
    int confirmed = menuConfirmReplacement(oldWord, newWord);
    if (!confirmed) {
        menuError("Operacao cancelada pelo usuario.");
        return 0;
    }

    /* ── Tela 4: Processando ──────────────────────────────────────────── */
    menuProcessing();

    /* ── Backend: abrir arquivos ──────────────────────────────────────── */
    FILE *fileIn  = fileReturn(inputPath,  "r");
    FILE *fileOut = fileReturn(outputPath, "w");

    if (!fileIn) {
        menuError("Nao foi possivel abrir o arquivo de entrada.");
        return 1;
    }
    if (!fileOut) {
        fclose(fileIn);
        menuError("Nao foi possivel criar o arquivo de saida.");
        return 1;
    }

    /* ── Backend: realizar substituição e gravar novo arquivo ────────── */
    replacedFile(fileOut, fileIn, oldWord, newWord);

    /* ── Tela 5: Sucesso ─────────────────────────────────────────────── */
    menuSuccess(outputPath);

    /* ── Tela 6: Encerramento ────────────────────────────────────────── */
    menuGoodbye();

    return 0;
}
