#include <bits/stdc++.h>
#include <stdlib.h>
#include<iomanip>

using namespace std;

vector<int>pri_div[10000005];
int sml_prm_factor[10000005];

 int n,i,j,m;

 void smallest_prime_factor(int n)
 {
      sml_prm_factor[1]=1;
     for(i=2;i<=n;i+=2)
     {
        sml_prm_factor[i]=2;
     }
     for(i=3;i<=n;i+=2)
     {
        sml_prm_factor[i]=i;
     }

      for(i=3;i<=n;i+=2)
     {
         for(j=i*i;j<=n;j+=i)
         {
          if(sml_prm_factor[j]==j)
          {
            sml_prm_factor[j]=i;
          }
         }
     }
 }

int main()
 {
     cin>>n;

  smallest_prime_factor(n);///Function calling
                           ///Generate smallest one prime factor of each number up to n.

    /* for(i=1;i<=n;i++)
      {
        cout<<sml_prm_factor[i]<<" ";   ///one Smallest prime factor for each number up to n.
      }
      */

  for(i=1;i<=n;i++)
  {
      int x=i;
      while(x!=1)
      {
        pri_div[i].push_back(sml_prm_factor[x]);
        x/=sml_prm_factor[x];
      }
  }

      ///ALL prime factor from 1 to n

      /* for(i=2;i<=n;i++)
        {
          cout<<i<<" : ";
          for(j=0;j<pri_div[i].size();j++)
          {
              cout<<pri_div[i][j]<<" ";
          }
          cout<<endl;
      }
      */
     ///

     puts("Enter number to see it's divisor.");

     cin>>m;
     for(i=0;i<pri_div[m].size();i++)
     {
        cout<<pri_div[m][i]<<" "; ///Print all divisor of specific number.
     }



    return 0;
  }


