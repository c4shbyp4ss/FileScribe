#include <stdio.h>
#include <string.h>
#include "../../include/menus/menus.h"
#include "../../include/operation/operation.h"
#include "../../include/lineScout/lineScout.h"
#include "../../include/wordHarvester/wordHarvester.h"
#include "../../include/charSweeper/charSweeper.h"

void welcome () {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║                           ║\n");
	printf("║        WordPulse          ║\n");
	printf("║   Contador de Texto v1.0  ║\n");
	printf("║                           ║\n");
	printf("║  Bem-vindo! Pressione     ║\n");
	printf("║  ENTER para iniciar...    ║\n");
	printf("║                           ║\n");
	printf("╚═══════════════════════════╝\n");


	promptUserToContinue();
}


void mainMenu (char * ptr_op) {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║        WordPulse          ║\n");
	printf("║  Contador de Texto v1.0   ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║  1. Analisar texto        ║\n");
	printf("║  2. Sobre                 ║\n");
	printf("║  3. Configurar Caminho    ║\n");
	printf("║  0. Sair                  ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("   Escolha uma opcao: ");
	*ptr_op = getchar();

	clearBuffer();
}

void on () {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║    WordPulse > Sobre      ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║  WordPulse v1.0           ║\n");
	printf("║  Contador de Texto        ║\n");
	printf("║                           ║\n");
	printf("║  Desenvolvido em C        ║\n");
	printf("║  Autor: C4shByp4ss        ║\n");
	printf("║  ───────────────────────  ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║ Pressione ENTER p/ voltar ║\n");
	printf("╚═══════════════════════════╝\n");

	promptUserToContinue();
}


void defineDirectory (char dir[]) {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║  WordPulse > Diretorio    ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║                           ║\n");
	printf("║  Informe o caminho do     ║\n");
	printf("║  arquivo a ser lido:      ║\n");
	printf("║                           ║\n");
	printf("║  > ");
	fgets(dir, 256, stdin);
	dir[strcspn(dir, "\n")] = '\0';
	printf("║                           ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║       Digite enter...     ║\n");
	printf("╚═══════════════════════════╝\n");

	promptUserToContinue();
}


void fileNotFound (FILE * file) {
	if (!file) {

		clearScreen();

		printf("╔═══════════════════════════╗\n");
		printf("║  WordPulse > Diretorio    ║\n");
		printf("╠═══════════════════════════╣\n");
		printf("║                           ║\n");
		printf("║  Arquivo nao encontrado!  ║\n");
		printf("║                           ║\n");
		printf("║  Verifique o caminho      ║\n");
		printf("║  e tente novamente.       ║\n");
		printf("║                           ║\n");
		printf("╠═══════════════════════════╣\n");
		printf("║       Digite enter...     ║\n");
		printf("╚═══════════════════════════╝\n");

		promptUserToContinue();
	}
}



void farewell () {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║                           ║\n");
	printf("║        WordPulse          ║\n");
	printf("║                           ║\n");
	printf("║   Obrigado por usar o     ║\n");
	printf("║   WordPulse. Ate logo!    ║\n");
	printf("║                           ║\n");
	printf("╚═══════════════════════════╝\n\n");
}




void wrongOption () {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║                           ║\n");
	printf("║        WordPulse          ║\n");
	printf("║                           ║\n");
	printf("║   Opcao invalida!         ║\n");
	printf("║   Digite apenas numeros   ║\n");
	printf("║   do menu.                ║\n");
	printf("║                           ║\n");
	printf("║   Tente novamente...      ║\n");
	printf("║                           ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║  Pressione ENTER: _       ║\n");
	printf("╚═══════════════════════════╝\n");

	promptUserToContinue();
}



// option menus
void analysisType (char * ptr_op) {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║    WordPulse > Analise    ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║  1. Contar palavras       ║\n");
	printf("║  2. Contar linhas         ║\n");
	printf("║  3. Contar caracteres     ║\n");
	printf("║  4. Contar tudo           ║\n");
	printf("║  ───────────────────────  ║\n");
	printf("║  0. Voltar                ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("   Escolha uma opcao: ");

	*ptr_op = getchar();

	clearBuffer();
}
void analyzeResult (char op, FILE * file) {

	clearScreen();

	printf("╔═══════════════════════════╗\n");
	printf("║   WordPulse > Resultado   ║\n");
	printf("╠═══════════════════════════╣\n");
	op == '1' || op == '4' ? printf("║  Palavras:      %05d     ║\n", wordHarvester(file)) : (void)0;
	op == '2' || op == '4' ? printf("║  Linhas:        %05d     ║\n", lineScout (file)) : (void)0;
	op == '3' || op == '4' ? printf("║  Caracteres:    %05d     ║\n", charSweeper (file)) : (void)0;
	printf("║  ───────────────────────  ║\n");
	printf("╠═══════════════════════════╣\n");
	printf("║       Digite enter...     ║\n");
	printf("╚═══════════════════════════╝\n");

	promptUserToContinue();

}