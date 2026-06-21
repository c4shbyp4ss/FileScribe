# LexiMap

Mapeador de frequência de palavras em C, com leitura de arquivo via
caminho informado pelo usuário e menu de terminal com moldura de
borda dupla.

## Estrutura do projeto

```
LexiMap/
├── Makefile
├── data/
│   ├── exemplo.txt        # arquivo de exemplo para testar a opção 1
│   └── wordmap.txt        # gerado em tempo de execução (resultado)
├── include/
│   ├── config/             # constantes globais + struct Word
│   │   ├── config.h
│   │   └── word.h
│   ├── menu/                # tudo relacionado ao menu
│   │   ├── menu.h            # ponto de entrada: runMenu()
│   │   ├── menuDisplay.h     # desenho da moldura de borda dupla
│   │   └── menuActions.h     # handlers de mapear/ver último mapa
│   ├── fileLoader/          # lê o arquivo de texto informado pelo usuário
│   ├── wordTokenizer/       # strtok + contagem de frequência
│   ├── alphabetSorter/      # ordenação alfabética
│   ├── mapWriter/           # fprintf do resultado em data/wordmap.txt
│   ├── mapDisplay/          # exibe o conteúdo do mapa salvo
│   └── operational/         # cleanScreen / cleanBuffer / screenWait
└── src/
    ├── main.c                # ponto de entrada do programa — só chama runMenu()
    └── (espelha as pastas de include/, com a implementação .c de cada módulo)
```

`src/main.c` contém **apenas** a função `main()`. Toda a lógica (menu,
leitura de arquivo, tokenização, ordenação, escrita e exibição do
resultado) foi modularizada em pastas próprias dentro de `src/` e
`include/`.

## Como funciona

1. **Mapear palavras de um arquivo**: o programa pede o caminho de um
   arquivo `.txt` (ex.: `data/exemplo.txt`), lê o conteúdo inteiro,
   tokeniza as palavras (`strtok`), conta a frequência de cada uma,
   ordena alfabeticamente e salva o resultado em `data/wordmap.txt`.
2. **Ver último mapeamento gerado**: exibe no terminal o conteúdo de
   `data/wordmap.txt`, caso já exista.

## Compilar e rodar

```bash
make        # compila tudo para ./leximap
make run    # compila (se necessário) e executa
make clean  # remove build/ e o binário
```

Ao rodar, escolha a opção `1` e informe `data/exemplo.txt` como
caminho para testar rapidamente.
