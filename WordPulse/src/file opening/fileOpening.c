#include <stdio.h>
#include "../../include/file opening/fileOpening.h"

FILE * fileOpening (char * dir) {
	FILE * file = fopen(dir, "r");
	if (file == NULL) {
		return NULL;
	}
	return file;
}