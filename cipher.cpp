#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int j = 0;
    int cnt = 1;
    for (int i = 0; i < n; i += cnt)
    {
        cout << s[i];
        // ans[j] = s[i];
        cnt++;
        // j++;
        // cout << ans[j] << " ";
    }
    cout << endl;
}