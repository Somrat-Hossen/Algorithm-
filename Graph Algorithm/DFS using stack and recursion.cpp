#include<bits/stdc++.h>
using namespace std;

int vis[1000];
vector<int>vec[1000];

void DFS(int src)
{
   if(vis[src]) return ;
   vis[src]=1;
   cout<<src<<endl;


   for(int i=0;i<vec[src].size();i++)
   {
      int f=vec[src][i];
      if(vis[f]==0)
      {
         DFS(f);
      }

   }


}


stack<int>stk;
void DFS_stack(int src)
{
   stk.push(src);
   vis[src]=1;
      cout<<src<<" ";

   while(!stk.empty())
   {
      int p=stk.top();stk.pop();

      for(int i=0;i<vec[p].size();i++)
      {
         int child=vec[p][i];
         if(vis[child]==0)
         {
            cout<<child<<" ";
           vis[child]=1;
           stk.push(p);
           stk.push(child);
           break;
         }
      }





   }




}

int main()
{
 int node,edge;

 cin>>node>>edge;

 for(int i=0;i<edge;i++)
 {

   int u,v;
   cin>>u>>v;
   vec[v].push_back(u);
   vec[u].push_back(v);
 }

 for(int i=1;i<=node;i++)
 {
    cout<<i<<":";
    for(int j=0;j<vec[i].size();j++)
    {
      cout<<vec[i][j]<<" ";
    }
    cout<<endl;
 }

  ///DFS(1);
  DFS_stack(1);

}
