%{
 #include "lex.h"
%}
alpha[a-zA-z];
digit[0-9];
%%
"auto"|"else"|"long"|"switch"|"break"|"enum"|"register"|"typedef"|"case"|"extern"|"return"|"union"|"char"|"float"|"short"|"unsigned"|"const"|"for"|"signed"|"void"|"continue"|"goto"|"sizeof"|"volatile"|"default"|"if"|"static"|"while"|"do"|"int"|"struct"|"_Packed"|"double"|"char"	return RESERVED;
[a-zA-Z][a-zA-Z0-9]*			return IDENTIFIER;
[+\-*/%]					return OPERATOR;
[1-9][0-9]*				return LITERAL;
[(){}]					return PARANTHESIS;
%%
int main()
{
	yin=fopen("abc.c",'r');
	yylex();
	return 0;
}



