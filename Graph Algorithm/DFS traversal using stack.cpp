#include<bits/stdc++.h>
#include<iomanip>
#define PI acos(-1)
int vis[100];
using namespace std;
stack<int>stk;
vector<int>vec[100];

 void dfs(int src)
  {
     stk.push(src);
     vis[src]=1;
     cout<<src<<" ";

   while(!stk.empty())
   {
     int u=stk.top();stk.pop();
     for(int i=0;i<vec[u].size();i++)
     {
         int f=vec[u][i];
         if(vis[f]==0)
         {cout<<f<<" ";
           stk.push(u);  ///FIRST parrent push then chile
           stk.push(f);
           vis[f]=1;
          break;
         }
      }
    }
  }


int main()
{
  /// freopen("in.txt","r",stdin);
   int u,v,edg,ver,src;
   cin>>edg;
  for(int i=0;i<edg;i++)
  {
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  cin>>src;

  dfs(src);

    return 0;
}



