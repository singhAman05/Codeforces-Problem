// Problem: H. Sakurako's Test
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
typedef unordered_map<int,int> uom;
typedef unordered_map<char,int> uocm;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Modular Exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Factorial of a Number;
ll factorial(ll n) {
    ll result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void fun() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi a(n);
    vi f(n + 1, 0);

    REP(i, 0, n) {
        cin >> a[i];
        f[a[i]]++;
    }

    vi prefix_sum(n + 1, 0);
    FOR(i, 1, n) {
        prefix_sum[i] = prefix_sum[i - 1] + f[i];
    }

    int req_cnt;
    if (n & 1) 
        req_cnt = (n + 1) / 2;
    else 
        req_cnt = (n + 2) / 2;

    auto range_sum = [&](int l, int r) -> int {
        if (l) return prefix_sum[r] - prefix_sum[l - 1];
        return prefix_sum[r];
    };

    vi res(n + 1, 0);
    FOR(x, 1, n) {
        int l = 0;
        int r = x - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;

            auto good = [&](int val) -> bool {
                int cnt = 0;
                for (int start = 0; start <= n; start += x) {
                    cnt += range_sum(start, min(start + val, n));
                }
                return cnt >= req_cnt;
            };

            if (good(mid)) 
                r = mid - 1;
            else 
                l = mid + 1;
        }

        res[x] = l;
    }

    REP(i, 0, q) {
        int val;
        cin >> val;
        cout << res[val] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
