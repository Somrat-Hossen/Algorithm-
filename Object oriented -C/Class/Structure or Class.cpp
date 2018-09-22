#include<bits/stdc++.h>
using namespace std;

class student ///it we wanna use as structure
{               /// then class replace by structure and public deleted
    public:
    string name;
    int roll;
    double gpa;
};

int main()
{
    int i,n;
    puts("Enter the number of student");
    cin>>n;
    struct student s[n+5];

    for(i=1;i<=n;i++)
    {
        cin>>s[i].name>>s[i].roll>>s[i].gpa;
    }
    puts("\nOutput is:");

    for(i=1;i<=n;i++)
    {
        cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].gpa<<endl;
    }
    return 0;
}
