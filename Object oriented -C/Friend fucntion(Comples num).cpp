#include<bits/stdc++.h>
using namespace std;

class Dream
{
    int  real;
    int imag;
   public:
    void set_data(int x,int y){real=x;imag=y;}
    friend Dream Complex (Dream,Dream );
    void Display()
    {
        cout<<real<<"+i"<<imag<<endl;
    }
};

Dream Complex(Dream A,Dream B)
{
   Dream res;
   res.real=A.real+B.real;
   res.imag=A.imag+B.imag;
   return res;
}



int main()
{
    Dream ob1,ob2,ob3;
    ob1.set_data(10,3);
    ob2.set_data(5,2);
    ob3=Complex(ob1,ob2);
    ob3.Display();

    return 0;
}
