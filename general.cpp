#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int min_ind = 0;
    int max_ind = 0;
    int minele = 101;
    int maxele = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] <= minele)
        {
            minele = v[i];
            min_ind = i;
        }
        if (v[i] > maxele)
        {
            maxele = v[i];
            max_ind = i;
        }
    }
    if (min_ind < max_ind)
    {
        cout << (n - 1 - min_ind) + (max_ind - 0) - 1 << endl;
    }
    else
    {
        cout << (n - 1 - min_ind) + (max_ind - 0) << endl;
    }
}