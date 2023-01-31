#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct keyword_found
{
    int found;
    int index;
};


// for testing purposes. I will remove this later.
int main()
{
    struct keyword_found a;
    a = checkkeyword("case");
    printf("%d\t%d\n", a.found , a.index);
    return 0;
}


struct keyword_found checkkeyword(char *check)
{
    // int found[2];
    // static int found[2];
    struct keyword_found found;

    found.found = -1;
    // found[0] = -1;

    char key[35][10] = {"auto", "else", "long", "switch", "break", "enum", "register", "typedef", "case", "extern", "return", "union", "char", "float", "short", "unsigned", "const", "for", "signed", "void", "continue", "goto", "sizeof", "volatile", "default", "if", "static", "while", "do", "int", "struct", "_Packed", "double"};
    for (int i = 0; i < 35; i++)
    {
        if (!(strcmp(check, key[i])))
        {
            // just for checking for presence of keyword
            // return 1;

            // for the type of keyword. wait!! i forgot why i was trying soo hard to send the index as well -_- like fr
            // found[0] = 1;
            found.found = 1;
            found.index = i;
            // found[1] = i;
            return found;
        }
    }
    return found;
}
