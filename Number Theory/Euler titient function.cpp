#include<bits/stdc++.h>
#define mx 100000000
using namespace std;

int mark[mx+1],phi[mx+2];

void Euler_totient(int n)
{
  int i,j;
  for(i=1;i<=n;i++){phi[i]=i;}

  phi[1]=1;
  mark[1]=1;

  for(i=2;i<=n;i++)
  {
    if(!mark[i])
    {
      for(j=i;j<=n;j+=i)
      {
        mark[j]=1;
        phi[j]=(phi[j]/i)*(i-1);

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
