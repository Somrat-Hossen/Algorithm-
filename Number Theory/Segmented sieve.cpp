#include<bits/stdc++.h>
#define maxx 1000000000
#define mx 32000   ///we need to find prime upto sqrt b/r
using namespace std;
typedef long long ll;

bool prime[mx+1];
int isprime[mx];


ll l,r,i,current,sq,j,pos=0;

void sieve()
{
  sq=sqrt(mx)+1;
  for(i=4;i<=mx;i+=2){prime[i]=true;}

  for(i=3;i<=mx;i+=2)
  {
    if(prime[i]==0)
    {
      isprime[++pos]=i;

      if(i<=sq)
      {
        for(j=i*i;j<=mx;j+=i)
        {
          prime[j]=true;
        }
      }
    }

  }
  isprime[0]=2;
}

void segmented_sieve(ll l,ll r) /// left and right range.
{
  bool seg_prime[r-l+1];

  for(i=0;i<r-l+1;i++){seg_prime[i]=false;}  /// false means initially prime
  if(l==1) seg_prime[0]=1;

  for(i=0;isprime[i]*isprime[i]<=r;i++)   /// prime upto sqrt of r
  {
    current=isprime[i];            /// current prime num
    ll start=(l/current)*current;  /// start cutting from the range start. such l=20 the 20/2*2=20 ,
    if(start<l) start+=current;    ///from 20 cutting will be start. 2 is first prime

    for(j=start;j<=r;j+=current){seg_prime[j-l]=true;}
    if(start==current){seg_prime[start-l]=false;}

  }

  for(i=0;i<r-l+1;i++)
  {
    if(seg_prime[i]==false)
    {
    cout<<l+i<<" ";
    }
  }

}


int main()
{

 sieve();
/*for(i=0;i<30;i++)
{
  cout<<isprime[i]<<" ";
}*/

cin>>l>>r;
segmented_sieve(l,r);


 return 0;
}




