#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    string exp;
    vector<int> num;
    vector<char> optr;
    vector<int>::iterator iit;
     vector<char>::iterator cit;

    int x,y,a,i,b;
    getline(cin,exp);
    for(i=0;i<exp.size();i++)
    {
        x=0;
        if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' )
            {
                optr.push_back(exp[i]);
            }
        else if(exp[i]==' ') continue;

        else
           {
            while(exp[i]>='0' && exp[i]<='9')
            {
                int bit=exp[i]-'0';
                //cout<<bit<<endl;
                x=x*10+bit;
                i++;
            }
             num.push_back(x);
           }
    }
    for(iit=num.begin();iit!=num.end();iit++)
    {
        cout<<*iit<<" ";
    }
  cout<<endl;
  for(cit=optr.begin();cit!=optr.end();cit++)
    {
        cout<<*cit<<" ";
    }

    if(*cit=='*') puts("Multi"); /// cit and value check.
    else puts("Not");
    return 0;
}

