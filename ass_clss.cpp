#include <bits/stdc++.h>
using namespace std;

#define ll long long int

long getSubarraySum(vector<ll> &arr)
{
    int l = 0, r = 1e14;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        int ans = 1;
        int pr = 0;
        for (int i = 0; i < n; i++)
        {
            if (pr > starts[i] + d)
            {
                ans = 0;
            }
            else
            {
                pr = max(pr + mid, starts[i]);
            }
        }
        if (ans)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    // cin >> t ;
    t = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<vector<ll>> dp(5, vector<ll>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // ll ans = f(1, 0, a, dp);
        cout << getSubarraySum(a) << "\n";
    }
}