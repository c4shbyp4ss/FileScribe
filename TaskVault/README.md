# TaskVault

Gerenciador de tarefas em C, com persistência simples em arquivo texto e
menu de terminal com moldura de borda dupla.

## Estrutura do projeto

```
TaskVault/
├── Makefile
├── data/
│   └── teste.txt          # gerado em tempo de execução (não versionado)
├── include/
│   ├── config/             # constantes globais (SIZE_LIST, DIR_FILE, MAX_STR_LEN)
│   ├── menu/                # tudo relacionado ao menu
│   │   ├── menu.h            # ponto de entrada: runMenu()
│   │   ├── menuDisplay.h     # desenho da moldura de borda dupla
│   │   └── menuActions.h     # handlers de inserir/remover/listar
│   ├── persistence/         # salvar/carregar a lista em disco
│   ├── addToList/
│   ├── removingItems/
│   ├── listingItems/
│   ├── startingList/
│   └── operational/         # cleanScreen / cleanBuffer / screenWait
└── src/
    ├── main.c                # ponto de entrada do programa — só chama runMenu()
    └── (espelha as pastas de include/, com a implementação .c de cada módulo)
```

`src/main.c` contém **apenas** a função `main()`. Toda a lógica (menu,
inserir, remover, listar, salvar/carregar) foi modularizada em
`menu/`, `persistence/` e nos módulos de domínio existentes.

## Compilar e rodar

```bash
make        # compila tudo para ./taskvault
make run    # compila (se necessário) e executa
make clean  # remove build/ e o binário
```

## Bugs corrigidos nesta revisão

- **Loop infinito em EOF**: a opção do menu era lida como `char` e comparada
  com `EOF`; em plataformas onde `char` é unsigned essa comparação nunca é
  verdadeira. Agora é lida como `int`.
- **Variável não inicializada**: se o usuário digitasse um índice não
  numérico na remoção, a variável ficava com lixo de memória. Agora o
  retorno do `scanf` é validado.
- **Falhas silenciosas**: `addToList` e `removingItems` agora retornam um
  código de erro (lista cheia / índice inválido), e o menu exibe a
  mensagem correspondente ao usuário.
- **Constantes duplicadas**: `SIZE_LIST`, `DIR_FILE` e o tamanho dos campos
  (100) viviam espalhados em vários arquivos. Agora centralizados em
  `include/config/config.h`.
- **Includes relativos frágeis** (`../../include/...`): substituídos por
  includes baseados no diretório `include/` (via `-Iinclude` no Makefile),
  resistentes a mudanças de localização dos arquivos.
- **Binários commitados** (`a.out`, `main`): removidos; `.gitignore`
  adicionado para evitar que voltem.
