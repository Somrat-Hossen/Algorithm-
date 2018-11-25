#include<bits/stdc++.h>
#define mx 100000000
using namespace std;


int Euler_totient(int n)
{
  int i,j;
  int tmp=n;
  for(i=2;i*i<=n;i++)
  {
     if(n%i==0)
     {
       while(n%i==0)
       {
         n/=i;
       }
      tmp=(tmp/i)*(i-1);
     }
  }
  if(n>2) tmp=(tmp/n)*(n-1);
  return tmp;
}


int main()
{
  int n;
  cin>>n;

  int phi_of_n=Euler_totient(n);
  cout<<phi_of_n<<endl;


}

