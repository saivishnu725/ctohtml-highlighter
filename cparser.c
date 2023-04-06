#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum TokenType {
    IDENTIFIER, INTEGER, FLOAT, STRING, CHAR, KEYWORD, OPERATOR, PUNCTUATOR
};

struct Token {
    enum TokenType type;
    char value[100];
};

int isKeyword(char *str) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"
                            };
    int i;
    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}