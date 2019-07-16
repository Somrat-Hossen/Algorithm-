#include<bits/stdc++.h>
#define mx 10000
using namespace std;

int arr[mx],n;

void Initialize(int n)
{
   for(int i=1;i<=n;i++)
   {
      arr[i]=i;
   }
}

int Find(int x)  ///check the representative
{
   if(arr[x]==x) return x;
   return arr[x]=Find(arr[x]); ///path compression
}

void Union(int a, int b) ///make friends or marge two set.
{
   int u=Find(a);
   int v=Find(b);

   if(u==v) cout<<"They are already friend"<<endl;
   else
        arr[b]=a;
}

int main()
{

   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

   cin>>n;
   Initialize(n);
   Union(1,2);
   Union(2,3);
   Union(1,4);
   Union(1,3);

   Find(3);



   return 0;
}
