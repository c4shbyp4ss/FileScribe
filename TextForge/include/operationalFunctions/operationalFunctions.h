#ifndef OPERATIONAL_FUNCTIONS_H
#define OPERATIONAL_FUNCTIONS_H

/* Limpa a tela do terminal (cross-platform) */
void clearScreen(void);

/* Remove o '\n' deixado pelo fgets no final da string */
void stripNewline(char *str);

/* Limpa o buffer de entrada do stdin */
void clearInputBuffer(void);

/* Centraliza um texto dentro de uma caixa de largura W */
void printCentered(const char *text, int width);

/* Desenha uma linha horizontal com bordas duplas (topo) */
void drawTop(int width);

/* Desenha uma linha horizontal com bordas duplas (meio / separador) */
void drawSeparator(int width);

/* Desenha uma linha horizontal com bordas duplas (rodapé) */
void drawBottom(int width);

/* Imprime uma linha vazia com bordas laterais */
void drawEmptyRow(int width);

/* Imprime uma linha de conteúdo centralizado dentro das bordas */
void drawRow(const char *text, int width);

#endif /* OPERATIONAL_FUNCTIONS_H */
