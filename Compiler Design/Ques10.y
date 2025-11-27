%{
#include <stdio.h>
#include <stdlib.h>

/* Declarations for modern C */
void yyerror(const char *s);
int yylex(void);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%

expr:
      expr '+' expr { printf("%d + %d = %d\n", $1, $3, $1+$3); $$ = $1 + $3; }
    | expr '-' expr { printf("%d - %d = %d\n", $1, $3, $1-$3); $$ = $1 - $3; }
    | expr '*' expr { printf("%d * %d = %d\n", $1, $3, $1*$3); $$ = $1 * $3; }
    | expr '/' expr { 
        if ($3 == 0) yyerror("Division by zero");
        else { printf("%d / %d = %d\n", $1, $3, $1/$3); $$ = $1 / $3; }
      }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER        { $$ = $1; }
    ;

%%

int main(void)
{
    printf("Enter arithmetic expression(s):\n");
    if(yyparse() == 0)
        ; // already printed during parsing
    else
        printf("Invalid expression\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("Error: %s\n", s);
    exit(0);
}
