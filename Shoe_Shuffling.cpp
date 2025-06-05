// Problem: B. Shoe Shuffling
// Contest: Codeforces - CodeCraft-22 and Codeforces Round 795 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1691/B
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
#define nl "\n"

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

void fun() {
	int n;
	cin >> n;
	vector<int> shoe_sz(n);
	for (int i = 0; i < n; i++) // non-decreasing order; asc; sorted
		cin >> shoe_sz[i]; 

	// create a perm. p[i] = i
	vector<int> shuffling(n);
	for (int i = 0; i < n; i++)
		shuffling[i] = i + 1;

	//'left' rotate same shoe size groups by 1
	//rotate a group of 'k' elements; it takes only O(k) time 
	//Total TC: O(N)

	int i = 0;
	while (i < n) {
		int cur_sz = shoe_sz[i]; // shoe size for current group

		// find bounds: start, end; cur_sz is in [start, end)
		// start: first occurrence of cur_sz
		int start = i;
		// end: one past the last occurrence of cur_sz
		int end = i;
		while (end < n && shoe_sz[end] == cur_sz) end++;

		// if you have a unique shoe size: 6 7 7 
		if (start == end - 1) {
			// we have a unique shoe size
			cout << "-1" << '\n';
			return;
		}

		// rotate this group by left
		// cyclically rotate by 1 in left direction
		rotate(shuffling.begin() + start, shuffling.begin() + start + 1, shuffling.begin() + end);

		// move to next group
		i = end;
	}	

	// shuffling has a valid shuffling
	for (auto s : shuffling) cout << s << ' ';
	cout << '\n';
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
