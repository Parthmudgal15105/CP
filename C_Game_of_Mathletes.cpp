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
#define all(x) x.begin(), x.end()
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
// Utility functions for checking odd/even numbers
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime
// Prime number checking function
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
// GCD and LCM calculation functions
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
// Binary search implementation for square root
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

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (v[l] + v[r] == k)
        {
            ans++;
            l++, r--;
        }
        else if (v[l] + v[r] > k)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    // Fast I/O optimization
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Process multiple test cases
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
