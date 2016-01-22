%{
//	#include "mylex.h"
%}
%%
"prashant"|"mishra"	printf("mishra ji");
"shubham"|"shukla"	printf("shukla ");
[34+]			printf("lau");
%%
 int yywrap(void)
  {
    return 1;
  }

