#include <bits/stdc++.h>
#define mx 100000

using namespace std;


typedef pair<int,int>pii;
bool marked[mx];
vector <pii> adj[mx];
vector<int>path;

int  Prim(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq; ///Min heap .Also you can overload operator to do so

    int minimumCost = 0;
    pii p;
    pq.push(make_pair(src,0));
   // path.push_back(src);

    while(!pq.empty())
    {
        /// Select the edge with minimum weight
        p = pq.top();
        pq.pop();

        src = p.first;
        // Checking for cycle
        if(marked[src] == true) continue;
        path.push_back(src);

        minimumCost += p.second;

        marked[src] = true;

        for(int i = 0;i < adj[src].size();++i)
        {
            int ch = adj[src][i].first;

            if(marked[ch] == false)
            {
                pq.push(adj[src][i]);
            }
        }
    }
    return minimumCost;
}

int main()
{
    int n, e, x, y,wet;

    cin >> n >> e;
    for(int i=0;i<e;++i)
    {
        cin >> x >> y >> wet;

        adj[x].push_back(make_pair(y, wet));
        adj[y].push_back(make_pair(x, wet));
    }
    ///Selecting 1 as the starting node

    cout <<"Minimum cost is: "<< Prim(1)<< endl;

    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";


    return 0;
}
