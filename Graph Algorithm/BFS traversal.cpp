#include<bits/stdc++.h>
using namespace std;

int u,e,nd,i,j,f,s,src,x,y;
vector<int>v[100];
int vis[100],cost[100];
queue<int> q;

void traversal(int src)
{
    q.push(src);
    vis[src]=1;

    while(!q.empty())
    {
        f=q.front();
        q.pop();
        cout<<f<<" "; ///print node during traversal.

        for(i=0;i<v[f].size();i++)
        {
            s=v[f][i];
            if(vis[s]==0)
            {
                q.push(s);
                vis[s]=1;
            }
         }
     }
}


int main()
{
  freopen("in.txt","r",stdin);

 cout<<"Enter node and vertices "<<endl;
  cin>>nd>>e;

  for(i=0;i<e;i++)
  {
      cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
    
  puts("Adjacency list:");
  for(int i=1;i<=nd;i++)
  {
    cout<<i<<" : ";
    for(int j=0;j<(int)v[i].size();j++)
    {
    cout<<v[i][j]<<" "; ///Adjacency list of graph print
    }
    cout<<endl;
  }
  cout<<endl;

  cout<<"Enter  src vertix :"<<endl;
   cin>>src;
  cout<<"Traversal are: ";

  traversal(src); ///Function call

    return 0;
}

