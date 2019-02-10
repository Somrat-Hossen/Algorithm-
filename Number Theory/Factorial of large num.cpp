#include<bits/stdc++.h>
using namespace std;

vector<int>fact;


void Multiply(int x)
{
  int mul,car=0;

  for(int i=0;i<fact.size();i++)  /// loop will continue upto the till size.
  {
       mul=fact[i]*x+car;          /// simple multiplication ,store in the vec
       fact[i]=mul%10;             /// don't use push_back func,causes error
       car=mul/10;
  }

    while(car>0)                    /// if at last car can 120 such so use loop
    {
       fact.push_back((car%10));
       car/=10;
    }
}




void Find_fact(int n)
{
   for(int j=2;j<=n;j++)                 /// function call for multiplying 2 to n
   {
      Multiply(j);
   }

  reverse(fact.begin(),fact.end());            /// we multiply from right to left but for multiplication be left to right.
  puts("Factorial value for n is: ");     /// so reversr the vector.

   for(int i=0;i<fact.size();i++)
   {
     cout<<fact[i];
   }

}


int main()
{

 fact.push_back(1); /// initially keep 1 for multiplication.

  int n;
  cin>>n;
  Find_fact(n);

  return 0;
}
