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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                even.push_back(i + 1);
            else
                odd.push_back(i + 1);
        }

        if (odd.size() >= 3)
        {
            cout << "YES" << endl;
            cout << odd[0] << " " << odd[1] << " " << odd[2] << endl;
        }
        else if (even.size() >= 2 && odd.size() >= 1)
        {
            int evecnt = 0, oddcnt = 0;
            cout << "YES" << endl;

            cout << odd[0] << " " << even[0] << " " << even[1] << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}