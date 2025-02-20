#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countWordsAndLines(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    int lineCount = 0;
    int wordCount = 0;
    char ch;
    int inWord = 0; // Flag to track if we are inside a word

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }

        if (isspace(ch)) {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    // Check for the last word if the file doesn't end with a space or newline.
    if (inWord) {
        wordCount++;
    }

    printf("Total Lines: %d\n", lineCount);
    printf("Total Words: %d\n", wordCount);

    fclose(fp);
}

int main() {
    char filename[] = "data.txt"; // Replace with your file name
    countWordsAndLines(filename);
    return 0;
}
