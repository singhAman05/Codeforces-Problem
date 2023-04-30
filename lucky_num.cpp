#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int l = 0;
    while (n != 0)
    {
        int x = n % 10;
        if (x == 4 || x == 7)
            l++;
        n = n / 10;
    }
    if (l == 4 || l == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}