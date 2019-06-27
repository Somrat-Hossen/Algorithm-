#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int n,e,i,u,v,w;
int indeg[mx],outdeg[mx];
vector<int>edge[mx];
queue<int>que;
vector<int>path;




int main()
{
   freopen("in.txt","r",stdin);

   cin>>n>>e;


   for(int i=0;i<e;i++)
   {
      cin>>u>>v;
      indeg[v]++;           ///indegree
      outdeg[u]++;           ///outdegree
      edge[u].push_back(v);  ///Directed graph
   }


   cout<<"Indegree of each node is: "<<endl;
   for(int i=1;i<=n;i++)
   {
      cout<<i<<": "<<indeg[i]<<endl;
   }

   cout<<"outdegree of each node is: "<<endl;
   for(int i=1;i<=n;i++)
   {
      cout<<i<<" : "<<outdeg[i]<<endl;
   }


   return 0;
}
