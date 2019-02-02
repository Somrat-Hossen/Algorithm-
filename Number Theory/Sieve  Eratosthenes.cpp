#include <bits/stdc++.h>
#define mx 1000000


using namespace std;

typedef  long long int ll;

ll num,sq,x,i,j,cnt,len,p,n;
bool check[mx+1];
vector<ll> prime;

void prime_test()
{
  prime.push_back(2);
   p=sqrt(mx)+1;

 for(i=4;i<=mx;i+=2)///All even except 3 are marked.
  {
     check[i]=1;
  }
    for(int i=3;i<=mx;i+=2)///same sqrt(n)==i*i
    {
      if(check[i]==0)
      {
          prime.push_back(i); ///i means prime
          if(i<=p)  ///there is no divisor after sqrt n
          {
            for(int j=i*i;j<=mx;j+=i*2)
           {
              check[j]=1; ///0 means not prime
           }
          }
      }
    }
}



int main()
{
  prime_test();

 cin>>n;

  for(i=0;i<n;i++)
  {
    cout<<prime[i]<<" ";
  }

    return 0;
}


