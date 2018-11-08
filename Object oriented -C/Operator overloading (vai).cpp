#include<bits/stdc++.h>
using namespace std;

class Math
{
    public: int id;
    double gpa;
Math operator + (Math b)
{
    Math sum;
    sum.id=id+b.id;
    sum.gpa=gpa+b.gpa;
    return sum;
}

};
Math addition(Math a,Math b)
{
    Math sum;
    sum.id=a.id+b.id;
    sum.gpa=a.gpa+b.gpa;
    return sum;
}


int main()
{
    Math ob,ob1,ob2;
    ob.id=10;
    ob1.id=20;
    ob.gpa=3.50;
    ob1.gpa=3.75;
   // ob2=addition(ob,ob1);
   ob2=ob+ob1;
    cout<<ob2.id<<" "<<ob2.gpa<<endl;
   // ob3=ob+ob1;

    return 0;
}
