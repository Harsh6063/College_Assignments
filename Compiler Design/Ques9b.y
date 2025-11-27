%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);  /* declaration for Lex function */
%}

%token VARIABLE

%%

start: VARIABLE
     ;

%%

int main(void)
{
    printf("Enter variable:\n");
    if(yyparse() == 0)
        printf("Valid variable\n");
    else
        printf("Invalid variable\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("Invalid variable\n");
    exit(0);
}
