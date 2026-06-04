#include <stdio.h>
#include <ctype.h>
#include "../../include/charSweeper/charSweeper.h"


int charSweeper (FILE * file) {
	rewind(file);
	int c = 0;

	int character;

	while ((character = fgetc(file)) != EOF) {

		if (!isspace(character)) {
			c++;
		}
	}

	return c;
}