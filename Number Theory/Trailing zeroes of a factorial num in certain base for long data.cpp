#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tmp;
ll n,base;

ll Count(ll n,ll j)
{
    ll anss=0;

    while(j<=n)
    {
      anss+=n/j;
      n/=j;
    }
   return anss;
}


ll count_zero(ll n,ll b)
{
  /// at first made prime factorization of base b.if one factor occurences more than one the divide the res by occurence num. res will get from the
  /// las while(n/>0){ res+=n/i;i*=i; }look at the topics on how to find trailing zero of a factorial n. At last take the min.because we count 5 in our
  /// 10 base factorial.2 was more than 5.thus think a little bit.

	ll cnt,res=1e18+5,y,ans;

     y=b;

   for(ll i = 2; i*i<= b; i++)
   {
		cnt = 0;
       if(b%i==0)
       {
		 while(b % i == 0)
		  {
			cnt++;
			b /= i;
		  }

          ans=Count(n,i);
		  res=min(res,ans/cnt); /// if one prime occur several times,so ans/cnt
		}
	}

	if(b>1)         /// i*i so if n is prime then it will not be zero
	{
		ans=Count(n,b);
        res=min(res,ans);
	}

	return res;
}

int main()
{

   cin>>n>>base;

   ll zero;
   zero=count_zero(n,base);

   cout<<zero<<endl;

 return 0;
}

