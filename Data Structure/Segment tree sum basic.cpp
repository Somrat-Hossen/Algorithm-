#include<bits/stdc++.h>
#define mx 1000000
using namespace std;

int n;
int arr[mx];
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

  tree[node]=tree[left_node]+tree[right_node];
}

int query(int node,int l,int r,int i,int j)  /// l and r are the current node[4-6]sum   i,j are the range where,s sum needed
{
   if(i>r || j<l) return 0; /// out of cur node
   if(l>=i && r<=j) return tree[node];

  int left_node=2*node;
  int right_node=2*node+1;
  int mid=(l+r)/2;

  int a=query(left_node,l,mid,i,j);
  int b=query(right_node,mid+1,r,i,j);

  return (a+b);

}

void update(int node,int l, int r, int pos, int val)
{
  if(pos>r || pos<l) return;   ///out of boundary
  if((l==r) and pos==l)  /// l==r and pos==(l /r)
  {
     tree[node]=val;
  }
else
{
  int left_node=2*node;
  int right_node=2*node+1;
  int mid=(l+r)/2;

  update(left_node,l,mid,pos,val);
  update(right_node,mid+1,r,pos,val);

  tree[node]=tree[left_node]+tree[right_node];
 }

}


int main()
{
  cin>>n;

    for(int i=1;i<=n;i++) cin>>arr[i];

    built(1,1,n);
    cout<<endl<<"Sum is:"<<query(1,1,n,3,6)<<endl;

    update(1,1,n,5,0);  ///index 5 will be update by 0
    cout<<endl<<"Sum is:"<<query(1,1,n,3,6)<<endl;


   update(1,1,n,6,0);  ///index 6 will be update by 0
   cout<<query(1,1,n,3,6)<<endl;

   update(1,1,n,4,0);  ///index 6 will be update by 0
   cout<<query(1,1,n,3,6)<<endl;

   update(1,1,n,3,0);  ///index 6 will be update by 0
   cout<<query(1,1,n,3,6)<<endl;
   cout<<query(1,1,n,1,2)<<endl;


  return 0;
}
