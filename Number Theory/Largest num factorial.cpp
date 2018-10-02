#include<bits/stdc++.h>

void multiply(int x);
void factorial(int n);
#define MAX 500
int result[MAX];
int len;

 using namespace std;
   int main()
   {
    int n;
    cin>>n;
    factorial(n);
    return 0;
   }

  void factorial(int n)
  {
       result[0]=1;
       len=1;int cnt=0;
       for(int i=2;i<=n;i++)
       {
           multiply(i);
       }
       for(int i=len-1;i>=0;i--)
       {
         cout<<result[i];
         cnt++;
       }
      // cout<<endl;
       //cout<<cnt;
     }

     void multiply(int x)
     {
       int carry=0;
       for(int i=0;i<len;i++)
       {
           int temp=result[i]*x+carry;
           result[i]=temp%10;
           carry=temp/10;
       }
       while(carry)
       {
          result[len]=carry%10;
          carry=carry/10;
          len++;
       }
     }
