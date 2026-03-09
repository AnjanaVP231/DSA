#include <stdio.h>
#include <string.h>

int main() {

    FILE *fp;
    char line[200];
    int count = 0;
    char s[20];
    printf("Enter a c program file :");
    scanf("%s",s);
    fp = fopen(s, "r");   // File to analyze

    if(fp == NULL) {
        printf("File cannot be opened\n");
        return 0;
    }

    while(fgets(line, sizeof(line), fp)) {

        // Check if line contains '(' and ')'
        if(strstr(line, "(") && strstr(line, ")") && strstr(line, "{")) {

            // Ignore common built-in functions
            if(strstr(line, "main") ||
               strstr(line, "printf") ||
               strstr(line, "scanf"))
                continue;

            count++;
        }
    }

    fclose(fp);

    printf("Number of user-defined functions: %d\n", count);

    return 0;
}
