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
    char *code = calloc(1000, sizeof(char));
    strcat(code, "int main()\n{\n\tprintf( \"Hello world!!\" );\n\treturn 0;\n}");
    // strcat(code, "int main() {\n  int x = 10;\n  printf(\"Hello, world! My integer variable is %d.\\n\", x);\n  return 0;\n}\0");
    // strcat(code, "int main()\n{\n\tint a = 5;\n\tfloat b = 3.14;\n\tchar c = 'x';\n\tchar str[] = \"Hello, world!\";\n\n\tif (a > b) {\n\t\tprintf(\"%s\\n\", str);\n\t}\n\n\treturn 0;\n}");
    printTokens(code);
    printf("done");
    return 0;
}
