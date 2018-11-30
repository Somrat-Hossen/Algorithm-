#include<bits/stdc++.h>
#define mx 10000000
using namespace std;

typedef long long ll;

bool prime[mx+2];
ll sum[mx+2];
int n,i,j,x,y;

void check_prime()
{
  sum[2]=2;

  for(i=2;i<=mx;i+=2)
  {
      prime[i]=true;
  }

  for(i=3;i<=mx;i++)
  {
     if(prime[i]==0)
     {
       sum[i]=sum[i-1]+i;
       for(j=2*i;j<=mx;j+=i)
       {
         prime[j]=true;
       }
     }
     else {sum[i]=sum[i-1];}
  }

}

int main()
{

  check_prime();

  cin>>n;

  for(i=2;i<=n;i++)
  {
    cout<<sum[i]<<" ";
  }


 return 0;
}
