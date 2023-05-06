#include "bits/stdc++.h"

using namespace std;

int main()
{
    // Write your code here
    string gc;
    cin >> gc;
    int n = gc.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (gc[j] < gc[i - 1])
                dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}