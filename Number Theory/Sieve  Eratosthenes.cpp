#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
 {

  int n,m;
  printf("Enter the limit for check prime :\n");
  cin>>n;

  int p=sqrt(n)+1;
  int prime[n+2];
  int check[n];
  int cnt=1;



    for(int i=4;i<=n;i+=2)///All even except 3 are marked.
    {
     prime[i]=0;
    }
    for(int i=3;i<=n;i+=2)///same sqrt(n)==i*i
    {
      if(prime[i]!=0)
      {
          check[++cnt]=i; ///i means prime
          if(i<=p)  ///there is no divisor after sqrt n
          {
           for(int j=i*2;j<=n;j+=i)
           {
              prime[j]=0; ///0 means not prime
           }
          }
      }
    }
    check[1]=2;

 cout<<"Prime series is :";

 for(int i=1;i<=cnt;i++)
   {
     cout<<check[i]<<" ";
   }

   cout<<endl<<"Enter any number to check whether it is prime or not:";
   cin>>m;

   if(prime[m])
         printf("%d is a prime number",m);
    else
         printf("%d is not a prime number",m);

     return 0;
 }


