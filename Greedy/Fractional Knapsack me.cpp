#include<bits/stdc++.h>

using namespace std;

pair<int,int> pi[1000];
int i,n,w,res=0,weight,price;

int main()
{
    freopen("in.txt","r",stdin);



    puts("Enter the number and weight");
    cin>>n>>w;

    for(i=0;i<n;i++)
    {
       cin>>weight>>price;
       pi[i].first=price/weight;
       pi[i].second=weight;
    }

    sort(pi,pi+n);//Ascending order.

    for(i=n-1;i>=0;i--)///Read data in descending order
    {
      int x=min(w,pi[i].second);
      w-=x;
      res+=x*pi[i].first;
    }
    cout<<"Max profit:"<<res<<endl;

    /*for(i=n-1;i>=0;i--)
    {
      cout<<pi[i].first<<" "<<pi[i].second<<endl;
    }*/

    return 0;
}

