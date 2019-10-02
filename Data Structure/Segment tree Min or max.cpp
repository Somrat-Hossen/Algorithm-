#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int n;
int arr[mx+5];
int tree[4*mx];

void built(int node, int l,int r)
{

   if(l==r)
   {
      tree[node]=arr[l]; /// l and r is equl
      return ;
   }

   int left_node=2*node;
   int right_node=2*node+1;
   int mid=(l+r)/2;

   built(left_node,l,mid);
   built(right_node,mid+1,r);

  tree[node]=min(tree[left_node],tree[right_node]);
}

int query(int node,int l,int r,int i,int j)  /// l and r are the current node[4-6]sum   i,j are the range where,s sum needed
{
   if(i>r || j<l) return INT_MAX; /// out of cur node
   if(l>=i && r<=j) return tree[node];

  int left_node=2*node;
  int right_node=2*node+1;
  int mid=(l+r)/2;

  int a=query(left_node,l,mid,i,j);
  int b=query(right_node,mid+1,r,i,j);

  return min(a,b);
}


int main()
{

   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);


   int cnt=0,l,r,tmp,q;


      scanf("%d %d",&n,&q);
      for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

      built(1,1,n);

      while(q--)
      {
         scanf("%d %d",&l,&r);

         printf("%d\n",query(1,1,n,l,r));
      }


   return 0;
}
