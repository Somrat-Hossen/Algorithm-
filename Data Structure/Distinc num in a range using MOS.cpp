#include <bits/stdc++.h>
#define mx 30005
using namespace std;

typedef long long ll;

int currL = 0,currR =0;
int cnt = 0;
int res[2*100005],arr[mx],vis[1000005];

int block;

struct Query
{
	int L, R,id;
}q[200005];

bool compare(Query x,Query y)
{
    /// of the same block are arranged together and within a block,
     /// queries are sorted in increasing order of R values.
    if (x.L/block != y.L/block)  /// Different blocks, sort by block.
      return x.L/block < y.L/block;

    return x.R < y.R; /// Same block, sort by R value
}

void Add(int x)
{
  vis[arr[x]]++;
  if(vis[arr[x]]==1) cnt++;
}
void Remove(int x)
{
  vis[arr[x]]--;
  if(vis[arr[x]]==0) cnt--;
}

void queryResults(int n, int m)
{
    block = (int)sqrt(n);
    sort(q, q + m, compare);

  /*for(int i=0;i<m;i++)
	{
	 cout<<q[i].L<<" "<<q[i].R<<" "<<q[i].id<<endl;
	}
	*/

    for (int i=0; i<m; i++)
    {
        int l = q[i].L, r = q[i].R;

      while(currL < l) Remove(currL++);
      while(currL > l) Add(currL-1),currL--;
      while(currR <= r) Add(currR++);
      while(currR > r+1) Remove(currR-1),currR--;

     res[q[i].id]=cnt;

    }
}


int main()
{
    //freopen("in.txt","r",stdin);

   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);


   int n,m;
	cin>>n;

	for(int i=0;i<n;i++) cin>>arr[i];

	cin>>m;

	for(int i=0;i<m;i++)
   {
      cin>>q[i].L>>q[i].R;
      q[i].id=i;
      q[i].L--;
      q[i].R--;
   }

   queryResults(n,m);

   for(int i=0;i<m;i++)
   {
      cout<<res[i]<<endl;
   }

  return 0;
}

