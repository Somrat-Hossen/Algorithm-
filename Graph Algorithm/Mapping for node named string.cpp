#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int n,e,i,u,v,w;
int indeg[mx];
vector<int>edge[mx];
queue<int>que;

map<string ,int>mps;
map<int ,string >mpi;





int main()
{
   freopen("in.txt","r",stdin);

   cin>>n>>e;

   ///Without mapping
  /* for(int i=0;i<e;i++)
   {
      cin>>u>>v;
      indeg[v]++;
      edge[u].push_back(v);
   }
   Topological(n);

   for(int i=0;i<path.size();i++)
   {
      cout<<path[i]<<" "<<endl;
   }*/

   int cnt=0;///node will be mapped from 1
   int u,v;
   string s1,s2;

   for(int i=1;i<=e;i++)
   {
      cin>>s1>>s2;
      if(mps.find(s1)!=mps.end())
      {
         u=mps[s1];
         mpi[u]=s1;///If we want to print the path,so int hold string
      }
      else
      {
         mps[s1]= ++cnt;
         u=cnt;
          mpi[u]=s1;
      }

      if(mps.find(s2)!=mps.end())
      {
         v=mps[s2];
          mpi[v]=s2;

      }
      else
      {
         mps[s2]=++cnt;
         v=cnt;
          mpi[v]=s2;
      }

      indeg[v]++;           ///count indegree of each node
      edge[u].push_back(v);     ///Directed graph
   }

  /// for(int i=1;i<=n;i++) cout<<indeg[i]<<" "; ///print indegree
  /// cout<<endl;

   for(int i=1;i<=n;i++)
   {
      cout<<i<<": ";
      for(int j=0;j<edge[i].size();j++)
      {
         cout<<edge[i][j] <<" ";  /// if we want to print the original string then print mpi[edge[i][j]].
      }
      cout<<endl;
   }




   return 0;
}

