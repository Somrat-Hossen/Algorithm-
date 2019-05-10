#include <bits/stdc++.h>
#define mx 100000
using namespace std;

int res[mx];

int block;

struct Query
{
	int L, R,id;
};

bool compare(Query x,Query y)
{
    /// Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
    /// Same block, sort by R value
    return x.R < y.R;
}


void queryResults(int a[], int n, Query q[], int m)
{
    block = (int)sqrt(n);
    // Sort all queries so that queries of same blocks
    // are arranged together.
    sort(q, q + m, compare);

  /*  for(int i=0;i<m;i++)
	{
	 cout<<q[i].L<<" "<<q[i].R<<" "<<q[i].id<<endl;

	}*/

    int currL = 0, currR = 0;
    int Sum = 0;

    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            Sum-= a[currL];
            currL++;
        }
        /// Add Elements of current Range
        while (currL > L)
        {
            Sum += a[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            Sum += a[currR];
            currR++;
        }
        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            Sum -= a[currR-1];
            currR--;
        }
            // Print sum of current range
            // cout << "Sum of [" << L << ", " << R
            // << "] is "  << Sum << endl;
        res[q[i].id]=Sum;
    }
}


int main()
{
    freopen("in.txt","r",stdin);

	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);

	Query q[100];

	int m;

	cin>>m;

	for(int i=0;i<m;i++)
	{
	  cin>>q[i].L>>q[i].R;
	  q[i].id=i;
	}

	queryResults(a, n, q, m);

	for(int i=0;i<m;i++)
	{
	   cout<<res[i]<<" ";
	}

  return 0;
}
