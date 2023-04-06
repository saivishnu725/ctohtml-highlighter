#include <stdio.h>
#include <stdlib.h>
#include "cparser.c"

/*              isKeyword check
int main()
{
    // printf("12 is %d \n", isKeyword("12"));          0
    // printf("char is %d \n", isKeyword("char"));      1
    return 0;
}
*/

int main()
{
    // char code[1000];
    char *code = malloc(1000);
    strcat(code, "int main()\n{\n\tint a = 5;\n\tfloat b = 3.14;\n\tchar c = 'x';\n\tchar str[] = \"Hello, world!\";\n\n\tif (a > b) {\n\t\tprintf(\"%s\\n\", str);\n\t}\n\n\treturn 0;\n}");
    struct Token token;

    // char html[1000];
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
    printf("done");
    return 0;
}
