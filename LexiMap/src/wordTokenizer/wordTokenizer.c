#include <string.h>
#include <ctype.h>
#include "wordTokenizer/wordTokenizer.h"
#include "config/config.h"

static void toLowerCase(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
}

int tokenizeAndCount(char *text, Word list[]) {
    int total = 0;
    char *token = strtok(text, " \n\t.,;:!?\"");

    while (token != NULL) {
        toLowerCase(token);

        int found = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(list[i].text, token) == 0) {
                list[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && total < MAX_WORDS) {
            strncpy(list[total].text, token, MAX_WORD_LEN - 1);
            list[total].text[MAX_WORD_LEN - 1] = '\0';
            list[total].count = 1;
            total++;
        }

        token = strtok(NULL, " \n\t.,;:!?\"");
    }

    return total;
}
