// Problem: C. Remove the Ends
// Contest: Codeforces - Codeforces Round 1005 (Div. 2)
// URL: https://codeforces.com/contest/2064/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
        cin >> n;
        vl a(n+1);
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }

        vi v1(n+2, n+1);
        v1[n+1] = n+1;
        v1[n] = (a[n] > 0 ? n : n+1);
        for (int i = n-1; i >= 1; i--){
            if(a[i] > 0)
                v1[i] = i;
            else
                v1[i] = v1[i+1];
        }
        vi v2;
        int ind = 1;
        while(ind <= n){
            int tmp = v1[ind];
            if(tmp > n) break;
            v2.push_back(tmp);
            ind = tmp + 1;
        }
        vl v3(n+1, 0);
        int ci = 0;
        for (int k = 1; k <= n; k++){
            v3[k] = v3[k-1];
            if(ci < (int)v2.size() && v2[ci] == k){
                v3[k] += a[k];
                ci++;
            }
        }
        ll ca = v3[n]; 
 
        vi pn(n+1, 0);
        pn[0] = 0;
        for (int i=1; i<=n; i++){
            if(a[i] < 0)
                pn[i] = i;
            else
                pn[i] = pn[i-1];
        }
        vi nc; 
        int crr = n;
        while(crr >= 1){
            int tmp2 = pn[crr];
            if(tmp2 == 0) break;
            nc.push_back(tmp2);
            crr = tmp2 - 1;
        }
        vi ncr = nc;
        reverse(ncr.begin(), ncr.end());
 
        vl ngc(ncr.size()+1, 0);
        for (int i = 0; i < (int)ncr.size(); i++){
            ngc[i+1] = ngc[i] + (-a[ ncr[i] ]);
        }
        ll cb = (ncr.size() ? ngc[ ncr.size() ] : 0);
 
 
        auto getNegChainSumFrom = [&](int si) -> ll {
            if(si > n) return 0LL;
            int l = 0, h = (int)ncr.size();
            while(l < h){
                int mid = (l + h) / 2;
                if(ncr[mid] < si)
                    l = mid + 1;
                else
                    h = mid;
            }
            int tmp = l; 
            return ( ngc[ ncr.size() ] - ngc[tmp] );
        };
 
        ll cdm = 0;
        for (int k = 0; k <= n; k++){
            ll psum = v3[k]; 
            ll nsum = getNegChainSumFrom(k+1); 
            cdm = max(cdm, psum + nsum);
        }
 
        long long ans = max({ca, cb, cdm});
        cout << ans << "\n";
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
