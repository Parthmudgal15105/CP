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

void solve()
{
    // Read the number of boxes
    int n;
    cin >> n;
    // Create vector to store weights of boxes
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Build prefix sum array for efficient range sum calculations
    // prefix[i] stores sum of all elements from index 0 to i-1
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    // Find all possible values of k (number of boxes per truck)
    // k must be a divisor of n for equal distribution
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            // If i*i != n, then n/i is also a divisor
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }

    // Variable to store maximum difference possible
    ll ans = 0;
    // Try each possible value of k (boxes per truck)
    for (auto k : divisors)
    {
        // For current k, find minimum and maximum truck weights
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        // Iterate through boxes in steps of k
        // Each step represents one truck's allocation
        for (int start = 0; start < n; start += k)
        {
            // Calculate sum of weights for current truck using prefix sum
            // sumk = sum of weights from index 'start' to 'start+k-1'
            ll sumk = prefix[start + k] - prefix[start];
            // Update minimum and maximum truck weights seen so far
            mn = min(mn, sumk);
            mx = max(mx, sumk);
        }
        // Update answer if current distribution gives larger difference
        ans = max(ans, mx - mn);
    }
    // Output the maximum possible difference
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
