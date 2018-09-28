#include <bits/stdc++.h>
#include <stdlib.h>
#include<iomanip>

using namespace std;

vector<int>divisor[10000005];

 int n,i,j,m;

int main()
 {
     cin>>n;

     for(i=1;i<=n;i++)
     {
         for(j=i;j<=n;j+=i)
         {
             divisor[j].push_back(i);
         }
     }

   /*  for(i=1;i<=n;i++) ///Total divisor up to n.
     {
         cout<<i<<" : ";
         for(j=0;j<(int)divisor[i].size();j++)
         {
             cout<<divisor[i][j]<<" ";
         }
         cout<<endl;
     }
     */

     puts("Give input which number divisor needed:");
     cin>>m;


     for(i=0;i<divisor[m].size();i++)   ///Specific number divisor.
     {
         cout<<divisor[m][i]<<" ";
     }


    return 0;
  }

