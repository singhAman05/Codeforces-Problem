// Problem: B. Ternary String
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1354/B
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
    string s;
    cin >> s;
    int n = s.size();

    unordered_map<char, int> mp;
    int l = 0, r = 0;
    int ans = INT_MAX;

    while (r < n) {
        // Expand the window by including s[r]
        mp[s[r]]++;
        r++;

        // Check if all three characters are present in the current window
        while (mp['1'] > 0 && mp['2'] > 0 && mp['3'] > 0) {
            // Update the answer with the current window size
            ans = min(ans, r - l);

            // Contract the window from the left
            mp[s[l]]--;
            if (mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
    }

    // If no valid substring was found, return 0; otherwise, print the answer
    if (ans == INT_MAX) cout << "0\n";
    else cout << ans << "\n";
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
