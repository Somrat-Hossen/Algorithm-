#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>res;
int sum_of_digit;

void Multiply(int a)
{
   int x,car=0;

   for(int i=0;i<res.size();i++)
   {
      x=res[i]*a+car;
      res[i]=x%10;
      car=x/10;
   }
   while(car>0)
   {
     res.push_back(car%10);
     car/=10;
   }

}

void Power(int a, int b)
{
   for(int i=1;i<=b;i++)
   {
     Multiply(a);
   }
   reverse(res.begin(),res.end());
   for(int i=0;i<res.size();i++)
   {
      cout<<res[i];
      sum_of_digit+=res[i];
   }
   cout<<endl<<sum_of_digit<<endl;
}

int main()
{
  res.push_back(1);

  int a,b;
  cin>>a>>b;

  Power(a,b);

  return 0;
}
