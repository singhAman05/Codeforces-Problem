#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans[n][n - 1];
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cin >> ans[i][j];
            }
            freq[ans[i][0]]++;
        }

        int flag = -1;
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == n - 1)
                flag = i;
        }

        cout << flag << " ";

        for (int i = 0; i < n; i++)
        {
            if (ans[i][0] != flag)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    cout << ans[i][j] << " ";
                }
                break;
            }
        }
        cout << endl;
    }

    return 0;
}