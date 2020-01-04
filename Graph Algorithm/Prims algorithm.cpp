#include<bits/stdc++.h>
#define mx 100000
using namespace std;

struct edge
{
   int des,wet;
};
vector<edge>adj[mx],path;

priority_queue<edge>pq;



///if we overload "less than" (<) operator then we must overload "greater than" (>) operators.
///And vice versa

bool operator<(edge a,edge b) ///he overload less than (<)
{
   return a.wet>b.wet;  ///oposite according to our expectation
}



int mincost;
bool mark[mx];

int Prime(int src)
{
    edge current;

    current.des=src;
    current.wet=0;

    pq.push(current);


      while( !pq.empty())
      {
         current=pq.top();
         pq.pop();


           int last=current.des;
           if(mark[last]) continue;

           mincost+=current.wet;
           path.push_back(current);
           mark[last]=1;

          for(int i=0;i<adj[last].size();i++)
          {
                edge node=adj[last][i];

                int ch=node.des;
                int cost=node.wet;

                if(mark[ch]==0)
                {
                  pq.push(node);
                }
          }

      }

      return mincost;
}




int main()
{
   freopen("in.txt","r",stdin);

   int n,e,u,v,w,source;

   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
      cin>>u>>v>>w;

       edge input;
      input.des=v;
      input.wet=w;

      adj[u].push_back(input);

      input.des=u;
      input.wet=w;
      adj[v].push_back(input);
   }

   cin>>source;

   cout<<Prime(source)<<endl;

   for(int i=0;i<path.size();i++) cout<<path[i].des<<"--->";

   return 0;
}










