%{
#include "Ques9b.tab.h"
%}

%%

[a-z][0-9]    { return VARIABLE; }
.|\n          { /* ignore everything else */ }

%%

int yywrap(void) { return 1; }
