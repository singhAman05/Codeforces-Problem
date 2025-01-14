// Problem: C. Registration system
// Contest: Codeforces - Codeforces Beta Round 4 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/4/C
// Memory Limit: 64 MB
// Time Limit: 5000 ms
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
    int n;
    cin >> n;  // Read the number of users trying to register
    unordered_map<string, int> mp;
    
    while(n--){
        string s;
        cin >> s;
        
        // Check if the name already exists in the database
        if(mp.find(s) == mp.end()){
            cout << "OK\n";
            mp[s] = 1;  // Initialize the counter for this name
        } else {
            int i = mp[s]; // Start from the last used suffix
            string new_str;
            
            // Find the smallest suffix that hasn't been used
            while(true){
                new_str = s + to_string(i);
                if(mp.find(new_str) == mp.end()){
                    cout << new_str << endl;
                    mp[new_str] = 1;    // Mark this new name as used
                    mp[s] = i + 1;      // Update the counter for future use
                    break;
                }
                i++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t; // Uncomment if there are multiple test cases
    while (t--) {
        fun();
    }
    return 0;
}

