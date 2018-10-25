#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[10000][10000];
ll n,r,p=1000007;
ll find_ncr(ll n,ll r)
{
   if(r==0 || n==r) return 1;
   else if(r==1 ) return  n;
   else if(dp[n][r]!=0) return ((dp[n][r])%p);
   else
   {
       dp[n][r]=find_ncr(n-1,r)%p +find_ncr(n-1,r-1)%p;
       return dp[n][r]%p;
   }
}

int main()
{

    cin>>n>>r;

    cout<<"ncr % p = "<<find_ncr(n,r)<<endl;
}

