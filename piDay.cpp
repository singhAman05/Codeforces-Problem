#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        string pi = "314159265358979323846264338327";
        int cnt = 0;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == pi[i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        cout << cnt << endl;
    }
}