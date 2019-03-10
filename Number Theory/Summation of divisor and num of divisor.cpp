#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,i,j,cnt,sq,num_of_div=1,sum_of_div=1,x;


int main()
{

 cin>>n;

 sq=sqrt(n);

 for(i=2;i*i<=n;i++)
 {
    cnt=0;

    if(n%i==0)
    {
       while(n%i==0)
       {
          cnt++;
          n/=i;
       }
       num_of_div=num_of_div*(cnt+1);///calculate num of divisor.

       sum_of_div*=((pow(i,cnt+1)-1)/(i-1)); ///1+x+x^2+x^3+......x^n=(x^(n+1)-1)/(x-1);
    }
 }

 if(n>2)
 {
   num_of_div*=2;
   sum_of_div*=1+pow(n,1); ///if num is prime
 }

 cout<<"Number of Divisor:"<<num_of_div<<endl<<"Sum of divisor:"<<sum_of_div<<endl;

  return 0;
}
