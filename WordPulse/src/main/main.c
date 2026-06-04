#include <stdio.h>
#include "../../include/menus/menus.h"
#include "../../include/operation/operation.h"
#include "../../include/file opening/fileOpening.h"
#include "../../include/wordHarvester/wordHarvester.h"

int main () {

	// declarações de variaveis

	char op;
	char * ptr_op = &op;

	char dir[256];
	FILE * file = NULL;
	// execuções

	// tela de boas vindas

	welcome ();

	// menu_principal

	do {

		mainMenu(ptr_op);

		switch (op) {
			case '1': {
				char op2;
				ptr_op = &op2;
				do {

					analysisType(ptr_op);

					switch (op2) {
						case '0': {
							break;
						}

						case '1': {}
						case '2': {}
						case '3': {}
						case '4': {
							analyzeResult(op2, file);
							break;
						}
					}
				} while (op2 != '0');
				ptr_op = &op;
				break;
			}

			case '2': {
				on();
				break;
			}

			case '3': {
				defineDirectory(dir);
				file = fileOpening(dir);
				fileNotFound(file);
				break;
			}

			case '0': {
				farewell();
				break;
			}

			default: {
				wrongOption();
			}
		}

	} while (op != '0');

	return 0;
}