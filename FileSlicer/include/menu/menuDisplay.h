#ifndef MENU_DISPLAY_H
#define MENU_DISPLAY_H

/* Imprime o menu principal dentro de uma moldura de borda dupla (╔═╗║╚╝). */
void exibirMenuPrincipal(void);

/* Imprime um cabeçalho com título centralizado dentro de uma moldura de borda dupla. */
void exibirCabecalho(const char *titulo);

/* Imprime uma mensagem de sucesso formatada. */
void exibirSucesso(const char *msg);

/* Imprime uma mensagem de erro formatada. */
void exibirErro(const char *msg);

/* Imprime uma mensagem informativa formatada. */
void exibirInfo(const char *msg);

#endif /* MENU_DISPLAY_H */
