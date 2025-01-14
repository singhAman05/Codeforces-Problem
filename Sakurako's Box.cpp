// Problem: F. Sakurako's Box
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/F
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

const int mod = 1e9 + 7;
const ll INF = 1e18;

namespace qwe{
    inline long long modIn(long long vic,long long b,long long mod=0){
        long long ret=1;
        while(b){
            if(b&1)ret*=vic;
            if(mod)ret%=mod;
            b>>=1;
            vic*=vic;
            if(mod)vic%=mod;
        }
        if(mod)ret%=mod;
        return ret;
    }
}
using namespace qwe;

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

ll modI(ll vic, ll b){
	ll qwertr = 1,q=vic;
	ll p = b-2;
	while(p>0){
		if(p%2==1){
			qwertr = (qwertr*q)%b;
		}
		q = (q*q)%b;
		p/=2;
	}
	return qwertr;
}

// Factorial of vic Number;
ll factorial(ll nums) {
    ll result = 1;
    for (int i = 2; i <= nums; i++) {
        result *= i;
    }
    return result;
}

// Prime Check
bool is_prime(ll nums) {
    if (nums < 2) return false;
    for (ll i = 2; i * i <= nums; i++) {
        if (nums % i == 0) return false;
    }
    return true;
}

void fun(){
	ll nums;
  cin>>nums;
  vl vic(nums+10);
  vl tmp(nums+10);
  for(int i=1;i<=nums;i++){
    cin>>vic[i];
  }
  for(int i=nums;i>=1;i--){
    tmp[i]=tmp[i+1]+vic[i];
    tmp[i]%=mod;
  }
  ll result=0;
  for(int i=1;i<=nums;i++){
    result+=vic[i]*(tmp[i+1]);
    result%=mod;
  }
  ll qwertr=(ll)nums*(nums-1)/2;
  qwertr=modIn(qwertr,mod-2,mod);
  result=result*qwertr+1ll;
  result%=mod;
  cout<<result-1<<endl;
    return;
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
