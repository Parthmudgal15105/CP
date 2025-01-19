#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Types of declarations /////////////////////////////////
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

// Odd Even /////////////////////////////////////////////
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

///////////////////////////////////////////////////////// LCM GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
////////////////////////////////////////////////////////// SQR ROOT

long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1;
        else
            e = m - 1;
    }
    return res;
}

/*
check all edge cases
check for integer overflow
check for corner cases
check for constraints
check for time complexity
check for array bounds
check for negative values
*/

/*----------------------------------------------------------------------------*/
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Sort array to make min/max operations easier
    sort(a.begin(), a.end());

    // Create prefix sum array to efficiently calculate range sums
    // prefix[i] represents sum of first i elements
    vector<ll> prefix(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    // Main logic:
    // For each possible number of "remove 2 mins" operations (i),
    // calculate remaining "remove max" operations (k-i)
    // and find maximum possible sum
    ll ans = 0;
    for (ll i = 0; i <= k; i++)
    {
        ans = max(ans, prefix[n - (k - i)] - prefix[2 * i]);
    }
    cout << ans << endl;
}

/* Dry run example:
Input: n=5, k=1
Array: [2, 5, 1, 10, 6]

After sorting: [1, 2, 5, 6, 10]
Prefix sums: [0, 1, 3, 8, 14, 24]

i=0 (0 min operations, 1 max operation):
- Valid as 2*0 <= 5 && (1-0) <= (5-0)
- Sum = prefix[4] - prefix[0] = 14 - 0 = 14
  (removes last element 10)

i=1 (1 min operation, 0 max operations):
- Valid as 2*1 <= 5 && (1-1) <= (5-2)
- Sum = prefix[5] - prefix[2] = 24 - 3 = 21
  (removes first two elements 1,2)

Answer = max(14, 21) = 21
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
