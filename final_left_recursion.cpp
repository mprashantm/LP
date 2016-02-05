#include<iostream>
using namespace std;
#include<vector>
vector<string> vec;
string nw;
bool check(vector<string> vec,string exp,int index){
   
    nw=exp.substr(4);//cout<<nw<<" ";
    char s=exp[0];char temp=exp[3];
    if(exp.find(s)==3)
    return 1;
    
    
    
    
    else{
        for(int i=0;i<vec.size();i++){
            
            if(i!=index){
                
                if(vec[i].find(temp)==0){
                    nw=vec[i].substr(4)+nw;             
                    //cout<<nw<<" ";
                    temp=vec[i][3];
                    if(temp==exp[0]){
                        nw=temp+nw;
                      //  cout<<nw<<" ";
                        return 1;
                        }
                    }
                
                }
            }
        
        }
        return 0;
    }
 int num=4;   
int main(){
    //cout<<(int)('|');
    
   // char prod[3][20]={"A->BC|a","B->CD","C->AD"};
    vec.push_back("A->BC");vec.push_back("B->CD");
    vec.push_back("C->AD");vec.push_back("A->a");
    
    for(int i=0;i<vec.size();i++)
    {
         if(check(vec,vec[i],i)==1)
        {
           nw="->"+nw;
           //cout<<nw;
           nw=vec[i][0]+nw;
           cout<<nw<<" \n";
           vec[i][0]='.';
           vec.push_back(nw);
        }
        else
        cout<<vec[i]<<endl;
       
      
        
        nw="";
    }
    cout<<"\nproductions after removing left recursion\n";
    
    int size=vec.size();
    for(int i=0;i<size;i++)
    {
        if(vec[i][0]=='.')continue;
       // cout<<vec[i]<<"\n";
        if(vec[i][0]==vec[i][3])
        {
            //vec[i][3]='@';
           // vec[i][0]=(char)(num+65);
           // vec[i][vec[i].length()]=(char)(num+65);
           
            for(int j=0;j<size;j++)
            {
                if(j==i)continue;
                if((vec[i][0]==vec[j][0]) && vec[j][0]!='.' && vec[i][0]!='.')
                {
                    vec.push_back("A4->"+vec[i].substr(4)+'A'+(char)(num+48));
                    vec.push_back("A->a"+vec[j].substr(4)+'A'+(char)(num+48));
                    vec[j][0]='.';
                }
            }
            vec[i][0]='.';
        }
        
    }
    cout<<"\n";
    for(int i=0;i<vec.size();i++)
    {   if(vec[i][0]!='.')
     cout<<vec[i]<<"\n";
}
    
    
    
    
    
    system("pause");
    
    
    
}
