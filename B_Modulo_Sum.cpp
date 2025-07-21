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
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
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
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m; // Reduce each number modulo m (so all values are in [0, m-1])
    }
    // Pigeonhole principle: if n >= m, there must be a non-empty subset with sum % m == 0
    if (n >= m)
    {
        cyes;
        return;
    }
    // dp[i][j]: is it possible to get sum ≡ j (mod m) using the first i elements (with any non-empty subsequence)
    vector<vector<bool>> dp(n + 1, vector<bool>(m));
    dp[0][0] = true; // Base case: sum 0 is possible with empty subset

    // For each element, mark its own value as possible (single-element subsequence)
    for (int i = 1; i <= n; i++)
    {
        dp[i][a[i]] = 1;
    }

    // Build up the DP table
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j])
            {
                continue; // Already possible, skip
            }
            if (dp[i - 1][j])
            {
                dp[i][j] = dp[i - 1][j]; // If sum j was possible without a[i], it's still possible
                continue;
            }
            // If sum (j - a[i]) mod m was possible before, then by adding a[i], sum j is possible
            dp[i][j] = dp[i - 1][(j - a[i] + m) % m];
        }
    }
    // If sum 0 mod m is possible with any non-empty subsequence, print YES
    cout << (dp[n][0] ? "YES" : "NO");
}

/*
You are given a sequence of numbers a1, a2, ..., an, and a number m.

Check if it is possible to choose a non-empty subsequence aij such that the sum of numbers in this subsequence is divisible by m.

Input
The first line contains two numbers, n and m (1 ≤ n ≤ 106, 2 ≤ m ≤ 103) — the size of the original sequence and the number such that sum should be divisible by it.

The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 109).

Output
In the single line print either "YES" (without the quotes) if there exists the sought subsequence, or "NO" (without the quotes), if such subsequence doesn't exist.

Examples
InputCopy
3 5
1 2 3
OutputCopy
YES
InputCopy
1 6
5
OutputCopy
NO
InputCopy
4 6
3 1 1 3
OutputCopy
YES
InputCopy
6 6
5 5 5 5 5 5
OutputCopy
YES
Note
In the first sample test you can choose numbers 2 and 3, the sum of which is divisible by 5.

In the second sample test the single non-empty subsequence of numbers is a single number 5. Number 5 is not divisible by 6, that is, the sought subsequence doesn't exist.

In the third sample test you need to choose two numbers 3 on the ends.

In the fourth sample test you can take the whole subsequence.


 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
