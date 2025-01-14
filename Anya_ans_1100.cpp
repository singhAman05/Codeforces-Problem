// Problem: C. Anya and 1100
// Contest: Codeforces - Codeforces Round 984 (Div. 3)
// URL: https://codeforces.com/contest/2036/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

bool iscorrect(const string &s, int idx) {
    return idx >= 0 && idx + 3 < s.size() && s.substr(idx, 4) == "1100";
}


void fun(){
    // your code
    int n, q;
    string s;
    cin >> s;
    n = s.size();
    cin >> q;

    // Set to keep track of starting indices of "1100" substrings
    seti pos;

    // Initialize pos with all occurrences of "1100"
    for (int i = 0; i <= n - 4; i++) {
        if (iscorrect(s, i)) {
            pos.insert(i);
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        i--; // Convert 1-based index to 0-based

        // If no change, skip the query
        if (s[i] - '0' == v) {
            cout << (pos.empty() ? "NO" : "YES") << endl;
            continue;
        }

        // Remove affected pos from the set if they contain "1100"
        for (int j = i - 3; j <= i; j++) {
            if (iscorrect(s, j)) {
                pos.erase(j);
            }
        }

        // Apply the change
        s[i] = v + '0';

        // Re-check affected pos and add back any new "1100" substrings
        for (int j = i - 3; j <= i; j++) {
            if (iscorrect(s, j)) {
                pos.insert(j);
            }
        }

        // Output the result for this query
        cout << (pos.empty() ? "NO" : "YES") << endl;
    }
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
