#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Values (stored in array val)
// Weights (stored in array wet)
// Number of distinct items (n)
// Knapsack capacity capasity

int val[100000];
int wet[100000];
int benefit,benefit2,capasity,n,i;

int knapSack(int n, int capasity)
{

    if (capasity < 0)    /// base case: Negative capacity
        return INT_MIN;  /// base case: no items left or capacity becomes 0


    if (n < 0 || capasity == 0)
        return 0;


    int benefit = val[n] + knapSack(n - 1, capasity - wet[n]);  /// Case 1. include current item n in knapSack (v[n]) and recurse for                                                                /// remaining items (n - 1) with decreased capacity (W - w[n])

    int benefit2 = knapSack(n - 1, capasity);             /// Case 2. exclude current item n from knapSack and recurse for remaining items (n - 1)

    return max (benefit, benefit2);                  /// return maximum value we get by including or excluding current item
}

int main()
{
   // freopen("in.txt","r",stdin);
    cin>>n>>capasity;
    for(i=0;i<n;i++)
     {
         cin>>val[i]>>wet[i];    /// val and weight
     }

    cout << "Maximum Knapsack value is : "<< knapSack(n - 1, capasity)<<endl;

    return 0;
}


