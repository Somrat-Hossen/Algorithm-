#include<bits/stdc++.h>
#define mx 100000
using namespace std;

typedef pair <int,int >pr;
int dis[mx];
vector<pr>edge[mx];
const int infinity =1000000000;
int vis[mx];


class data
{
  public:
  int node, cost;

  data(int n,int c)
  {
     node=n;
     cost=c;
  }
  bool operator >(const data &a)const {
        return cost > a.cost;///Without this two lines gives compilation error
    }
};

bool operator< (data a, data b)
{
    return a.cost > b.cost;
}

void Dijkstra(int src)
{
   priority_queue<data> q;

   for (int i = 0; i < mx; i++) dis[i] = infinity;

   q.push(data(src,0));
   dis[src] = 0;

while(!q.empty())
{
     data u = q.top();
     q.pop();
     vis[u.node]=1;

    for (int i = 0; i < edge[u.node].size(); i++)
    {
       int v = edge[u.node][i].first;
       int wet = edge[u.node][i].second+dis[u.node];

      if(dis[v] > wet && !vis[v])
      {
         dis[v] = wet;
         q.push(data(v,dis[v]));
      }
    }
}

  for(int i=1;i<=4;i++) cout<<i<<" :"<<dis[i]<<endl;
}


int main()
{

  //freopen("in.txt","r",stdin);
  int n,e,i,j,u,v,wet,src;

  cin>>n>>e;

  for(int i=0;i<e;i++)
  {
     cin>>u>>v>>wet;
    edge[u].push_back(make_pair(v,wet));
  }

  cin>>src;

  Dijkstra(src);




  return 0;
}

