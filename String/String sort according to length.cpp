#include <bits/stdc++.h>
#include <stdlib.h>
#include<iomanip>

using namespace std;

 typedef unsigned int ui;
 typedef unsigned long long int ull;



int main()
 {
     freopen("in.txt","r",stdin);
     int n,l1,l2,i,j;
     string st[105];
     cin>>n;
     char s;


     for(int i=0;i<n;i++)
     {
         cin>>st[i];
     }

    // sort(st,st+n,cmp);

 for(int i=0;i<n;i++)
     {
         cout<<st[i]<<endl;
     }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((st[j].size())<(st[j+1].size()))
            {
               st[j].swap(st[j+1]);
            }
        }
    }
    cout<<endl;

    for(int i=0;i<n;i++)
     {
         cout<<st[i]<<endl;
     }

    return 0;
  }


