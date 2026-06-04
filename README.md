# FileScribe

Uma coleção de pequenos projetos em C focados em **I/O de arquivos e manipulação de texto**.  
Cada projeto isola um conceito específico, tornando este repositório uma referência pessoal para aprender e revisitar o tratamento de arquivos em C.

---

## Projetos

| # | Nome | Descrição | Status |
|---|------|-----------|--------|
| 01 | [WordPulse](#01-wordpulse) | Contador de palavras, linhas e caracteres | ✅ Concluído |
| 02 | [TextForge](#02-textforge) | Busca e substituição em arquivos de texto | 🔜 Planejado |
| 03 | [TaskVault](#03-taskvault) | Gerenciador de tarefas em arquivo | 🔜 Planejado |
| 04 | [LexiMap](#04-leximap) | Indexador de frequência de palavras | 🔜 Planejado |
| 05 | [FileSlicer](#05-fileslicer) | Divisor de arquivos por número de linhas | 🔜 Planejado |

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

> 🔜 Planejado

Lê um arquivo de origem, substitui todas as ocorrências de uma palavra por outra e salva o resultado em um novo arquivo.

**Conceitos a praticar:** `strstr`, `fgets`, `fputs`, leitura e escrita em streams de arquivo separados.

---

## 03. TaskVault

> 🔜 Planejado

Um to-do list minimalista em CLI que persiste tarefas em um arquivo `.txt`. Suporta adicionar, listar e marcar tarefas como concluídas.

**Conceitos a praticar:** modo append (`"a"`), parsing de linhas, reescrita de arquivo.

---

## 04. LexiMap

> 🔜 Planejado

Lê um arquivo de texto e gera um segundo arquivo com cada palavra única e quantas vezes ela aparece, ordenado alfabeticamente.

**Conceitos a praticar:** tokenização com `strtok`, contagem de frequência, `fprintf`, ordenação.

---

## 05. FileSlicer

> 🔜 Planejado

Divide um arquivo de texto grande em partes menores com um número fixo de linhas cada, gerando `parte_1.txt`, `parte_2.txt`, e assim por diante.

**Conceitos a praticar:** múltiplos ponteiros de arquivo, `sprintf` para nomeação dinâmica, iteração por linhas.

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
