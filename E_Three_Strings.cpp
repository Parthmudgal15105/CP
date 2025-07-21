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
int minChangesDP(const string &a, const string &b, const string &c)
{
    int n = a.size(), m = b.size();
    // dp[i][j] = minimum changes needed to form c[0..i+j-1] using a[0..i-1] and b[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0; // No characters taken from a or b, so no changes needed

    // Try all possible ways to interleave a and b to form c
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            int idx = i + j; // Current position in c
            if (idx >= c.size())
                continue;
            // Option 1: Take next character from a (if available)
            if (i < n)
            {
                int cost = 0;
                if (a[i] != c[idx])
                    cost = 1; // Need to change c[idx] to match a[i]
                // Update dp for taking a[i]
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost);
            }
            // Option 2: Take next character from b (if available)
            if (j < m)
            {
                int cost = 0;
                if (b[j] != c[idx])
                    cost = 1; // Need to change c[idx] to match b[j]
                // Update dp for taking b[j]
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost);
            }
        }
    }
    // The answer is the minimum changes needed to use all of a and b to form c
    return dp[n][m];
}

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    // Output the minimum number of changes needed
    cout << minChangesDP(a, b, c) << '\n';
}

/*
You are given three strings: a
, b
, and c
, consisting of lowercase Latin letters. The string c
 was obtained in the following way:

At each step, either string a
 or string b
 was randomly chosen, and the first character of the chosen string was removed from it and appended to the end of string c
, until one of the strings ran out. After that, the remaining characters of the non-empty string were added to the end of c
.
Then, a certain number of characters in string c
 were randomly changed.
For example, from the strings a=abra
 and b=cada
, without character replacements, the strings caabdraa
, abracada
, acadabra
 could be obtained.

Find the minimum number of characters that could have been changed in string c
.

Input
The first line of the input contains a single integer t
 (1≤t≤103
) — the number of test cases.

The first line of each test case contains one string of lowercase Latin letters a
 (1≤|a|≤103
) — the first string, where |a|
 denotes the length of string a
.

The second line of each test case contains one string of lowercase Latin letters b
 (1≤|b|≤103
) — the second string, where |b|
 denotes the length of string b
.

The third line of each test case contains one string of lowercase Latin letters c
 (|c|=|a|+|b|
) — the third string.

It is guaranteed that the sum of |a|
 across all test cases does not exceed 2⋅103
. Also, the sum of |b|
 across all test cases does not exceed 2⋅103
.

Output
For each test case, output a single integer — the minimum number of characters that could have been changed in string c
.

Example
InputCopy
7
a
b
cb
ab
cd
acbd
ab
ba
aabb
xxx
yyy
xyxyxy
a
bcd
decf
codes
horse
codeforces
egg
annie
egaegaeg
OutputCopy
1
0
2
0
3
2
3
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
