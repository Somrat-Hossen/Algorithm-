#include<bits/stdc++.h>
using namespace std;
vector<int>vec[1000];

bool vis[1000];
vector<int>path;
vector<int>Adj[1000];
map<string,int>mp;
map<int,string>i_mp;
int pPre[1000],dist[1000];

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
            int f= Adj[u][i];
            if(vis[f]==0)
            {
                q.push(f);
                vis[f]  = 1;
                pPre[f] = u; //We came node "uA' from the node u
                dist[f] = dist[u]+1;/*Distance of "uA" from the starting node "src" is :
                 Distance of previous node of "uA" + 1 */
            }
        }
    }
    if(vis[des]==0)
       return -1;

    int nDes = des;
    path.push_back(des);
    while(nDes !=src)
    {
        nDes = pPre[nDes];
        path.push_back(nDes);
    }
    reverse(path.begin(),path.end());
    cout<<"Direction is : ";
    for(int i=0,len = (int)path.size();i<len;i++)
    {
     cout<<i_mp[path[i]]<<" ";
    }

    cout<<endl;
    path.clear();
    return dist[des];
}


int main()
{
   // freopen("in.txt","r",stdin);
    int nN=0,e,n,cnt=1;
    cin>>e;
    string u,v,src,des;
    for(int i=0;i<e;i++)
     {
        cin>>u>>v;
        if(mp.find(u)==mp.end())///if the desired name could not be found it goes to the end  and return last address
         {
            mp[u] = cnt; /// inside string hold int
            i_mp[cnt++] = u;///inside int hold string
         }
        if(mp.find(v)==mp.end())
         {
            mp[v] = cnt;
            i_mp[cnt++] = v;
         }
        Adj[mp[v]].push_back(mp[u]);
        Adj[mp[u]].push_back(mp[v]);
    }
    /// For readable Display

    cin>>src>>des;
    int res=findSpath(mp[src],mp[des]);
    cout<<"Distance is: "<<res<<endl;

    return 0;
}



