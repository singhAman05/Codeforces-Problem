// Problem: D. I Love 1543
// Contest: Codeforces - Codeforces Round 984 (Div. 3)
// URL: https://codeforces.com/contest/2036/problem/D
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
ll factorial(ll row) {
    ll result = 1;
    for (int i = 2; i <= row; i++) {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll row) {
    if (row < 2) return false;
    for (ll i = 2; i * i <= row; i++) {
        if (row % i == 0) return false;
    }
    return true;
}

int solve(int row, int col, vector<string>& mat) {
    string res = "1543";
    int acc_res = 0;

    for (int l = 0; l < min(row, col) / 2; ++l) {

        string str_lay;

        for (int j = l; j < col - l; ++j)
            str_lay += mat[l][j];

        for (int i = l + 1; i < row - l; ++i)
            str_lay += mat[i][col - l - 1];

        for (int j = col - l - 2; j >= l; --j)
            str_lay += mat[row - l - 1][j];

        for (int i = row - l - 2; i > l; --i)
            str_lay += mat[i][l];

        string temp_layer = str_lay + str_lay.substr(0, 3);

        int cnt = 0;
        for (size_t i = 0; i < str_lay.size(); ++i) {
            if (temp_layer.substr(i, 4) == res) {
                cnt++;
            }
        }
        acc_res += cnt;
    }

    return acc_res;
}

vector<int> ans;

void fun() {
    int row, col;
    cin >> row >> col;
    vector<string> mat(row);

    for (int i = 0; i < row; ++i) {
        cin >> mat[i];
    }

    ans.push_back(solve(row, col, mat));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        fun();
    }

    for (int it : ans) {
        cout << it << endl;
    }

    return 0;
}
