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
    // Understand the problem:
    // We have arrays a and b; we want the number of permutations of a
    // such that a[i] > b[i] for every i. We'll count this modulo 1e9+7.

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Step 1: sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    const ll MOD = 1000000007;
    ll ways = 1; // result counter

    // Step 2: count possibilities from largest index
    // We'll track used elements in 'a' implicitly by adjusting the count.
    for (int i = n - 1; i >= 0; i--)
    {
        // Count how many in 'a' are strictly greater than b[i]
        // This is all elements from some index to the end
        // (Use upper_bound to find first element > b[i])
        ll pos = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll biggerCount = n - pos;

        // We must subtract (n-1 - i) because we've already used that many
        // in previous (larger) b[i] checks.
        ll valid = biggerCount - (n - 1 - i);
        if (valid <= 0)
        {
            ways = 0;
            break;
        }
        ways = (ways * valid) % MOD;
    }

    cout << ways << "\n";

    /*
    Dry run example:
    Suppose n=3, a=[4,3,2], b=[3,4,9]
    Sorted a=[2,3,4], b=[3,4,9]
    - i=2 (b[2]=9): biggerCount=0 => ways=0 => no valid arrangement
    */
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
