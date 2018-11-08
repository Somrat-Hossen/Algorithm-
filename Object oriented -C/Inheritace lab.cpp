#include<bits/stdc++.h>
using namespace std;
class Person
{
    string name;
    int age;
public:
   // Person(){}
      Person(string x,int y){name=x;age=y;}
      void Display()
      {
          cout<<"Name: "<<name<<endl;
          cout<<"Age : "<<age<<endl;
      }
};
class Teacher:public Person
{
    string degree;
public: //Teacher(){}
      Teacher(string na,int ag,string deg):Person(na,ag)
      {
          degree=deg;
      }
      void Display()
      {
          cout<<"Profession : Teacher"<<endl;
          Person::Display();
          cout<<"Degree:"<<degree<<endl;
      }
};
class Student :public Person
{
   int id;
public:
      Student(string na,int ag,int m):Person(na,ag)
      {
          id=m;
      }
      void Display()
      {
          cout<<"Profession : Student"<<endl;
          Person::Display();
          cout<<"Std id: "<<id<<endl;
      }
};



int main()
{

   Teacher teacher1("Dr .Md Waliur Rahman",40,"Phd defree") ;
   Student student2("Somrat",20,164067);
   teacher1.Display();
   cout<<endl;
   student2.Display();


    return 0;
}
