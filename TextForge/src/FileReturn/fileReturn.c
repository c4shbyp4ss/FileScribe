#include <stdio.h>
#include "../../include/FileReturn/fileReturn.h"


FILE * fileReturn (char * directoryPath, char * typeOpen) {
	// abrindo arquivo no tipo leitura
	FILE * file = fopen(directoryPath, typeOpen);
	if (!file) return NULL;
	return file;
}