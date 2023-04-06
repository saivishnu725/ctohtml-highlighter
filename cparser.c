#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum TokenType
{
    IDENTIFIER,
    INTEGER,
    FLOAT,
    STRING,
    CHAR,
    KEYWORD,
    OPERATOR,
    PUNCTUATOR
};

struct Token
{
    enum TokenType type;
    char value[100];
};

int isKeyword(char *str)
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], str) == 0)
        {
            return 1;
        }
    }
    return 0;
}

struct Token checkTokenType(char *str)
{
    struct Token token = {0};
    int i = 0, j = 0, len = strlen(str);
    char current_char = str[i];

    if (isalpha(current_char))
    {
        while (isalnum(current_char))
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
        token.type = isKeyword(token.value) ? KEYWORD : IDENTIFIER;
    }
    else if (isdigit(current_char))
    {
        while (isdigit(current_char))
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
        if (current_char == '.')
        {
            token.value[j++] = current_char;
            current_char = str[++i];
            while (isdigit(current_char))
            {
                token.value[j++] = current_char;
                current_char = str[++i];
            }
            token.type = FLOAT;
        }
        else
        {
            token.type = INTEGER;
        }
    }
    else if (current_char == '"')
    {
        token.type = STRING;
        token.value[j++] = current_char;
        current_char = str[++i];
        while (current_char != '"' && i < len)
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
        token.value[j++] = current_char;
        current_char = str[++i];
    }
    else if (current_char == '\'')
    {
        token.type = CHAR;
        token.value[j++] = current_char;
        current_char = str[++i];
        if (current_char != '\\')
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
        token.value[j++] = current_char;
        current_char = str[++i];
        token.value[j++] = current_char;
        current_char = str[++i];
    }
    else if (ispunct(current_char))
    {
        token.type = PUNCTUATOR;
        while (ispunct(current_char))
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
    }
    else
    {
        token.type = OPERATOR;
        while (!isalnum(current_char) && !ispunct(current_char) && i < len)
        {
            token.value[j++] = current_char;
            current_char = str[++i];
        }
    }
    token.value[j] = '\0';
    return token;
}

void printTokens(char *code)
{
    struct Token token;

    FILE *f;
    f = fopen("output.html", "w");
    if (f == NULL)
    {
        printf("didnt open :'(");
        exit(EXIT_FAILURE);
    }
    printf("open\n");
    fprintf(f, "<html>\n<head>\n<style>\n");
    fprintf(f, "body { font-family: Courier; }\n");
    fprintf(f, ".keyword { color: blue; }\n");
    fprintf(f, ".integer { color: red; }\n");
    fprintf(f, ".float { color: red; }\n");
    fprintf(f, ".string { color: green; }\n");
    fprintf(f, ".char { color: green; }\n");
    fprintf(f, ".operator { color: black; }\n");
    fprintf(f, ".punctuator { color: black; }\n");
    fprintf(f, "</style>\n</head>\n<body> <pre>\n");
    while (*code != '\0')
    {
        token = checkTokenType(code);
        code += strlen(token.value);
        if (token.type == KEYWORD)
        {
            fprintf(f, "<span class=\"keyword\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == INTEGER)
        {
            fprintf(f, "<span class=\"integer\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == FLOAT)
        {
            fprintf(f, "<span class=\"float\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == STRING)
        {
            fprintf(f, "<span class=\"string\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == CHAR)
        {
            fprintf(f, "<span class=\"char\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == OPERATOR)
        {
            fprintf(f, "<span class=\"operator\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else if (token.type == PUNCTUATOR)
        {
            fprintf(f, "<span class=\"punctuator\">");
            fprintf(f, token.value);
            fprintf(f, "</span>");
        }
        else
        {
            fprintf(f, token.value);
        }
    }
    fprintf(f, "\n </pre> </body>\n</html>");
    fclose(f);
}