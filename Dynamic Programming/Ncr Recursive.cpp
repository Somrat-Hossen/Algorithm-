#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;


 int table[20][20];ll n,r;
/*ll ncr(ll n,ll r)
{
  if(r==0 || n==r)return 1;
  if(r==1)return n;
  return ncr(n-1,r)+ncr(n-1,r-1);
}*/
ll nCr(ll n,ll r)
{
   if(r==1) return n;
    if (n==r) return 1;
    if (table[n][r] != 0)  return table[n][r];
  else
   {
      table[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
      return table[n][r];
  }
}



int main()
{

 cin>>n>>r;
 //memset(table,0,sizeof(table[0][0])*20*20);
 cout<<nCr(n,r);
 return 0;
}
