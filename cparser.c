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