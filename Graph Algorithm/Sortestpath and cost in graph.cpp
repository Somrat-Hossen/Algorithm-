#include<bits/stdc++.h>
#define pb push_back
using namespace std;

bool vis[1000];
vector<int>path;
vector<int>Adj[1000];
int pa[1000],dist[1000];

int findSpath(int src,int des)
{
    queue<int> q;
    //For one source. If there are many source then push all of them.
    q.push(src); vis[src]=1; dist[src]=0;
    while(!q.empty())
        {
        int u = q.front();
        q.pop();
        for(int i=0,len = Adj[u].size();i<len;i++)
        {
            int f = Adj[u][i];
            if(vis[f]==0)
            {

                q.push(f);
                vis[f]  = 1;
                pa[f] = u; //we have store parrent by sequence
                dist[f] = dist[u]+1;/*Distance of f from the starting node "src" is :
                Distance of previous node of u + 1 */
            }
        }
    }
    if(vis[des]==0)
    return -1;
    int nDes = des;
    path.push_back(des);
    while(nDes !=src)
    {
        nDes = pa[nDes];
        path.push_back(nDes);
    }
    reverse(path.begin(),path.end());
    for(int i=0,len = (int)path.size();i<len;i++)
    cout<<path[i]<<" ";
    cout<<endl;
    path.clear();
    return dist[des];
}
int main()
{   //freopen("in.txt","r",stdin);
    int edge, u, v,re,s,d;
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        Adj[u].pb(v);
        Adj[v].pb(u);
    }
    cin>>s>>d;
    re = findSpath(s,d);
    if(re==-1)
        cout<<"There are not any path"<<endl;
    else
        cout<<"The Minimum cost is : "<<re<<endl;
    return 0;
}
