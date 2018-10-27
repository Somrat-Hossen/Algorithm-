#include<bits/stdc++.h>
using namespace std;

int main()
{
  string str,substring;
  int i,j=0,cnt=0,len;

  puts("Enter string");
  cin>>str;
  puts("\nEnter substring");
  cin>>substring;
  len=substring.size();

  for(i = 0, j = 0; str[i] != '\0' && substring[j] != '\0'; i++)
    {
        if(str[i] == substring[j])
        {
            j++;
        }
        else
        {
           j = 0;
        }
    }

    if(j == len)
        cout<<"Substring found at position "<< i - j + 1;
    else
        cout<<"Substring not found";
  return 0;
}



