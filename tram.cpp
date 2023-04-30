#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        cnt = cnt + b[i] - a[i];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}