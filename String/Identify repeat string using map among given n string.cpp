#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int>mp;
    int n,cnt=0,j;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        if(mp[str]==0)
        {
            puts("Not Found");
            mp[str]++;
        }
        else
        {
          puts("Found");
           mp[str]++;
        }
    }

    return 0;
}


