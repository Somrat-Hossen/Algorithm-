#include<bits/stdc++.h>
#define mx 1000000
using namespace std;

typedef unsigned long long ull;
bool prime[1000002];
ull n,m,i,j,res;
int tc;

void check_prime()
{
   for( i=4;i<=1000000;i+=2)
   {
    prime[i]=1;///Initial generate upto 2-n
   }

    for(i=3;i*i<=1000000;i+=2)
    {
      if(prime[i]==0)
      {
          for(j=i*i;j<=1000000;j+=i)
          {
              prime[j]=1;
          }
      }
    }
}

int main()
 {
  check_prime();

    scanf("%lld",&n);res=0;

    for(int i=2;i<=n;i++)
    {
      if(prime[i]==0)
         {

            cout<<i<<" ";
         }
    }

     return 0;
 }



