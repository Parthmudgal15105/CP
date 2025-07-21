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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vi prefix(n + 1), dp(n + 1); // prefix[i]: number of '1's in s[0..i], dp[i]: min cost to make s[0..i] k-periodic ending at i

    // Build prefix sum of '1's for fast range queries
    for (int i = 0; i < n; i++)
    {
        prefix[i] = (i > 0 ? prefix[i - 1] : 0); // carry forward previous count
        if (s[i] == '1')
            prefix[i]++; // increment if current is '1'
    }

    int ans = prefix[n - 1]; // start with all '1's flipped to '0' (worst case)

    for (int i = 0; i < n; i++)
    {
        int cost = (s[i] == '1' ? 0 : 1); // cost to make s[i] '1' (flip if it's '0')

        // Case 1: Make s[i] '1', flip all '1's before i to '0'
        // dp[i] = cost to flip s[i] + cost to flip all '1's before i
        dp[i] = cost + (i > 0 ? prefix[i - 1] : 0);

        // Case 2: Use dp[i-k] and flip all '1's between i-k+1 and i-1 to '0'
        // dp[i-k]: min cost up to i-k, then flip all '1's in (i-k, i) except s[i]
        if (i >= k)
        {
            // prefix[i-1] - prefix[i-k]: number of '1's between i-k and i-1
            dp[i] = min(dp[i], cost + dp[i - k] + prefix[i - 1] - prefix[i - k]);
        }

        // Update answer: dp[i] + number of '1's after i (flip all '1's after i to '0')
        ans = min(ans, dp[i] + prefix[n - 1] - prefix[i]);
    }
    cout << ans << nl;
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
