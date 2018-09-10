#include<bits/stdc++.h>

using namespace std;
int prime[100000000],arr[10000000],nprime[10000000];

int main()
{
    int n,m=0,cnt=0,i,x=0,res=0,tc,a,b,j;

    cin>>a>>b;
    for(i=4;i*i<=b;i+=2)
    {
        arr[i]=1;
    }
    for(i=3;i*i<=b;i+=2)
    {
      if(arr[i]==0)
      {
          for(j=2*i;j*j<=b;j+=i)
          {
              arr[j]=1;
          }
      }
    }

    for(i=2;i*i<=b;i++)
    {
       if(arr[i]==0)
       {
          // cout<<i<<" ";
           prime[++x]=i;

       }
    }

    for(i=a;i<=b;i++)
    {
        nprime[i]=i;
    }
    for(i=1;i<=x;i++)
    {
        if(nprime[i]!=-1)
        {
            for(j=a;j<=b;j++)
            {
                if(nprime[j]%prime[i]==0)
                {
                    nprime[j]=-1;
                }
            }
        }
    }

  for(i=a;i<=b;i++)
  {
      if(nprime[i]!=-1)
      {
          cout<<nprime[i]<<" ";
      }
  }


    return 0;
}




