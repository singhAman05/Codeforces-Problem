// Problem: B. Petr and a Combination Lock
// Contest: Codeforces - Hello 2019
// URL: https://codeforces.com/problemset/problem/1097/B
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

int dp[16];

bool solve(vi &v, int sum, int &tar, int i){
	int n = v.size();
	if(i==n) return tar==sum;
	if(dp[i]!=-1) return dp[i];
	return dp[i] = solve(v,sum+v[i],tar,i+1) || solve(v,sum,tar,i+1);
}

void fun(){
    // your code
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    vi v(n);
    REP(i,0,n) cin>>v[i];
    int sum = accumulate(all(v),0);
    if(sum%2) {cout<<"NO\n";return;}
    sum/=2;
    sum = sum%
    // cout<<sum;
    if(solve(v,0,sum,0)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
