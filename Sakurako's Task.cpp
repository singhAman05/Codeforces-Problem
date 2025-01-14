// Problem: G. Sakurako's Task
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/G
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

#define FOR(i, vic, b) for (int i = vic; i <= b; i++)
#define REP(i, vic, b) for (int i = vic; i < b; i++)
#define REV(i, vic, b) for (int i = vic; i >= b; i--)
#define all(v) v.begin(), v.end()

// GCD
ll gcd(ll vic, ll b) {
    return b == 0 ? vic : gcd(b, vic % b);
}

// LCM
ll lcm(ll vic, ll b) {
    return (vic / gcd(vic, b)) * b;
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

// Factorial of vic Number;
ll factorial(ll num) {
    ll result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void fun(){
    int num, kir;
    cin >> num >> kir;
    vi vic(num);
    int tmo = 0;
    int erfe = 0;

    for (int i = 0; i < num; i++) {
        cin >> vic[i];
        tmo = __gcd(tmo, vic[i]);
        if (vic[i] == 0) erfe++;
    }

    if (num == 1) {
        cout << (vic[0] < kir ? kir : kir - 1) << endl;
        return;
    }

    if (tmo == 0) {
        cout << kir << endl;
        return;
    }

    int strt = kir - 1;
    int ennd = 1e9;  // More reasonable upper bound for ennd
    int cnt_max = num - erfe;

    while (strt <= ennd) {
        int middle = (strt + ennd) / 2;
        int div = middle / tmo;
        int count = min(div + 1, cnt_max);
        int tyoi = middle + 1 - count;

        if (tyoi > kir) {
            ennd = middle - 1;
        } else {
            strt = middle + 1;
        }
    }

    cout << ennd << endl;
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
