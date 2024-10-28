#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

// Types of declarations
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Odd Even
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

// Prime check
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// GCD & LCM
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; 
}

// Square Root
long long sqrt(long long x) {
    long long s = 0, e = 2e9, res = s;
    while (s <= e) {
        long long m = (s + e) / 2;
        if (m * m <= x) res = m, s = m + 1;
        else e = m - 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vi shoe_sizes(n);
    for (int i = 0; i < n; i++) 
        cin >> shoe_sizes[i];

    vi shuffling_indices(n);
    for (int i = 0; i < n; i++)
        shuffling_indices[i] = i + 1;
    //'left' rotate same shoe size groups by 1
    
    int i = 0;
    while (i < n) {
        int current_size = shoe_sizes[i]; 
        int start = i;
        // end: one past the last occurrence of current_size
        int end = i;
        while (end < n && shoe_sizes[end] == current_size) end++;

        // if you have a unique shoe size: 6 7 7 
        if (start == end - 1) {
            // we have a unique shoe size
            cout << "-1" << nl;
            return;
        }

        // rotate this group by left
        // cyclically rotate by 1 in left direction
        rotate(shuffling_indices.begin() + start, shuffling_indices.begin() + start + 1, shuffling_indices.begin() + end);

        // move to next group
        i = end;
    }

    // shuffling_indices has a valid shuffling
    for (auto index : shuffling_indices) cout << index << sp;

    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}
