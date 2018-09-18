#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii>vec;

bool cmp(pii a,pii b)
{
    return ((a.second*b.first)>(a.first*b.second));///first=weight,second=price
}

int main()
{
    freopen("in.txt","r",stdin);
    int i,n,w,res=0,weight,price;
    puts("Enter the number and weight");
    cin>>n>>w;
    for(i=0;i<n;i++)
    {
       cin>>weight>>price;
       vec.push_back(pii(weight,price));
    }
    sort(vec.begin(),vec.end(),cmp);
    for(i=0;i<n;i++)
    {
      int x=min(w,vec[i].first);
      w-=x;
      res+=x*vec[i].second;
    }
    cout<<endl<<"Maximum sum is:"<<res<<endl;

    return 0;
}
