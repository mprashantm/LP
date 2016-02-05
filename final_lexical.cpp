#include<stdio.h>
#include<stdlib.h>
#define bool int 
#define true 1
#define false 0
#define NUMKEY 32
#define NUMOP  23
char keyword[32][15]={"auto","double","int","struct",
				  "break","else","long","switch",
				  "case" ,"enum","register","typedef",
				  "char" ,"extern","return","union"
				  "continue","for","signed","void",
				  "do","if","static" ,"while",
				  "default","goto","sizeof","volatile",
				  "const",	"float","short","unsigned"};
char operator[23][3]={"+","-","*","/","%",">","<","=",
					  "+=","-=","*=","/=","%=",">=",
					  "<=","==","^" ,"&","|","&&","||",
					  "++","--"};
char punctuator[]={'[',']','(',')','{','}',':',';','#','"'};

char space[]={' ','\t','\n','\v','\r','\f'};
bool isAlpha(char ch)
{
	return ((ch>='A' && ch<='Z') ||(ch>='a' && ch<='z'));
}					 
bool isDigit(char ch)
{
	return (ch>='0' && ch<='9');
}
bool isPunctuator(char ch)
{
	int i=0,len=strlen(punctuator);
	for(;i<len;i++)
		if(ch==punctuator[i])return true;
	return false;
}
bool isSpace(char ch)
{
	int i=0,len=strlen(space);
	for(;i<len;i++)
		if(ch==space[i])
			return true;
	return false;
}
bool isOperator(char token[])
{
	if(strcmp(token,"")==0)return false;
	int i;
	for(i=0;i<NUMOP;i++)
	{
		if(strcmp(token,operator[i])==0)
			return true;
	}
	return false;
}
bool isKeyword(char token[])
{
	if(strcmp(token,"")==0)return false;
	int i;
	for(i=0;i<NUMKEY;i++)
	{
		if(strcmp(token,keyword[i])==0)
			return true;
	}
	return false;
}
bool isIdentifier(char token[])
{ 
	if(strcmp(token,"")==0)return false;
	int i=0,len=strlen(token);
 	if(isAlpha(token[i])||token[i]=='_')
 	{
 		for(i=1;i<len ;i++)
 			if(!(isAlpha(token[i])
 			   ||isDigit(token[i])
 			   ||(token[i]=='_')))
 				return false;
 		return true;	

 	}
 	return false;
}
bool isConstant(char token[])//numeric constant 
{
  int i=0,len=strlen(token);
  while(i<len && isDigit(token[i++]));
  if(i==len)return true;
  return false;
}
char* toArray(char *op,char ch)
{
	int l;
	op[l=strlen(op)]=ch;
	op[l+1]='\0';
	return op;
}
void flush(char arr[])
{
	int i=0,len=strlen(arr);
	for(;i<len;i++)
		arr[i]='\0';
}
int main(int argc, char const *argv[])
{
	char token[1024];
	int j;
	char op[3];//=(char *)malloc(sizeof(char)*3);
	FILE *fp=fopen("test.c","r");
	char ch;
	while((ch = fgetc(fp)) != EOF)
	{
             //putchar(c);
		//printf("%c",)
		op[0]=ch;op[1]='\0';
		if(isSpace(ch)||isPunctuator(ch)||isOperator(op))
		{
			if(token[0]!='\0')
			{
				//printf("from if %s\n",token);
				if(isKeyword(token))
					printf("%s keyword\n",token);
				else if(isIdentifier(token))
					printf("%s Identifier\n",token);
				else if(isConstant(token))
					printf("%s Constant\n",token);
			}
			if(isSpace(ch))
			{}
			else if(isPunctuator(ch))
			{
				printf("%c punctuator\n",ch);
			}
			else //operator
			{
				if((ch=fgetc(fp))!=EOF )
				{	
					op[1]=ch;op[2]='\0';
					if(isOperator(op))
					{
						printf("%s operator\n",op);
					}
					else 
					{
						fseek(fp,-1,SEEK_CUR);
						op[1]='\0';
						printf("%s operator\n",op);
					}
				}
			} 
			flush(token);flush(op); 
			j=0;      
        }
        else
        {
        	token[j++]=ch;
        }
    }
}
