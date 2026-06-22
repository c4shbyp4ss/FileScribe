# FileScribe
Uma coleção de pequenos projetos em C focados em **I/O de arquivos e manipulação de texto**.  
Cada projeto isola um conceito específico, tornando este repositório uma referência pessoal para aprender e revisitar o tratamento de arquivos em C.
---
## Projetos
| # | Nome | Descrição | Status |
|---|------|-----------|--------|
| 01 | [WordPulse](#01-wordpulse) | Contador de palavras, linhas e caracteres | ✅ Concluído |
| 02 | [TextForge](#02-textforge) | Busca e substituição em arquivos de texto | ✅ Concluído |
| 03 | [TaskVault](#03-taskvault) | Gerenciador de tarefas em arquivo | ✅ Concluído |
| 04 | [LexiMap](#04-leximap) | Indexador de frequência de palavras | ✅ Concluído |
| 05 | [FileSlicer](#05-fileslicer) | Divisor de arquivos por número de linhas | ✅ Concluído |
---
## 01. WordPulse
Lê um arquivo `.txt` e imprime o total de **palavras**, **linhas** e **caracteres**.  
Inspirado no comando Unix `wc`.

**Conceitos praticados:** `fopen`, `fgetc`, `fgets`, detecção de palavras por estado, contagem de caracteres UTF-8, tratamento de EOF.

```
╔═══════════════════════════╗
║   WordPulse > Resultado   ║
╠═══════════════════════════╣
║  Palavras:      00317     ║
║  Linhas:        00042     ║
║  Caracteres:    01842     ║
║  ───────────────────────  ║
╠═══════════════════════════╣
║       Digite enter...     ║
╚═══════════════════════════╝
```
---
## 02. TextForge
> ✅ Concluído

Lê um arquivo de origem, substitui todas as ocorrências de uma palavra por outra e salva o resultado em um novo arquivo.

**Conceitos praticados:** `strstr`, `fgets`, `fputs`, leitura e escrita em streams de arquivo separados.

```
╔════════════════════════════════════════════════╗
║                  CONFIRMACAO                   ║
╠════════════════════════════════════════════════╣
║                                                ║
║                  Substituir:                   ║
║                "Copa do Mundo"                 ║
║                                                ║
║                      Por:                      ║
║              "Copa Libertadores"               ║
║                                                ║
╚════════════════════════════════════════════════╝

  Confirmar? (S/N): S

╔════════════════════════════════════════════════╗
║                  PROCESSANDO                   ║
╠════════════════════════════════════════════════╣
║                                                ║
║                Lendo arquivo...                ║
║           Aplicando substituicoes...           ║
║            Gerando novo arquivo...             ║
║                                                ║
╚════════════════════════════════════════════════╝

╔════════════════════════════════════════════════╗
║                   CONCLUIDO                    ║
╠════════════════════════════════════════════════╣
║                                                ║
║          Arquivo gerado com sucesso:           ║
║                   output.txt                   ║
║                                                ║
╚════════════════════════════════════════════════╝
```

---
## 03. TaskVault
> ✅ Concluído

Um gerenciador de tarefas em CLI que persiste a lista em um arquivo `.txt`. Suporta inserir, remover por índice e listar tarefas, com um menu de terminal desenhado com moldura de borda dupla.

**Conceitos praticados:** modularização em múltiplos arquivos `.h`/`.c`, `fopen`/`fprintf`/`fgets` para persistência, parsing de linhas com `sscanf`, arrays multidimensionais de `char`, tratamento de erros (lista cheia, índice inválido, EOF), Makefile genérico.

```
╔════════════════════════════════════════╗
║               TASKVAULT                ║
╠════════════════════════════════════════╣
║ 1 - Inserir tarefa                     ║
║ 2 - Remover tarefa                     ║
║ 3 - Listar tarefas                     ║
║ 0 - Sair                               ║
╚════════════════════════════════════════╝

>: 3

╔════════════════════════════════════════╗
║            LISTA DE TAREFAS            ║
╚════════════════════════════════════════╝

[1] - Categoria: Trabalho | Tarefa: Fazer relatorio
[2] - Categoria: Casa | Tarefa: Lavar louca

Pressione ENTER para continuar...
```

```
╔════════════════════════════════════════╗
║             REMOVER TAREFA             ║
╚════════════════════════════════════════╝

[1] - Categoria: Trabalho | Tarefa: Fazer relatorio
[2] - Categoria: Casa | Tarefa: Lavar louca

Selecione o índice para remover
>: 1

Tarefa removida!
```

---
## 04. LexiMap
> ✅ Concluído

Lê um arquivo de texto informado pelo usuário e gera um segundo arquivo com cada palavra única e quantas vezes ela aparece, ordenado alfabeticamente. Menu de terminal com moldura de borda dupla, no mesmo padrão do TaskVault.

**Conceitos praticados:** tokenização com `strtok`, contagem de frequência, ordenação alfabética (`strcmp`), `fprintf`/`fgets`, modularização em pastas próprias (`fileLoader`, `wordTokenizer`, `alphabetSorter`, `mapWriter`, `mapDisplay`), entrada de caminho de arquivo via `fgets`.

```
╔════════════════════════════════════════╗
║                LEXIMAP                 ║
╠════════════════════════════════════════╣
║ 1 - Mapear palavras de um arquivo      ║
║ 2 - Ver ultimo mapeamento gerado       ║
║ 0 - Sair                               ║
╚════════════════════════════════════════╝

>: 1

╔════════════════════════════════════════╗
║             MAPEAR ARQUIVO             ║
╚════════════════════════════════════════╝

Caminho do arquivo texto: data/exemplo.txt

16 palavra(s) unica(s) encontrada(s).
Resultado salvo em: ./data/wordmap.txt

Pressione ENTER para continuar...
```

```
╔════════════════════════════════════════╗
║            ULTIMO MAPEAMENTO           ║
╚════════════════════════════════════════╝

  1) a - 2
  2) de - 2
  3) do - 2
  4) e - 1
  5) ficou - 1
  6) mais - 1
  7) o - 2
  8) pouco - 1
  9) rasgada - 1
 10) rato - 2
 11) rei - 2
 12) roeu - 2
 13) roma - 2
 14) roupa - 2
 15) um - 1
 16) voltou - 1

Pressione ENTER para continuar...
```

---
## 05. FileSlicer
> ✅ Concluído

Divide um arquivo de texto grande em partes menores com um número fixo de linhas cada, gerando `parte_1.txt`, `parte_2.txt`, e assim por diante. As partes são salvas em `./data/parts/`.

**Conceitos praticados:** múltiplos ponteiros de arquivo, `sprintf` para nomeação dinâmica, iteração por linhas, modularização em subpastas (`menu`, `slicer`, `operational`), menu com `getchar()` + `cleanBuffer()`.

```
╔════════════════════════════════════════╗
║               FILESLICER               ║
╠════════════════════════════════════════╣
║ 1 - Dividir arquivo em partes          ║
║ 0 - Sair                               ║
╚════════════════════════════════════════╝

>: 1

╔════════════════════════════════════════╗
║            DIVIDIR ARQUIVO             ║
╚════════════════════════════════════════╝

Caminho do arquivo de entrada: data/exemplo.txt
Linhas por parte: 10
  [INFO] Processando...

  [OK] Arquivo dividido com sucesso! Resultado em: ./data/parts/

Pressione ENTER para continuar...
```

---
## Compilando
Cada projeto fica na sua própria pasta com seu próprio `Makefile`.

```bash
cd 01-wordpulse
make
./wordpulse input.txt
```

---
## Objetivo
Este repositório documenta minha jornada de aprendizado com I/O de arquivos em C.  
O objetivo não é apenas código funcionando, mas entender *por que* cada abordagem funciona — incluindo os casos extremos.

---
*Parte da minha trilha de aprendizado em C*
