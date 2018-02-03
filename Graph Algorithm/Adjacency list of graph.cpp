#include<bits/stdc++.h>
#include<iomanip>
#define PI acos(-1)
bool visited[1000];

using namespace std;

int main()
{
   //freopen("int.txt","r",stdin);
   queue<int>que;

   int u,v,edg,ver,src;//node means edge

  cout<<"Enter node and vertices "<<endl;
  cin >>ver>>edg;
  vector<int>vec[ver+1];
  for(int i=0;i<edg;i++)
  {
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for(int i=1;i<=ver;i++)
  {
    cout<<i<<" : ";
    for(int j=0;j<(int)vec[i].size();j++)
    {
    cout<<vec[i][j]<<" ";
    }
    cout<<endl;
  }
  
    return 0;
}
