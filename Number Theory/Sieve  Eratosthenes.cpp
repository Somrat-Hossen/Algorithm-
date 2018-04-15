#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
 {

  int n,m;
  printf("Enter the limit for check prime :\n");
  cin>>n;
  int p=sqrt(n)+1;
  int prime[n+2];



    for(int i=2;i*i<=p;i++)//same sqrt(n)==i*i
    {
      if(prime[i])
      {
          for(int j=i*2;j<=n;j+=i)
          {
              prime[j]=0;
          }
      }
    }

 cout<<"Prime series is :";

 for(int i=2;i<=n;i++)
   {
      if(prime[i])
         cout<<prime[i]<<" ";
   }

   cout<<endl<<"Enter any number to check whether it is prime or not:";
   cin>>m;

   if(prime[m])
         printf("%d is a prime number",m);
    else
         printf("%d is not a prime number",m);

     return 0;
 }

