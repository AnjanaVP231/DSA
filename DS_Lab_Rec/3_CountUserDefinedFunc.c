#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50], line[100];
    int count = 0;
    
    printf("Enter file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("File not found!\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "(") && strstr(line, ")") && strstr(line, "{"))
        {
            if (!strstr(line, "main") && !strstr(line, "if") && !strstr(line, "for") &&
                !strstr(line, "while") && !strstr(line, "switch"))
            {
                count++;
            }
        }
    }
    fclose(fp);

    printf("Number of user-defined functions = %d\n", count);
    return 0;
}
