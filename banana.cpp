#include "bits/stdc++.h"
using namespace std;
int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    long long ans = k * ((w * (w + 1)) / 2);
    if (ans > n)
        cout << ans - n << endl;
    else
        cout << 0 << endl;
}