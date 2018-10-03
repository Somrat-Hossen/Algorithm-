#include <bits/stdc++.h>

using namespace std;

long long cache[10000][10000];
int weight[10000];
int value[10000];

///with n items and capacity cap
///return maximum value that can be taken.

long long knapsack(int n, int cap)
{
    for(int i= 0; i<= n; i++)
    {
      for(int j= 0; j<= cap; j++)
      {
        if(i == 0 || j == 0)
         cache[i][j]= 0;

        else if(weight[i-1] <= j)
            cache[i][j]= max(value[i-1] + cache[i-1][j-weight[i-1]], cache[i-1][j]);
        else
            cache[i][j]= cache[i-1][j];
      }
    }

    return cache[n][cap];
}

int main(void)
{
    freopen("in.txt","r",stdin);
    int cap, n;
    cout<< "Enter number of items and weight capacity:  ";
    cin>>n>>cap;

    for(int i= 0; i<n; i++){
    cin>>value[i]>>weight[i];
    }

    cout<<endl<<"Total Benefit is: "<< knapsack(n, cap) <<endl;


    return 0;
}
