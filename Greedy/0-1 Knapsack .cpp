#include<bits/stdc++.h>

using namespace std;

 pair<int,int> pi[1000];
 int i,n,w,res=0,weight,price;

int main()
{
    freopen("in.txt","r",stdin);

    puts("Enter the number and weight");
    cin>>n>>w; ///n is num or item

    for(i=0;i<n;i++)
    {
       cin>>weight>>price;
       pi[i].first=price;
       pi[i].second=weight;
    }

    sort(pi,pi+n); ///Ascending order.

    for(i=n-1;i>=0&& w>0; i--) ///Read data in descending order while the weight is greater than 0
    {
      int x=min(w,pi[i].second);///when weight is 0 then loop end.
      w-=x;
      res+=pi[i].first;
    }
    cout<<"Max profit:"<<res<<endl;

    /*for(i=n-1;i>=0;i--)
    {
      cout<<pi[i].first<<" "<<pi[i].second<<endl;
    }*/

    return 0;
}


