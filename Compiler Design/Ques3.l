%{
#include <stdio.h>
char shift(char c) {
    if(c >= 'a' && c <= 'z')
        return 'a' + (c - 'a' + 3) % 26;
    else if(c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + 3) % 26;
    else
        return c;
}
%}

%%
.   { putchar(shift(yytext[0])); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() { return 1; }
