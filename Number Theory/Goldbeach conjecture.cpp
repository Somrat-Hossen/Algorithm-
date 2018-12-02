/*
statement : every even number greater than 2 can be written as the sum of the two prime num.
Algorithm:
1.Make a prime list upto your big input .if num if prime then fill up with 0 else 1.
3.check whether the given num is n<=2 or odd then print false
2.make a loop untill your num (say n) then check whether i and n-ith prime array holds 1 or 0,if holds zero then print i and n-i.
*/

#include<bits/stdc++.h>
#define mx 1000000
using namespace std;

typedef unsigned long long ull;
bool prime[1000002];
ull n,m,i,j,res;
int tc;

void check_prime()
{
   for( i=4;i<=mx;i+=2)
   {
    prime[i]=1;///Initial generate upto 2-n
   }

    for(i=3;i*i<=mx;i+=2)
    {
      if(prime[i]==0)
      {
          for(j=i*i;j<=mx;j+=i)
          {
              prime[j]=1;
          }
      }
    }
}

int main()
 {
   check_prime();


  /*  for(int i=2;i<=n;i++)
    {
      if(prime[i]==0)
         {

            cout<<i<<" ";
         }
    }*/

    while(1)
    {
       puts("Give your input :");
       scanf("%lld",&n);res=0;

      if(n<=2 || (n & 1)) puts("Invalid input");

     else
      {
       for(int i=2;i<=n;i++)
       {
         if(prime[i]!=1 && prime[n-i]!=1)
          {
          cout<<i<<" "<<n-i<<endl;break;
          }
       }
     }
    }


     return 0;
 }

