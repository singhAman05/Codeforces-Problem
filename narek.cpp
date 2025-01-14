// Problem: C. Lazy Narek
// Contest: Codeforces - Codeforces Round 972 (Div. 2)
// URL: https://codeforces.com/contest/2005/problem/C
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

const int MAX_STRINGS = 1000 + 10;
int totalStrings, stringLength;
string strings[MAX_STRINGS];
bool isTarget[256];
int memo[MAX_STRINGS][5], scoreDelta[MAX_STRINGS][5], nextState[MAX_STRINGS][5];
string targetChars = "narek";

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

void processString(int idx) {
    for (int startState = 0; startState < 5; startState++) {
        int currentState = startState;
        int delta = 0;
        for (char ch : strings[idx]) if (isTarget[ch]) {
            if (ch == targetChars[currentState]) currentState = (currentState + 1) % 5, delta++;
            else delta--;
        }
        scoreDelta[idx][startState] = delta;
        nextState[idx][startState] = currentState;
    }
}

void computeMaxScore() {
    cin >> totalStrings >> stringLength;
    for (int i = 1; i <= totalStrings; i++) cin >> strings[i];
    for (int i = 0; i <= totalStrings; i++) {
        for (int j = 0; j < 5; j++) memo[i][j] = -1e9;
    }
    for (int i = 1; i <= totalStrings; i++) {
        processString(i);
    }
    memo[0][0] = 0;
    for (int i = 1; i <= totalStrings; i++) {
        for (int prevState = 0; prevState < 5; prevState++) {
            memo[i][nextState[i][prevState]] = max(memo[i][nextState[i][prevState]], memo[i - 1][prevState] + scoreDelta[i][prevState]);
            memo[i][prevState] = max(memo[i][prevState], memo[i - 1][prevState]);
        }
    }
    int optimalScore = 0;
    for (int i = 0; i < 5; i++) optimalScore = max(optimalScore, memo[totalStrings][i] - i - i);
    cout << optimalScore << '\n';
}

void fun(){
    // your code
    cin >> totalStrings >> stringLength;
    for (int i = 1; i <= totalStrings; i++) cin >> strings[i];
    for (int i = 0; i <= totalStrings; i++) {
        for (int j = 0; j < 5; j++) memo[i][j] = -1e9;
    }
    for (int i = 1; i <= totalStrings; i++) {
        processString(i);
    }
    memo[0][0] = 0;
    for (int i = 1; i <= totalStrings; i++) {
        for (int prevState = 0; prevState < 5; prevState++) {
            memo[i][nextState[i][prevState]] = max(memo[i][nextState[i][prevState]], memo[i - 1][prevState] + scoreDelta[i][prevState]);
            memo[i][prevState] = max(memo[i][prevState], memo[i - 1][prevState]);
        }
    }
    int optimalScore = 0;
    for (int i = 0; i < 5; i++) optimalScore = max(optimalScore, memo[totalStrings][i] - i - i);
    cout << optimalScore << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (char c : targetChars) isTarget[c] = true;
    int t;
    cin >> t;
    while (t--) {
        fun();
    }
    return 0;
}
