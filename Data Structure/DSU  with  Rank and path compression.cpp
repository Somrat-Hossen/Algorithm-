#include<bits/stdc++.h>
#define mx 10000
using namespace std;

int parrent[mx],rankparrent[mx],n;

void Initialize(int n)
{
   for(int i=1;i<=n;i++)
   {
      parrent[i]=i;
      rankparrent[i]=0;
   }
}

int Find(int x)  ///check the representative
{
   if(parrent[x]==x) return x;
   return parrent[x]=Find(parrent[x]);  ///path compression
}

void Union(int a, int b) ///make friends or marge two set.
{
   int u=Find(a);
   int v=Find(b);

   //cout<<u<<" "<<v<<endl;
   if(u==v) cout<<"They are already friend"<<endl;
   /// Union Rank
   if(rankparrent[u]<rankparrent[v]) parrent[u]=v;
   else if(rankparrent[u]> rankparrent[v])  parrent[v]=u;
   else ///equal rank
   {
      parrent[v]=u;
      rankparrent[u]++;
   }
}

void Print(int n)
{
   for(int i=1;i<=n;i++)
   {
      cout<<"Node is "<<i<<" Parrent is "<<parrent[i]<<" Rank is "<<rankparrent[i]<<endl;
   }
}

int main()
{
   cin>>n;
   Initialize(n);

   Union(1,2);
   Union(2,3);
   Union(1,4);
   Union(1,3);

   //Find(3);

   Print(n);



   return 0;
}

