#include <string.h>
#include "alphabetSorter/alphabetSorter.h"

void sortWordsAlphabetically(Word list[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(list[j].text, list[j + 1].text) > 0) {
                Word temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
