#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return", "void", "main"};
int isKeyword(char *str)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(keywords[i], str) == 0)
        return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>');
}

int main()
{
    FILE *fp;
    char ch, str[100];
    int i;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error: File cannot be opened.\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        
        if (isspace(ch))
            continue;

        
        if (isOperator(ch))
        {
            printf("Operator: %c\n", ch);
        }
        
        else if (isalpha(ch))
        {
            i = 0;
            str[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
            {
                str[i++] = ch;
            }
            str[i] = '\0';
            if (isKeyword(str))
                printf("Keyword: %s\n", str);
            else
                printf("Identifier: %s\n", str);
            
            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }
    }

    fclose(fp);
    return 0;
}
