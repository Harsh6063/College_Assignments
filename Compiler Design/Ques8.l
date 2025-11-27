%{
#include <stdio.h>
#include <ctype.h>
int valid;   /* Flag to check validity */
%}

%%

\n      {  /* end of expression */
            if(valid)
                printf("Valid arithmetic expression\n");
            else
                printf("Invalid expression\n");
            valid = 1;  /* reset for next line */
         }
[0-9]+  { /* integers are valid */ }
[+\-*/] { /* operators are valid */ }
[ \t]+  { /* ignore spaces */ }
.       { valid = 0; }   /* any other character invalidates line */
%%

int yywrap(void) { return 1; }

int main(void) {
    valid = 1;   /* assume valid at start */
    yylex();
    return 0;
}
