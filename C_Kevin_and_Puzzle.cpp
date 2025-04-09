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
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/

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
    const long long mod = 998244353;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(2, 0));

    // dp[i][0] represents the number of configurations ending at i where person i is honest.
    // dp[i][1] represents the number of configurations ending at i where person i is a liar.

    // Base case: For the first person.
    dp[0][1] = 1; // A liar is always allowed, regardless of statement.
    if (a[0] == 0)
    {
        dp[0][0] = 1; // Honest if their statement matches: 0 liars on the left.
    }
    else
    {
        dp[0][0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        // When person i is set as a liar:
        // Since two liars can't be consecutive, the previous person must be honest.
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;

        // When person i is set as honest:
        // Their statement must be truthful regarding how many liars are to their left.
        // If a[i] equals a[i-1], then the number of liars remains the same.
        if (a[i] == a[i - 1])
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;

        // If a[i] equals a[i-2] + 1, this indicates that person i-1 was a liar,
        // increasing the liar count by one.
        if (i > 1 && a[i] == a[i - 2] + 1)
        {
            dp[i][0] = (dp[i][0] + dp[i - 2][0]) % mod;
        }
        else if (i == 1)
        {
            // Special case for the second person:
            // If the second person's statement is 1, it implies the first must be a liar.
            if (a[i] == 1)
                dp[i][0] = (dp[i][0] + 1) % mod;
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << nl;
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
