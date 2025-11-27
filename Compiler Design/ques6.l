%{
#include <stdio.h>
int words = 0, chars = 0, spaces = 0, lines = 0;
%}

%%

[ \t]+          { spaces += yyleng; }
\n              { lines++; chars++; }
[a-zA-Z0-9_]+   { words++; chars += yyleng; }
.               { chars++; }

%%

int yywrap(void) { return 1; }

int main(void) {
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    printf("Spaces: %d\n", spaces);
    return 0;
}
