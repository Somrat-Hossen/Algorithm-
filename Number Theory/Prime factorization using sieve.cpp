#include <bits/stdc++.h>
#define mx 10000000


using namespace std;

typedef  long long int ll;

ll num,sq,x,i,j,cnt,len,p;
bool check[mx+1];
vector<int> prime;

void prime_test()
{
  prime.push_back(2);
   p=sqrt(mx)+1;

 for(i=4;i<=mx;i+=2)///All even except 3 are marked.
  {
     check[i]=1;
  }
    for(int i=3;i<=mx;i+=2)///same sqrt(n)==i*i
    {
      if(check[i]==0)
      {
          prime.push_back(i); ///i means prime
          if(i<=p)  ///there is no divisor after sqrt n
          {
            for(int j=i*2;j<=mx;j+=i)
           {
              check[j]=1; ///0 means not prime
           }
          }
      }
    }
}



int main()
{
  prime_test();
  vector<ll>div;

  /*for(i=0;i<50;i++)
  {
    cout<<prime[i]<<" ";
  }*/

 while(scanf("%lld",&num)&& num!=-1)
  {
    div.clear();
      for(i=0;i*i<num;i++)
       {
        while(num%prime[i]==0 && num)
        {
          div.push_back(prime[i]);
          num/=prime[i];
        }
       }
       if(num>2)  div.push_back(num);

      for(i=0,len=div.size();i<len;i++)
      {
          cout<<div[i]<<endl;
      }
      cout<<endl;
  }


    return 0;
}





