// Problem: E. Klee's SUPER DUPER LARGE Array!!!
// Contest: Codeforces - Codeforces Round 971 (Div. 4)
// URL: https://codeforces.com/contest/2009/problem/E
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

ll solve(ll x, ll y){
    ll tmp1 = x * (x - 1) / 2;  // Sum of numbers from 1 to x
    ll tmp2 = y * (y + 1) / 2;  // Sum of numbers from 1 to y

    return tmp2 - tmp1;  // Return the difference between the sums
}

void fun() {
    ll n, k;
    cin >> n >> k;

    ll l = k, r = n + k-1;
    ll ans = LLONG_MAX;  // Use LLONG_MAX for large numbers
    
    while (l <= r) {
        ll mid = l + (r - l) / 2;  // Find the mid-point of the current range
        
        // Calculate sum1 and sum2 for the current mid value
        ll sum1 = solve(k, mid);
        ll sum2 = solve(mid+1, k+n-1);
        
        // Minimize the difference between the two sums
        ans = min(ans, abs(sum1 - sum2));
        
        // Adjust binary search bounds
        if (sum1 > sum2) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
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
