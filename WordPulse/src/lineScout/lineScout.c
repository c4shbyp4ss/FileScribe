#include <stdio.h>
#include <ctype.h>
#include "../../include/lineScout/lineScout.h"

int lineScout (FILE * file) {
	rewind(file);
	char line [256];
	int count = 0;
	while (fgets(line, sizeof(line), file) != NULL) {
		count++;
	} 

	return count;
}