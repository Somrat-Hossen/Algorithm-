#include <bits/stdc++.h>
using namespace std;

int x, y;

int gcdExtended(int a, int b, int &c, int &d)
{
    if (a == 0)
    {
        c = 0;
        d = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, x1, y1);

    // Update c and d using results of recursive
    // call
    c = y1 - (b/a) * x1;
    d = x1;

    x = y1 - (b/a) * x1; ///Store for final op
    y = x1;

    return gcd;
}

int main()
{

/// ax+by=gcd(a,b).Find x and y.

    int c, d;
    int a = 7, b = 19;
    int g = gcdExtended(a, b, x, y);

    printf("gcd(%d, %d) = %d\n", a, b, g);
    cout<<x<<" "<<y<<endl;

    return 0;
}
