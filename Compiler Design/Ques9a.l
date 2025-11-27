%{
#include "Ques9a.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]   { return yytext[0]; }
[ \t\n]+    { /* ignore spaces */ }
.           { return yytext[0]; }

%%

int yywrap(void) { return 1; }
