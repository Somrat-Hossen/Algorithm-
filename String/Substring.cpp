#include <iostream>
#include <string>

using namespace std;

int main ()
{
  string str="abcabc.";
                                           // (quoting Alfred N. Whitehead)

 string st= str.substring(str.begin(),str.end());     // "think"


  cout << st<< '\n';

  return 0;
}
