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
/*
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // pre[i] = the earliest position in a where we can collect the i-th required flower (b[i-1])
    // pre[0] = -1 (before the start), pre[i] = n if not possible
    vector<int> pre(m + 1, n);
    pre[0] = -1;
    int j = 0;
    // Try to match each requirement b[j] with a flower in a from left to right
    for (int i = 0; i < n and j < m; ++i)
    {
        if (a[i] >= b[j])
        {
            pre[j + 1] = i; // Found a flower for b[j] at position i
            j++;
        }
    }

    // suf[i] = the latest position in a where we can collect the i-th required flower (b[i])
    // suf[m] = n (after the end), suf[i] = -1 if not possible
    vector<int> suf(m + 1, -1);
    suf[m] = n;
    j = m - 1;
    // Try to match each requirement b[j] with a flower in a from right to left
    for (int i = n - 1; i >= 0 && j >= 0; i--)
    {
        if (a[i] >= b[j])
        {
            suf[j] = i; // Found a flower for b[j] at position i
            j--;
        }
    }

    // If we can collect all m flowers without inserting, output 0
    if (pre[m] < n)
    {
        cout << "0\n";
        return;
    }

    int ans = INT_MAX;
    // Try inserting a flower for each requirement b[i-1] (1-based for pre/suf)
    // Check if by inserting a flower of beauty b[i-1] between pre[i-1] and suf[i], we can collect all m flowers
    for (int i = 1; i <= m; ++i)
    {
        if (pre[i - 1] < suf[i])
        {
            ans = min(ans, b[i - 1]);
        }
    }

    // If no valid insertion found, output -1
    if (ans == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
}

/*
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
