#include<bits/stdc++.h>
#define pb push_back
using namespace std;

char vis[1000];
vector<int>path;
vector<int>Adj[1000];
int pa[1000],dist[1000];
queue<int> q;
int Findcolor(int src)
{
    q.push(src); vis[src]='r';
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0,len = Adj[u].size();i<len;i++)
        {
            int f = Adj[u][i];
            if(vis[f]!='r' && vis[f]!='b')
            {
                if(vis[u]=='r')//check parrent's color.child color must inverse of parrent
                    vis[f]='b';
                else
                    vis[f]='r';

                q.push(f);   //it works for both if or else  statement
            }
            else
             {
                if(vis[f]==vis[u])//if child and parrent color are same.then .....
                    return 0;
             }
        }
    }
    return 1;
 }
int main()
{  // freopen("in.txt","r",stdin);
    int edge,u,v,res,src,d;
    cin>>edge;

    for(int i=0;i<edge;i++)
     {
        cin>>u>>v;
        Adj[u].pb(v);
        Adj[v].pb(u);
     }
    cin>>src;
    res=Findcolor(src);
    if(res==0)
        cout<<"Not BIColorable or Not Bipartite "<<endl;
    else
        cout<<"biColorable or Bipartite"<<endl;

    return 0;
}

