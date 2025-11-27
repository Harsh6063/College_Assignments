%{
#include <stdio.h>
#include <string.h>

char longest[1000] = "";
%}

%%
[a-zA-Z]+  {
    if(strlen(yytext) > strlen(longest))
        strcpy(longest, yytext);
}
.|\n       ;
%%

int main() {
    yylex();
    printf("Longest word: %s\n", longest);
    return 0;
}

int yywrap() { return 1; }
