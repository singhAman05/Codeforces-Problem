// Problem: D. Skibidus and Sigma
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/D
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
#define all(vec) vec.begin(), vec.end()

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
    int n, m;
        cin >> n >> m;
        vpl vec(n);
 
        REP(i,0,n){
            ll sum = 0;   
            ll efvce = 0; 
            REP(ind,0,m){
                ll x;
                cin >> x;
                sum += x;
                efvce += sum;
            }
            vec[i] = {sum, efvce};
        }
 
        ll res = 0;
        REP(i,0,n){
            res += vec[i].second;
        }
        sort(vec.begin(), vec.end(), [](const pair<ll,ll> &a, const pair<ll,ll> &b){
            return a.first > b.first;
        });
        
        REP(i,0,n){
            res += vec[i].first * (ll)(n - 1 - i) * m;
        }
 
        cout << res << "\n";

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
