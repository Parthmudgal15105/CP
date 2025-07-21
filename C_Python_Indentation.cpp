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
const int MOD = 1e9 + 7;
/*----------------------------------------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    vector<char> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp[i][l]: number of ways to indent the program from line i onwards,
    //           given current indentation level is l
    vvi dp(n + 1, vi(n + 2));

    // Base case: at the end (after the last line), there is 1 way for any indentation level
    for (int l = 0; l <= n + 1; l++)
        dp[n][l] = 1;

    // Process lines from n-1 down to 1 (bottom-up DP)
    for (int i = n - 1; i >= 1; i--)
    {
        int sum = 0;
        // For each possible indentation level l
        for (int l = 0; l <= n; l++)
        {
            // sum accumulates dp[i + 1][l] + dp[i + 1][l - 1] + ... + dp[i + 1][0]
            // This is used for 's' (simple statement) cases
            sum += dp[i + 1][l];
            sum %= MOD;

            if (a[i] == 'f')
            {
                // If current line is a 'for', it must increase indentation by 1
                // So, next line must be at indentation l+1
                dp[i][l] = dp[i + 1][l + 1];
            }
            else
            {
                // If current line is a 'simple statement', it can be at current indentation
                // or any previous indentation (simulate dedent)
                dp[i][l] = sum;
            }
        }
    }

    // The answer is the number of ways to indent starting from line 1 at indentation 0
    cout << dp[1][0];
}

/*
In Python, code blocks don't have explicit begin/end or curly braces to mark beginning and end of the block. Instead, code blocks are defined by indentation.

We will consider an extremely simplified subset of Python with only two types of statements.

Simple statements are written in a single line, one per line. An example of a simple statement is assignment.

For statements are compound statements: they contain one or several other statements. For statement consists of a header written in a separate line which starts with "for" prefix, and loop body. Loop body is a block of statements indented one level further than the header of the loop. Loop body can contain both types of statements. Loop body can't be empty.

You are given a sequence of statements without indentation. Find the number of ways in which the statements can be indented to form a valid Python program.

Input
The first line contains a single integer N (1 ≤ N ≤ 5000) — the number of commands in the program. N lines of the program follow, each line describing a single command. Each command is either "f" (denoting "for statement") or "s" ("simple statement"). It is guaranteed that the last line is a simple statement.

Output
Output one line containing an integer - the number of ways the given sequence of statements can be indented modulo 109 + 7.

Examples
InputCopy
4
s
f
f
s
OutputCopy
1
InputCopy
4
f
s
f
s
OutputCopy
2
Note
In the first test case, there is only one way to indent the program: the second for statement must be part of the body of the first one.


simple statement
for statement
    for statement
        simple statement
In the second test case, there are two ways to indent the program: the second for statement can either be part of the first one's body or a separate statement following the first one.


for statement
    simple statement
    for statement
        simple statement
or


for statement
    simple statement
for statement
    simple statement
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
