#include<bits/stdc++.h>
#include<string>
using namespace std;
struct Production
{
	char lhs;
	vector<string > rhs;
};
int num_pro;
vector<Production> P;
int Map[26];
char Map1[26];
int cnt=0;
void tokenizer(string S,char lhs,vector<string > &rhs)
{
	char A[10];
	int j=0;
	for(int i=0;i<S.length();i++)
	{
		if(S[i]=='|')
		{
			A[j]='\0';
			j=0;
			string s(A);
			rhs.push_back(s);
		}
		else
		{
			A[j++]=S[i];
		}
	}
	A[j]='\0';
	string s(A);
	rhs.push_back(s);
	if(Map[lhs-'A']<Map[A[0]-'A'])//i<j
		rhs.push_back(true);
	else
		rhs.push_back(false);
	for(int i=0;i<rhs.size();i++)
		cout<<rhs[i]<<" ";
}
// void make_i_less_j()
// {
// 	int siz=P.size();
// 	for(int i=0;i<siz;i++)
// 	{
		
// 	}
// }
int main(int argc, char const *argv[])
{
		cout<<"number of variables:";
		cin>>num_pro;
		char lhs;
		for(int i=0;i<num_pro;i++)
		{
			Production p;
			string s;
			cout<<"left side ";
			cin>>lhs;
			Map[lhs-'A']=cnt;
			//Map1[cnt++]=lhs;
			p.lhs=lhs;
			cout<<"rhs (ex. aA|bB)";
			cin>>s;
			//vector<string > rhs;
			tokenizer(s,p.rhs);	
			//p.rhs=rhs;
			P.push_back(p);
		}
		 int siz=P.size();
		 cout<<"size is"<<siz<<"\n";
    for(int i=0;i<siz;i++)
    {
     	cout<<"P[i].rhs.size()"<<P[i].rhs.size()<<"\n";
     	for(int j=0;j<P[i].rhs.size();j++)
     		cout<<P[i].lhs<<" -> "<<P[i].rhs[j]<<"\n";
    }
    int flag=0;
    for(int i=0;i<P.size();i++)
    {
    	flag=0;
    	while(!flag)
    	{
    		flag=1;
    		for(int j=0;j<P[i].rhs.size();j++)
    		{
    			if(P[i].rhs[j][0]>='A' && P[i].rhs[j][0]<='Z' && Map[P[i].rhs[j][0]-'A']<Map[P[i].lhs-'A'])//Ai=>Aja j<i
    			{//Ai->AjALPHA
    				flag=0;
    				string substring = P[i].rhs[j].substr(1);//Alpha
    				int index=Map[P[i].rhs[j][0]-'A'];
    				for(int k=0;k<P[index].rhs.size();k++)
    				{
    					string s1;
    					s1.assign(P[index].rhs[k]);
    					s1.append(substring);
    					P[i].rhs.push_back(s1);
    				}
    				P[i].rhs.erase(P[i].rhs.begin()+j);

    			}
    		}

    	}
    	//remove immediate left recursion 
    	int flag=0;
    	vector<string >tmp;
    	for(int j=0;j<P[i].rhs.size();j++)
    	{
    		if(P[i].lhs==P[i].rhs[j][0])
    		{
    			flag=1; 
    		} 
    		else
    		{
    			tmp.push_back(P[i].rhs[j]);
    		}
    	}
    	if(flag==1)
    	{
    		//
    	}

    }


     //c_str();string to array
    //string s(chararray);//char aaray to string
    //strtok(char aaray,const char *delimiter)


}

