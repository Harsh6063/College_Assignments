%{
#include <stdio.h>
#include <string.h>

char str[100];
%}

%%
[a-zA-Z]+   {
                strcpy(str, yytext);   /* store the input string */
            }
.|\n        ;
%%

int yywrap(void) { return 1; }

int main(void)
{
    printf("Enter a string: ");
    yylex();  /* read the string */

    int len = strlen(str);
    for (int i = len; i > 0; i--) {
        for (int j = 0; j < i; j++)
            printf("%c", str[j]);
        printf("\n");
    }
    return 0;
}
