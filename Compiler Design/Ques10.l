%{
#include "Ques10.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]   { return yytext[0]; }
[ \t\n]+    { /* ignore whitespace */ }
.           { return yytext[0]; }

%%

int yywrap(void) { return 1; }
