%{
#include <stdio.h>

int char_count = 0;
int line_count = 0;
%}

%%

\n          { line_count++; char_count++; }   /* Count newline as both a character and a line */
.           { char_count++; }                 /* Count all other characters */

%%

int main(int argc, char *argv[])
{
    yylex();  /* Start lexical analysis */
    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", char_count);
    return 0;
}

int yywrap(void) {
    return 1;
}

