#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;
int p[10000000];
int di[1000000];
bool a[100000000000];

int main()
{
    ll n,m,c=0,i,x,res=0,j=0;
    set<int>st;
    set<int>::iterator it;

  cin>>n;

    for(i=1;i*i<=n;i++)
    {
     if(n%i==0)
     {
         st.insert(i);
         st.insert(n/i);
     }
    }
  cout<<"Divisor are: ";

    for(it=st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }

    return 0;
}




