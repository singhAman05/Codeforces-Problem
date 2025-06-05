// Problem: C2. Skibidus and Fanum Tax (hard version)
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/C2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef map<int, int> mpi;
typedef set<int> seti;
typedef unordered_map<int, int> uom;
typedef unordered_map<char, int> uocm;

const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()

bool solve(const vi &a, const vi &b)
{
    int n = a.size();
    vi sb = b;
    sort(sb.begin(), sb.end());

    ll cur = -INF; 
    REP(i, 0, n)
    {
        ll cb3 = INF, cb2 = INF;
        if (a[i] >= cur)
        {
            cb3 = a[i];
        }
        ll threshold = cur + a[i];
        auto it = lower_bound(sb.begin(), sb.end(), threshold);
        if (it != sb.end())
        {
            cb2 = (ll)(*it) - a[i];
        }
        ll nt = min(cb3, cb2);
        if (nt == INF)
        {
            return false; 
        }
        cur = nt;
    }
    return true;
}

void fun()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    REP(i, 0, n)
        cin >> a[i];
    vi b(m);
    REP(i, 0, m)
        cin >> b[i];

    if (solve(a, b))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}
