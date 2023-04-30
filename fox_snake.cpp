#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2 != 0 && cnt % 2 != 0)
            {
                if (j == m - 1)
                    cout << "#";
                else
                    cout << ".";
            }
            else if (i % 2 != 0 && cnt % 2 == 0)
            {
                if (j == 0)
                    cout << "#";
                else
                    cout << ".";
            }
            else
            {
                cout << "#";
            }
        }
        if (i & 1)
            cnt++;
        cout << endl;
    }
    return 0;
}