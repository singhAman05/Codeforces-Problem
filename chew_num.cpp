#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long t;
    cin >> t;
    vector<int> v;
    while (t != 0)
    {
        v.push_back(t % 10);
        t = t / 10;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 5)
            v[i] = 4;
        if (v[i] == 6)
            v[i] = 3;
        if (v[i] == 7)
            v[i] = 2;
        if (v[i] == 8)
            v[i] = 1;
        if (v[i] == 9 && i != 0)
            v[i] = 0;
    }
    for (auto it : v)
    {
        cout << it;
    }
    cout << endl;
}