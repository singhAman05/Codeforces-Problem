#include "bits/stdc++.h"
using namespace std;
int main()
{
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cout << abs(v[1] - v[0]) + abs(v[2] - v[1]) << endl;
}