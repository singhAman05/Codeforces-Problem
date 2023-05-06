#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                if (i == n - 1 && x == 'D')
                    ans++;
                else if (j == m - 1 && x == 'R')
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}