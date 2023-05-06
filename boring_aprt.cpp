#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int x = s[0] - '0';
        // cout << x << endl;
        int cnt = 0;
        while (x != 1)
        {
            cnt++;
            x--;
        }
        int ans = cnt * 10 + (n * (n + 1) / 2);
        cout << ans << endl;
    }
}