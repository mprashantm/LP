//program will only work for mathematical expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEYWORD 1
#define IDENTIFIER 2
#define OPERATOR 3
#define PARANTHESIS 4
#define LITERAL 5 
int main()
{
	char ex[100];//store entered expression
	char *token=(char *)malloc(sizeof(char)*100);//store current token
        char *st=token;//keep track of start of ch block
 	int current=0;//what is the class of current token
        scanf("%[^\n]%*c",Ex);//scanf with blankspace
	int i=0,l=strlen(EX),j=0;
	while(i<l)
	{
		ch=Ex[i];
	        if(current==0)
		{
			
			if((ch=='_')||(ch>='A'&&ch<='Z')||(ch>='a' && ch<='z'))
			{
				switch(current)
				{
					case IDENTIFIER:	token[j++]=ch;break;
					case OPERATOR:		{current=IDENTIFIER;token[j]='\0';printf("%s  operator\n",token);token[j=0]=ch;}
								break;
					case PARANTHESIS:	{current=IDENTIFIER;token[j]='\0';printf("%s  braces\n",token);token[j=0]=ch;}									break;
					case 
				}
			}
			else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='=')
			{
				current=OPERATOR;token[j++]=ch;
			}
			else if(ch=='('||ch==')')
			{
				current=PARANTHESIS;token[j++]='('
			}
			else if(ch>='0'&&ch<='9')	
			{
				current=LITERAL;token[j++]=ch;
			}
		}	
		else if(current==2)//is identifier
		{
			if(ch=='_'||(ch>='A'&&ch<='Z')||(ch>='a' && ch<='z')||(ch>='0'&&ch<='9'))
			{	
				current=IDENTIFIER;token[j++]=ch;
				
			}
		}
		
			
	
	}
}
