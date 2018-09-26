#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
int p[10000000];
int divisor[1000000];
bool a[100000000000];

int main()
{
    int n,m,c=0,i,x,res=0,j=0;
    cin>>n;
    m=n;

    for(i=2;i*i<=n;i++)
    {
      if(!a[i])
      {
          for(j=i*i;j<=n;j+=i)
          {
              a[j]=1;
          }
      }
    }
    j=0;
    for(i=2;i<=n;i++)
    {
        if(!a[i])
        {
            p[++j]=i; ////prime num store.
          //  cout<<i<<" ";
        }
    }
    divisor[++c]=1; /// first divisor is one
   for(i=1;i*i<=j;i++)
   {
    while(n%p[i]==0 && n)
    {
     divisor[++c]=p[i];
     n/=p[i];
    }
   }
   if(n>2) divisor[++c]=n; 
    
   cout<<"Divisor of "<<m<<" is: ";

   
   for(i=1;i<=c;i++)
    {
     cout<<divisor[i]<<" ";
    }

    return 0;
}



