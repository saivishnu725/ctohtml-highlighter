#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkkeyword(char *check)
{
    int found = 0;
    char key[35][10] = {"auto", "else", "long", "switch", "break", "enum", "register", "typedef", "case", "extern", "return", "union", "char", "float", "short", "unsigned", "const", "for", "signed", "void", "continue", "goto", "sizeof", "volatile", "default", "if", "static", "while", "do", "int", "struct", "_Packed", "double"};
    for (int i = 0; i < 35; i++)
    {
        if (!(strcmp(check, key[i])))
            return 1;
    }
    return found;
}

int main(int argc, char **argv)
{
    
    return 0;
}