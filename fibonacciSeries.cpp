// Fibbonacci series

#include "bits/stdc++.h"
using namespace std;
int fun(int n)
{
    if (n <= 1)
        return n;

    int sum = fun(n - 1) + fun(n - 2);
    // cout << sum;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << fun(n);
}