#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/wordReplacer/wordReplace.h"


char * wordReplace (char * text, char * oldWord, char * newWord) {

	// medir tamanho das palavras
	int oldWordSize = strlen(oldWord);
	int newWordSize = strlen(newWord);
	// anotando as ocorrencias da palavra antiga
	int oldWordOccurrence = 0;

	// apontador de memoria do texto
	char * pointerText = text;

	// verificando quando a palavra antiga irar aparecer
	// quando aparecer, ponteiro de texto vai receber o começo
	// do endereço da paralavra
	while ((pointerText = strstr(pointerText, oldWord)) != NULL) {
		/*
			Anotando quando a palavra que iremos trocar aparecer
		*/
		oldWordOccurrence++;

		/*
			Pulando o endereço do apontador do Texto,
			pois o apontador está apontado para o primeiro
			endereço da palavra antiga, vamos incrementar 
			o tamanho da palavra para pular
		*/
		pointerText += oldWordSize;
	}

	// alocar um tamanho novo para armazenar a o texto novo
	long int newTextSize = (long int) strlen(text) + oldWordOccurrence * ((int) newWordSize - (int) oldWordSize) +1;

	// criando um ponteiro para armazenar o texto novo com o novo tamanho alocado
	char * newText = malloc(newTextSize);
	if (!newText) return NULL; 

	// capturando palavra encontrada
	char * foundWord;
	// criando um apontador de memória para o novo espaço alocado
	char * tunnel = newText;
	// deixando o apontador do texto começando com o primeiro endereço do texto	
	pointerText = text;


	// procurando a palavra antiga e guardando no apontador
	while ( (foundWord = strstr(pointerText, oldWord)) != NULL ) {
		// agora FoundWord está apontando para o primeiro endereço da palavra selecionada

		// guardando o trecho de até onde aparece a palavra alvo
		long int excerpt = foundWord - pointerText;
		// copiando techo do texo antes que a palavra antiga apareça
		memcpy (tunnel, pointerText, excerpt);
		// incrementando o endereço do Tunnel até onde a palavra antiga vai aparecer
		tunnel += excerpt;

		// copiando a palavra nova até o endereço correto dela
		memcpy(tunnel, newWord, newWordSize);
		// incrementando o tamanho da palavra nova para o tunnel pular ela
		tunnel += newWordSize;

		// incrementando onde encontramos a palavra nova e o tamanho da nova palavra
		// para o compilador entender que queremos pular essa parte
		pointerText = foundWord + oldWordSize;
	}

	// copiando o resto do texto
	strcpy (tunnel, pointerText);
	// retornando o novo texto
	return newText;
}