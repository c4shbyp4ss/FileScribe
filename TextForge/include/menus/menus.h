#ifndef MENUS_H
#define MENUS_H

/* ── Tela 1: Boas-vindas ─────────────────────────────────────────────────── */
void menuWelcome(void);

/* ── Tela 2: Definir arquivos ────────────────────────────────────────────── */
/* Preenche inputPath e outputPath com os caminhos fornecidos pelo usuário.  */
void menuSetFiles(char *inputPath, int inputSize,
                  char *outputPath, int outputSize);

/* ── Tela 3a: Definir substituição ──────────────────────────────────────── */
/* Preenche oldWord e newWord com os termos fornecidos pelo usuário.         */
void menuSetReplacement(char *oldWord, int oldSize,
                        char *newWord, int newSize);

/* ── Tela 3b: Confirmação da substituição ───────────────────────────────── */
/* Retorna 1 se o usuário confirmou, 0 se cancelou.                         */
int menuConfirmReplacement(const char *oldWord, const char *newWord);

/* ── Tela 4: Processando ─────────────────────────────────────────────────── */
void menuProcessing(void);

/* ── Tela 5: Sucesso ─────────────────────────────────────────────────────── */
void menuSuccess(const char *outputPath);

/* ── Tela 6: Encerramento ────────────────────────────────────────────────── */
void menuGoodbye(void);

/* ── Tela de erro genérico ───────────────────────────────────────────────── */
void menuError(const char *message);

#endif /* MENUS_H */
