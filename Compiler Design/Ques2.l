%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%

[AEIOUaeiou]     { vowels++; }
[a-zA-Z]         { consonants++; }
.|\n             { /* ignore everything else */ }

%%

int yywrap(void) { return 1; }

int main(void)
{
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    return 0;
}
