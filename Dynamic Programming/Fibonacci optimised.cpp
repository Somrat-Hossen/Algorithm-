#include<bits/stdc++.h>

using namespace std;
unsigned typedef long long ull;
ull table[1000],n;

 ull fibo(int n)
 {
     if(n==1 || n==2) return table[n];
     else if(table[n]!=0) return table[n];
     else
     {
         table[n]=fibo(n-1)+fibo(n-2);
         return table[n];
     }
 }

int main()
{
    table[1]=0;
    table[2]=1;
    string st;

   while( cin>>n)
   {
    if(n==1) st="st";
     else  if(n==2) st="nd";
     else  if(n==3) st="rd";
     else  st="th";

    cout<<n<<st<<" Fibonacci is: "<<fibo(n)<<endl;
   }
    return 0;
}
