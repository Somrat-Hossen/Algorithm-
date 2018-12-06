#include <bits/stdc++.h>
#define mx 1000000

using namespace std;

vector<int>divisor[mx+1];
int i,j,n;

void prime_factor()
{
  for(i=2;i<=mx;i++)
   {
       if(divisor[i].size()==0)
       {
          for(j=i;j<=mx;j+=i)
          divisor[j].push_back(i);
       }
    }
}


int main()
{
  prime_factor();

     for(i=2;i<=100;i++)
     {
       cout<<i<<":";
       for(j=0;j<divisor[i].size();j++)
       {
         cout<<divisor[i][j]<<" ";
       }
       cout<<endl;
     }

     cin>>n;

    /* for(i=0;i<divisor[n].size();i++)
     {
        while(n%(divisor[n][i])==0)
        {
           cout<<divisor[n][i]<<" ";
           n/=divisor[n][i];
        }
     }
     */

    return 0;
}



