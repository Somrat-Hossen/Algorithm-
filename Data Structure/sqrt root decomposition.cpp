#include"bits/stdc++.h"
#define mx 100000
using namespace std;

int block[mx];

void Preprocess(int arr[],int n,int len )
{

  for(int i=0;i<n;i++)
  {
     block[i/len]+=arr[i];

  }
  //for(int i=0;i<len;i++) cout<<block[i]<<" ";
}

int Query(int arr[],int l,int r,int len)
{
   int sum = 0;
  int c_l = l / len,c_r = r / len;

  if (c_l == c_r)
  {
     for (int i=l;i<=r;++i) ///same segment
     sum += arr[i];
  }
    else
    {
        for (int i=l,tmp=(c_l+1)*len-1;i<=tmp; ++i)
        {
            sum += arr[i];
        }

        for (int i=c_l+1; i<=c_r-1; ++i)
        {
            sum += block[i];
        }

        for (int i=c_r*len;i<=r; ++i)
        {
            sum += arr[i];
        }
    }

    //cout<< sum<<endl;
    return sum;
}

void update(int arr[],int pos,int val,int len)
{

    int seg=pos/len;
    block[seg]+=val-arr[pos];
    arr[pos]=val;
}


int main()
{
   int arr[]={1,8,7,9,6,5,4,3};
   int n=sizeof arr/sizeof arr[0];

  int len= sqrt(n);
  if(sqrt(n)*sqrt(n)!=n)
  {
    len+=1;
  }

   Preprocess(arr,n,len);
   cout<<Query(arr,0,2,len) <<endl;

   update(arr,5,13,len);/// 5 means pos and 0 means val
   cout<<Query(arr,0,5,len) <<endl;

 return 0;
}
