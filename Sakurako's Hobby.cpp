// Problem: D. Sakurako's Hobby
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/D
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

void fun(){
    // your code
    int n;
        cin >> n;  // size of the permutation

        vector<int> p(n);  // the permutation array
        vector<int> color(n);  // color array where 0 is black and 1 is white
        string s;
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;  // make it zero-indexed
        }
        
        cin >> s;
        for (int i = 0; i < n; ++i) {
            color[i] = (s[i] == '0') ? 0 : 1;  // 0 for black, 1 for white
        }
        
        vector<bool> visited(n, false);
        vector<int> result(n, 0);

        // Process each element and find its cycle
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Find the cycle starting from i
                vector<int> cycle;
                int current = i;

                while (!visited[current]) {
                    visited[current] = true;
                    cycle.push_back(current);
                    current = p[current];  // follow the permutation
                }

                // Count the number of black elements in the cycle
                int black_count = 0;
                for (int idx : cycle) {
                    if (color[idx] == 0) {
                        black_count++;
                    }
                }

                // Assign the black count to all elements in the cycle
                for (int idx : cycle) {
                    result[idx] = black_count;
                }
            }
        }

        // Output the result for this test case
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
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
