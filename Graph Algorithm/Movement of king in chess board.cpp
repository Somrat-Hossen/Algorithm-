#include<bits/stdc++.h>
using namespace std;

bool check(int r,int c)
{
   if((r>=1 && r<=8) && (c>=1 && c<=8)) return 1;
   else return 0;
}

int main()
{

   int x,y,tc,a,b,res=0;
   char pos[3];
   cin>>pos;
   x=pos[1]-'0'; y=(pos[0]-'a')+1;
  // cout<<x<<" "<<y<<endl;

   if(check(x,y-1))  res++;
   if(check(x,y+1))  res++;
   if(check(x+1,y))  res++;
   if(check(x-1,y))  res++;
   if(check(x-1,y+1))  res++;
   if(check(x-1,y-1))  res++;
   if(check(x+1,y-1))  res++;
   if(check(x+1,y+1))  res++;

   cout<<res<<endl;

    return 0;
}

