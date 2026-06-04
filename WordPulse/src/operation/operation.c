#include <stdio.h>
#include <stdlib.h>
#include "../../include/operation/operation.h"


void promptUserToContinue () {
	while (getchar () != '\n');
}

void clearScreen () {
	system("clear");
}

void clearBuffer () {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}