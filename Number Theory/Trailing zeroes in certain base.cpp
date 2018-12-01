#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int digit_count(int n,int base)
{
  double digit=0;
  for(int i=1;i<=n;i++)
  {
     digit+=log(double(i));
  }

  digit=(digit/log(base))+1;
 ///digit=floor(digit)+1;  if base not needed.
  return  floor(digit) ;

}




int count_zero(int n,int b)
{

  /// at first made prime factorization of base b.if one factor occurences more than one the divide the res by occurence num. res will get from the
  /// las while(n/>0){ res+=n/i;i*=i; }look at the topics on how to find trailing zero of a factorial n. At last take the min.because we count 5 in our
  /// 10 base factorial.2 was more than 5.thus think a little bit.

	int cnt,res=INT_MAX,ans=0,x,y;
	int num=b;

     y=b;
   for(int i = 2; i <= b; i++)
   {
		cnt = 0;
       if(y%i==0)
       {
		 while(y % i == 0)
		  {
			cnt++;
			y /= i;
		  }
		  x=i;
		  ans=0;
		 while(n/x>0)
		  {
		    ans+=n/x;
		    x*=i;
		  }

		res=min(res,ans/cnt); /// if one prime occur several times,so ans/cnt
		}
	}

	return res;
}

int main()
{
   int n,base;
   cin>>n>>base;

   ll dig,zero;
   dig=digit_count(n,base);
   zero=count_zero(n,base);

   cout<<"Digit:"<<dig<<endl<<"Zero"<<zero<<endl;
 return 0;
}
