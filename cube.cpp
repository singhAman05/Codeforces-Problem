#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int lev = 1;
    int cub = 1;
    while (n > 0)
    {
        n = n - cub;
        if (n < 0)
            break;
        lev++;
        cub += lev;
        ans++;
    }
    cout << ans << endl;
}