#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char *keywords[] = {
        "if","for","while","switch","return","printf",
        "scanf","else","do","case"
    };

    for(int i = 0; i < 10; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isDatatype(char *word) {
    char *types[] = {
        "int","float","double","char","void","long","short"
    };

    for(int i = 0; i < 7; i++) {
        if(strcmp(word, types[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    char line[200];
    char word1[50], word2[50];

    int count = 0;

    printf("Enter C file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    while(fgets(line, sizeof(line), fp)) {

        // Try to extract: datatype function_name(
        if(sscanf(line, "%s %[^ (](", word1, word2) == 2) {

            // Check: valid datatype + not keyword + not main
            if(isDatatype(word1) &&
               !isKeyword(word2) &&
               strcmp(word2, "main") != 0 &&
               strchr(line, '{') != NULL) {

                count++;
            }
        }
    }

    fclose(fp);

    printf("Number of user-defined functions: %d\n", count);

    return 0;
}
