#include<iostream>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
#define NUM_VAR 5
#define NUM_TERM 6
#include<iomanip>
using namespace std;
struct Production
{
        char lhs;
        vector<string > rhs;
        set<char  > first;
        set<char > follow;
};
int num_pro;
vector<Production> P(5);
int Map[26];
map<char ,int > tmap; 
//char Map1[26];
int cnt=0;
void insert(int source ,int dest)
{
	set<char > ::iterator it;
	for(it=P[source].first.begin();it!=P[source].first.end();it++)
	{
		P[dest].first.insert(*it);
	}
}
void insertF(int source ,int dest)
{
	set<char > ::iterator it;
	for(it=P[source].follow.begin();it!=P[source].follow.end();it++)
	{
		P[dest].follow.insert(*it);
	}
}
void getfirst(char ch)
{
	int index=Map[ch-'A'];
	if(P[index].first.size()!=0)
	return ;

	for(int i=0;i<P[index].rhs.size();i++)
	{
		for(int j=0;j<P[index].rhs[i].length();j++)
		{
			if(P[index].rhs[i][j]>='A' && P[index].rhs[i][j]<='Z')//is non terminal 
			{
				
					int ind=Map[P[index].rhs[i][j]-'A'];
					getfirst(P[index].rhs[i][j]);
					insert(ind,index);
					if(P[ind].first.find('~')==P[ind].first.end())
					break;
					else
					continue;
			}
			if(P[index].rhs[i][j]<='A' || P[index].rhs[i][j]>='Z')//is terminal 
			{
					P[index].first.insert( P[index].rhs[i][j]);
					break;
			}
			
		}
	}
//	cout<<"\n\n\n";
	
	
}
int  getfollow(char ch)
{
	//cout<<"finding follow of"<<ch<<"\n";
	int index=Map[ch-'A'];
	//cout<<P[index].follow.size()<<"\n";
	if(P[index].follow.size()>1 ||(P[index].follow.size()>0  && index!=0))//start symbol have '$'
	return 0;
	//	cout<<"finding follow of"<<ch<<"\n";
	for(int i=0;i<P.size();i++)
	{
		for(int j=0;j<P[i].rhs.size();j++)
		{
			int k=P[i].rhs[j].find(ch);
			///cout<<i<<" "<<j<<" "<<k<<"\n";
			if(k>=0 && k<P[i].rhs[j].length())
			{
				int considerlhs=0;
				if(k==P[i].rhs[j].length()-1)
				{
					considerlhs=1;
					//cout<<"considering lhs\n";
				}
				else
				{
						if(P[i].rhs[j][k+1]<'A' || P[i].rhs[j][k+1]>'Z')
						{
						//	cout<<"got a terminal"<<i<<" "<<j<<" "<<k<<"\n";
					        int index=Map[ch-'A'];
							P[index].follow.insert((P[i].rhs[j][k+1]));
							continue;
						}
					//	cout<<"going for nonterminal"<<i<<" "<<j<<" "<<k<<"\n";
						int index=Map[ch-'A'];
						int hasEpsilon;
				         	hasEpsilon=0;
							set<char > ::iterator it;
							//cout<<"\n\n"<<P[i].rhs[j].length()<<"\n\n";
							for(int x=k+1;x<P[i].rhs[j].length();x++)
							{
								int y=Map[P[i].rhs[j][x]-'A'];
							  for(it=P[y].first.begin();it!=P[y].first.end();it++)
						   	   {
							    	 if(*it=='~')//epsilon
									{
								 	 hasEpsilon=1;
								  	 continue;
									}
									P[index].follow.insert(*it);
								
							   }
							   if(x==P[i].rhs[j].length()-1 && hasEpsilon)considerlhs=1;
							   if(!hasEpsilon)break;
							   else hasEpsilon=0;
							
							}
							//if(hasEpsilon && k<P[i].rhs[j].length()-1)
							
//							{
//								//	P[i].rhs[j][++k]<<"\n"
//									int m=Map[P[i].rhs[j][++k]-'A'];
//								    k=m-1;
//								    	cout<<k<<" for T";
//								 	 
//								    ///	return 1;
//								    
//							    	continue;
//							}
//							else if(hasEpsilon)
//					        {
//							     	considerlhs=1;
//							     	break;
//						    }

						
	
				}
				if(considerlhs==1)
				{
					
					if(P[i].lhs!=ch)
					{
					//	cout<<"going in lhs\n";
						 getfollow(P[i].lhs);
						int index=Map[P[i].lhs-'A'];
						int ind=Map[ch-'A'];
						set<char > ::iterator it;
						for(it=P[index].follow.begin();it!=P[index].follow.end();it++)
						{
							P[ind].follow.insert(*it);
						}
					}
				}		
			}
		}
	}
	
}
struct XY
{
	char lhs;
	string rhs[NUM_TERM+1];
}*Table;

string First(string s)
{
	
	//cout<<s<<"   ";
	int len=s.length();
	string fst;
	int l=0;
	int flag=0;
	//cout<<len<<"\n";
	for(int i=0;i<len;i++)
	{
		if(s[i]<'A'||s[i]>'Z')
		{
			fst.push_back(s[i]);
			//fst[l++]=s[i];
		//	cout<<"fst is"<<fst<<"\n";
			return fst;
		}
		else
		{
			int index=Map[s[i]-'A'];
			set<char > :: iterator it;
			for(it=P[index].first.begin();it!=P[index].first.end();it++)
			{
				//cout<<*it;
				if(*it=='~')
				{
					flag=1;
					fst.push_back(*it);
					//fst[l++]='~';
					continue;
				}
				fst.push_back(*it);
				//fst[l++]=*it;
			}
			if(flag==0)
			{
				break;
			}
			else
			{
				flag=0;
			}
		}
	}
	//cout<<fst<<"\n";
	return fst;
}
int main(int argc, char const *argv[])
{
	
				Map['E'-'A']=0;
				Map['Z'-'A']=1;
				Map['T'-'A']=2;
				Map['Y'-'A']=3;
				Map['F'-'A']=4;
				tmap['+']=1;
				tmap['*']=2;
				tmap['a']=3;
				tmap['(']=4;
				tmap[')']=5;
				tmap['$']=0;
				P[0].rhs.push_back("TZ");P[0].lhs='E';
				P[1].rhs.push_back("+TZ");P[1].lhs='Z';
				P[1].rhs.push_back("~");
				P[2].rhs.push_back("FY");P[2].lhs='T';
				P[3].rhs.push_back("*FY");P[3].lhs='Y';
				P[3].rhs.push_back("~");
				P[4].rhs.push_back("a");P[4].lhs='F';
				P[4].rhs.push_back("(E)");//P[4].rhs.push_back("~");
				
				
				for(int i=0;i<P.size();i++)
				{
					cout<<P[i].lhs<<"->";
					for(int j=0;j<P[i].rhs.size();j++)
					{
						if(j!=0)cout<<"|";
						cout<<P[i].rhs[j];
//						for(int k=0;k<P[i].rhs[j].length();k++)
//						   {
//						   	if(P[i].rhs[j][k]<'A' && P[i].rhs[j][k])
//						   }
					}
					cout<<"\n";
				}	
				P[0].follow.insert('$');		
				for(int i=0;i<P.size();i++)
				{
						getfirst(P[i].lhs);
				}
			    for(int i=0;i<P.size();i++)
				{
						//cout<<"from for loop "<<i<<"\n";
					     getfollow(P[i].lhs) ;
//							set<char > ::iterator it;
//			   				cout<<i<<"\t"<<"follow of "<<P[i].lhs<<" is\t";
//			 		  	   for(it=P[i].follow.begin();it!=P[i].follow.end();it++)
//			   			     cout<<(*it)<<" ";
//				 		   cout<<"\n";
				}	
			   for(int i=0;i<P.size();i++)
			   {
			   		set<char > ::iterator it;
			   			cout<<i<<"\t"<<" first of "<<P[i].lhs<<" is\t";
			   	   for(it=P[i].first.begin();it!=P[i].first.end();it++)
			   	     cout<<(*it)<<" ";
				    cout<<"\n";
			   }
			   cout<<"\n\n\n";
			  for(int i=0;i<P.size();i++)
			   {
			   		set<char > ::iterator it;
			   		cout<<i<<"\t"<<"follow of "<<P[i].lhs<<" is\t";
			   	   for(it=P[i].follow.begin();it!=P[i].follow.end();it++)
			   	     cout<<(*it)<<" ";
				 cout<<"\n";
			   }
//			   map<char ,int >  ::iterator it;
//			   for(it=tmap.begin();it!=tmap.end();it++)
//			    cout<<(it->first)<<" "<<(it->second)<<"\n";
//			    cout<<"printed\n";
			    
				Table=new XY[NUM_VAR];
//				for(int i=0;i<NUM_VAR;i++)
//					Table[i]=new XY[NUM_TERM+1];
				
				
				for(int i=0;i<P.size();i++)
				{
					for(int j=0;j<P[i].rhs.size();j++)
					{
						string fst=First(P[i].rhs[j]);
					//	cout<<fst<<"  \n";
						for(int k=0;k<fst.length();k++)
						{
						//	cout<<i<<" "<<tmap[fst[k]]<<"   "<<fst[k]<<"\n";
							Table[i].lhs=P[i].lhs;
							Table[i].rhs[tmap[fst[k]]]=P[i].rhs[j];
//							Table[i][tmap[fst[k]]].lhs=P[i].lhs;//cout<<"lhs"<<Table[i][tmap[fst[k]]].lhs<<"\n";
//							Table[i][tmap[fst[k]]].rhs=P[i].rhs[j];//cout<<"rhs"<<Table[i][tmap[fst[k]]].rhs<<"\n";
						}
					}
				}
				cout<<"\n\n\nTable \n\n\n";
				for(int i=0;i<NUM_VAR;i++)
				{
					cout<<Table[i].lhs<<"      ";
					for(int j=0;j<NUM_TERM+1;j++)
					{
						
						cout<<setw(4)<<Table[i].rhs[j]<<"  ";
					}
					cout<<"\n";
				}	
//				
//				
//				for(int i=0;i<)	
//				

}

                                                                                                                                                               
