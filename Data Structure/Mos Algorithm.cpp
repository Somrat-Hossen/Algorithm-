#include <bits/stdc++.h>
#define mx 100000
using namespace std;

int currL = 0,currR =-1;
int sum = 0;
int res[mx],arr[mx];

int block;

struct Query
{
	int L, R,id;
};

bool compare(Query x,Query y)
{

    if (x.L/block != y.L/block)  /// Different blocks, sort by block.
      return x.L/block < y.L/block;

    return x.R < y.R; /// Same block, sort by R value
}

void Add(int x) { sum += arr[x];}
void Remove(int x) { sum -= arr[x];}


void queryResults(int arr[], int n, Query q[], int m)
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

      while(currL > l) Add(--currL);
      while(currR < r) Add(++currR);
      while(currL < l) Remove(currL++);
      while(currR > r) Remove(currR--);

     res[q[i].id]=sum;

    }
}


int main()
{
    //freopen("in.txt","r",stdin);
	Query q[100000];
	int n,m;

	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];

	cin>>m;

	for(int i=0;i<m;i++)
	{
	  cin>>q[i].L>>q[i].R;
	  q[i].id=i;
	}

	queryResults(arr, n, q, m);

	for(int i=0;i<m;i++)
	{
	   cout<<res[i]<<" ";
	}

  return 0;
}
