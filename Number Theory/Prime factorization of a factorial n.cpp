/*
This algo find out the prime factor upto n.
It works for <=10^5 in 1 sec.
complexity is nlogn.
we need prime number upto mx/2[it is enough.]
*/


#include<bits/stdc++.h>
#define mx 105
using namespace std;

vector<int>prime;
int Mark[mx+2];
int p_factor[mx];

void Sieve_prime()
{
  for(int i=4;i<=mx;i+=2) Mark[i]=1;
  for(int i=3;i*i<=mx;i+=2)
  {
    if(Mark[i]==0)
    {
       for(int j=i*i;j<=mx;j+=i*2)
       {
          Mark[j]=1;
       }
    }
  }
  for(int i=2;i<=mx;i++)
  {
     if(Mark[i]==0) prime.emplace_back(i);  /// Store all prime upto mx
  }

 /// for(int i=0;i<100;i++) cout<<prime[i]<<" ";
}

void Prime_factor(int n) ///prime factorizaton
{

  for(int i=2;i<=n;i++)
   {
       int x=i;

         for(int j=0;prime[j]*prime[j]<=x;j++)
         {
            while(x%prime[j]==0)
             {
                p_factor[prime[j]]++;  ///Vector is two dimensional
                x=x/prime[j];
             }

         }
     if(x>1) p_factor[x]++;  /// if x is prime

   }

  int cnt=0;

   for(int i=2;i<=n;i++)
   {
     if(cnt && p_factor[i]) printf(" * ");
     if(p_factor[i])
     {
       printf("%d (%d)",i,p_factor[i]);
       cnt=1;
     }

   }
   printf("\n");

}


int main()
{

  ///freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);


    int tc,n;

   Sieve_prime();  /// for prime


     scanf("%d",&n);
     //printf("Case %d: %d = ",cs,n);

     Prime_factor(n);  ///for prime factor






  return 0;
}

