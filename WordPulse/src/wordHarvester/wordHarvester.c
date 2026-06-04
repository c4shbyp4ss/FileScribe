#include <stdio.h>
#include <ctype.h>
#include "../../include/wordHarvester/wordHarvester.h"



int wordHarvester (FILE * dir_file) {
	rewind(dir_file);
    int count = 0, within = 0;
    char line[256];

    while (fgets(line, sizeof(line), dir_file) != NULL) {
        int i = 0;
        while (line[i] != '\n' && line[i] != '\0') {    
            if (!isspace(line[i])) {
                if (!within) {
                    count++;
                    within = 1;                            
                }
            } else {
                within = 0;
            }
            i++;
        }
    }

    return count;
}