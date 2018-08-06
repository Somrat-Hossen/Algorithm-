#include <bits/stdc++.h>
#include <stdlib.h>
#include<iomanip>

using namespace std;

int main()
 {
     //freopen("in.text","r",stdin);
     char ch;
     string st,str;
     int cnt=0,res;
     puts("puts your string:");
     getline(cin,st);
    // scanf("%c",&ch);
    puts("puts your substring:");
     getline(cin,str);

    // printf("%d %d ",str.length(),st.length());

     for(int i=0;i<str.length();i++)
     {
         for(int j=0;j<st.length();j++)
         {
          if((str[i]==st[j]) and cnt==0)
             {
                 cnt++;
                 res=j; break;
             }
             else
              {
             if((str[i]==st[j]) and(j==res+1))
               {
                 cnt++;res=j;break;
               }
             }
         }
     }
     if(cnt==str.size())
     {
         puts("Found");
     }
     else
        puts("Not found");
 //cout<<cnt<<endl<<str.length()<<endl;

    return 0;
  }

