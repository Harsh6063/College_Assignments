%{
#include <stdio.h>
#include <stdlib.h>

/* Declare these for modern C */
void yyerror(const char *s);
int yylex(void);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    ;

%%

int main(void)
{
    if(yyparse() == 0)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
    return 0;
}

/* Define yyerror */
void yyerror(const char *s)
{
    printf("Invalid expression\n");
    exit(0);
}
