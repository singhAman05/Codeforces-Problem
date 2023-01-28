#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, r;
        cin >> n >> s >> r;
        int ans[n];
        int maxi = s - r;
        ans[n - 1] = maxi;
        for (int i = 0; i < n - 1; i++)
        {
            ans[i] = 1;
        }

        s = s - maxi - (n - 1);

        int i = 0;
        while (s > 0)
        {
            int cur = min(maxi - 1, s);
            ans[i] += cur;
            s -= cur;
            i++;
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}