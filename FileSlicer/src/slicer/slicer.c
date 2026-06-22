#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slicer/slicer.h"
#include "config/config.h"

int sliceFile(const char *input_path, int lines_per_part, const char *output_dir) {
    FILE *input = NULL;
    FILE *output = NULL;
    char line[MAX_LINE_LEN];
    char out_path[MAX_PATH_LEN];
    int part_num = 1;
    int line_count = 0;

    if (lines_per_part <= 0) {
        return -1;
    }

    input = fopen(input_path, "r");
    if (input == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        if (line_count % lines_per_part == 0) {
            if (output != NULL) {
                fclose(output);
                output = NULL;
            }

            snprintf(out_path, sizeof(out_path), "%sparte_%d.txt", output_dir, part_num);
            output = fopen(out_path, "w");
            if (output == NULL) {
                fclose(input);
                return -1;
            }
            part_num++;
        }

        fputs(line, output);
        line_count++;
    }

    if (output != NULL) {
        fclose(output);
    }
    fclose(input);

    return 0;
}
