#include<bits/stdc++.h>
using namespace std;
bool vis[1000];
queue<int>que;



int main()
{
    freopen("in.txt","r",stdin);
    int node,edge,u,v,s,f,i,j,src;

    puts("Enter the number of vertex and edge:");
    cin>>node>>edge;
    vector<int>vec[node+5];
    for(i=1;i<=edge;i++)
    {
      cin>>u>>v;
      vec[u].push_back(v);//i does not matter whether start from 1 or 0
      vec[v].push_back(u);
    }
    for(i=1;i<=node;i++)
    {
        cout<<i<<" : ";
        for(j=0;j<(int)vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
     puts("Give your desirous source:");
    cin>>src;
    que.push(src);

  cout<<endl<<"Graph Traversal are : ";
    while(!que.empty())
    {
        f=que.front(); que.pop();
        if(vis[f]==0)
        {
            cout<<f<<" "; vis[f]=1;
            for(j=0;j<(int)vec[f].size();j++)
            {
                s=vec[f][j];
                if(vis[s]==0)
                {
                    que.push(s);
                }
            }
        }
    }
    return 0;

}
