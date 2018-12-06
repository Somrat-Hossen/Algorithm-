#include <bits/stdc++.h>
#define mx 1000000

using namespace std;

vector<int>divisor(mx+1,0);

 int n,i,j,m;

int main()
 {
     for(i=1;i<=mx;i++)
     {
         for(j=i;j<=mx;j+=i)
         {
             (divisor[j])++;
         }
     }

  cin>>m;


 for(i=1;i<=m;i++)
 {
     cout<<divisor[i]<<" ";
 }


    return 0;
  }


