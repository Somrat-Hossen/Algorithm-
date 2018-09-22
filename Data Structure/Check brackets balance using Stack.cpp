#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int i,len;
char st[1000];
stack<char>stk;

int check(char st[])
{
 for(i=0,len=strlen(st);i<len;i++)
  {
      if(st[i]=='(' || st[i]=='{')
        {
            stk.push(st[i]);
        }
        else
        {
         if(stk.empty()) {return 0;}
         else if(st[i]==')' && stk.top()!='(') {return 0;}
         else if(st[i]=='}' && stk.top()!='{') { return 0;}
         else if(st[i]=='}' && stk.top()=='{') {stk.pop();}
         else if(st[i]==')' && stk.top()=='(') {stk.pop();}
        }
  }
  if(!stk.empty()) return 0;
  else return 1;

}

int main()
{
  freopen("in.txt","r",stdin);
  cin>>st;
  int  x=check(st);

 if(x) puts("Balanced.");
 else  puts("Not Balanced.");

 return 0;
}







