// Problem: F. XORificator 3000
// Contest: Codeforces - Codeforces Round 984 (Div. 3)
// URL: https://codeforces.com/contest/2036/problem/F
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
    ll ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

// Factorial of a Number
ll factorial(ll num) {
    ll ans = 1;
    for (int i = 2; i <= num; i++) {
        ans *= i;
    }
    return ans;
}

// Prime Check
bool is_prime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Compute XOR from 1 to num
ll solveXOR(ll num) {
    if (num < 0) return 0;
    int rem = num % 4;
    if (rem == 0) return num;
    if (rem == 1) return 1;
    if (rem == 2) return num + 1;
    return 0;
}

// Compute XOR of range [low, high]
ll solveRange(ll low, ll high) {
    return solveXOR(high) ^ solveXOR(low - 1);
}

// Calculate XOR of values satisfying x ≠ k mod 2^i within [l, r]
ll calCOR(ll l, ll r, ll bs, ll mv) {
    ll power = 1LL << bs;
    ll SI = max(0LL, (l > mv ? (l - mv + power - 1) / power : 0));
    ll EI = (r >= mv) ? (r - mv) / power : -1;

    if (SI > EI) return 0;

    ll count = EI - SI + 1;
    ll XOR_end = solveXOR(EI);
    ll XOR_sta = solveXOR(SI - 1);
    ll XOR_pat = (XOR_end ^ XOR_sta) << bs;

    // Include mv if count of terms is odd
    return (count % 2 == 1) ? XOR_pat ^ mv : XOR_pat;
}

void solve_query() {
    ll l, r, bs, mv;
    cin >> l >> r >> bs >> mv;

    ll XOR_exl = calCOR(l, r, bs, mv);
    ll XOR_tot = solveRange(l, r);
    ll ans = XOR_tot ^ XOR_exl;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve_query();
    }
    return 0;
}
