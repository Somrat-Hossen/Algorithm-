#include<bits/stdc++.h>
using namespace std;

int u,e,nd,i,j,f,s,src,x,y,des;

vector<int>v[100],path;
int vis[100],dis[100],pa[100];
queue<int> q;

void traversal(int src,int des)
{
    q.push(src);
    vis[src]=1;
    dis[src]=0;

    while(!q.empty())
    {
        f=q.front();
        q.pop();

        for(i=0;i<v[f].size();i++)
        {
            s=v[f][i];
            if(vis[s]==0)
            {
                q.push(s);
                vis[s]=1;
                dis[s]=dis[f]+1;  ///Each time we add 1 with it's parent node
                pa[s]=f;      ///we stored parent in child .f parent ,s child.
            }
        }
    }

  if(vis[des]==0)
        {
          cout<<"There is no path"<<endl;  return ;
        }
   else
    cout<<"Total distance from source to destination: "<<dis[des]<<endl;

   int ne=des;
    path.push_back(des);
    while(ne!=src)
    {
        path.push_back(pa[ne]);
        ne=pa[ne];    ///Each time value of ne changes.
    }
    
    reverse(path.begin(),path.end()); ///Reverse the path vector.

    for(vector<int>::iterator it=path.begin();it!=path.end();it++)
    {
        cout<<*it<<" ";    ///print the path between source to destination
    }
}




int main()
{
  ///freopen("in.txt","r",stdin);

  cin>>e;

  for(i=0;i<e;i++)
  {
      cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

   cin>>src>>des;
    
  traversal(src,des);

    return 0;
}

