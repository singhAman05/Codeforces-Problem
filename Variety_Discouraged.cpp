// Problem: B. Variety is Discouraged
// Contest: Codeforces - Codeforces Round 1005 (Div. 2)
// URL: https://codeforces.com/contest/2064/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

#define FOR(i, vect, b) for (int i = vect; i <= b; i++)
#define REP(i, vect, b) for (int i = vect; i < b; i++)
#define REV(i, vect, b) for (int i = vect; i >= b; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll vect, ll b) {
    return b == 0 ? vect : gcd(b, vect % b);
}

// LCM
ll lcm(ll vect, ll b) {
    return (vect / gcd(vect, b)) * b;
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

// Factorial of vect Number;
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
        cin >> n;
        vi vect(n);
        for (int i = 0; i < n; i++){
            cin >> vect[i];
        }
        vi ew3(n+1, 0);
        for (int i = 0; i < n; i++){
            ew3[vect[i]]++;
        }

        int ans = 0, lef = -1, rig = -1;
        int st = -1, en = 0;
        for (int i = 0; i < n; i++){
            if (ew3[vect[i]] == 1) {
                if(en == 0)
                    st = i;
                en++;
            } else {
                if(en > ans){
                    ans = en;
                    lef = st;
                    rig = i - 1;
                }
                en = 0;
            }
        }
        if(en > ans){
            ans = en;
            lef = st;
            rig = n - 1;
        }
        if(ans == 0) cout << 0 << "\n";
        else cout << (lef + 1) << " " << (rig + 1) << "\n";
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
