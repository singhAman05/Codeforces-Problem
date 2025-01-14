#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' || s[i] == 'a' || s[i] == 'I' || s[i] == 'i' || s[i] == 'E' || s[i] == 'e' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u' || s[i] == 'Y' || s[i] == 'y')
            continue;
        else
            s[i] = s[i] | 32;
        ans = ans + '.' + s[i];
    }

    cout << ans << endl;

    // cout << "hello";
    return 0;
}