// Problem: C1. Skibidus and Fanum Tax (easy version)
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/contest/2065/problem/C1
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

bool canSort(vector<int>& a, int b) {
    int n = a.size();
    vector<array<bool, 2>> dp(n);
    dp[0][0] = true;
    dp[0][1] = true;
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = false;
        dp[i][1] = false;
        // Options for index i:
        int option0 = a[i]; 
        int option1 = b - a[i];   
        
        if (dp[i-1][0] && (a[i-1] <= option0)) dp[i][0] = true;
        if (dp[i-1][1] && ((b - a[i-1]) <= option0)) dp[i][0] = true;
        
        if (dp[i-1][0] && (a[i-1] <= option1)) dp[i][1] = true;
        if (dp[i-1][1] && ((b - a[i-1]) <= option1)) dp[i][1] = true;
    }
    return dp[n-1][0] || dp[n-1][1];
}

void fun(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    REP(i, 0, n) cin >> a[i];
    vi b(m);
    REP(i, 0, m) cin >> b[i];
    if (canSort(a, b[0])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        fun();
    }
    return 0;
}
