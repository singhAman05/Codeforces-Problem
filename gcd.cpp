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
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int res = 0;
        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum -= arr[i];
            res += arr[i];
            maxi = max(maxi, __gcd(sum, res));
        }

        cout << maxi << endl;
    }
    return 0;
}