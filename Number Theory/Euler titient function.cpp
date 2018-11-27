#include<bits/stdc++.h>
#define mx 100000000
using namespace std;

int phi[mx+2];

void Euler_totient(int n)
{
  int i,j;
  for(i=1;i<=n;i++){phi[i]=i;}

  for(i=2;i<=n;i++)
  {
    if(phi[i]==i)  /// i is a prime
    {
      for(j=i;j<=n;j+=i)
      {
       /// phi[j]=(phi[j]/i)*(i-1);
        phi[j] -= phi[j] / i;
      }
    }
  }

}


int main()
{
  int n;
  cin>>n;
  Euler_totient(n);

   for(int i=1;i<=n;i++)
   {
     cout<<i<<": "<<phi[i]<<endl;
   }
}
