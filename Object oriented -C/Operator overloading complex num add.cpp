#include<bits/stdc++.h>
using namespace std;

class Dream
{
    int  real;
    int imag;
    public:
    void set_data(int x,int y){real=x;imag=y;}

    void Display()
    {
        cout<<real<<"+i"<<imag<<endl;
    }

    Dream operator + (Dream B )
    {
        Dream sum;
        sum.real=real+B.real;
        sum.imag=imag+B.imag;
        return sum;
    }
};


int main()
{
    Dream ob1,ob2,ob3;
    ob1.set_data(10,3);
    ob2.set_data(8,4);
    ob3=ob1+ob2;
    ob3.Display();

    return 0;
}
