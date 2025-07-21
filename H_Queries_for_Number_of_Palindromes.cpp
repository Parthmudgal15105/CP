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
    string s;
    cin >> s;
    int n = (int)s.size();

    // is[i][j] = true if s[i-1..j-1] is a palindrome (1-based indexing)
    vector<vector<bool>> is(n + 1, vector<bool>(n + 1, true));
    // ans[i][j] = number of palindromic substrings in s[i-1..j-1]
    vvi ans(n + 1, vi(n + 1));

    // Fill is[i][j]: check if substring s[i-1..j-1] is a palindrome
    // We process from larger i to smaller, so that is[i+1][j-1] is already computed
    for (int i = n; i >= 1; i--)

        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                is[i][j] = 1; // Single character is always a palindrome
                continue;
            }
            if (s[i - 1] != s[j - 1])
            {
                is[i][j] = 0; // If ends don't match, not a palindrome
            }
            else
            {
                // If ends match, check the inside substring
                is[i][j] = is[i + 1][j - 1];
            }
        }
}

// Fill ans[i][j]: number of palindromic substrings in s[i-1..j-1]
// Inclusion-exclusion principle is used to avoid double counting
for (int i = n; i >= 1; i--)
{
    for (int j = i; j <= n; j++)
    {
        if (i == j)
        {
            ans[i][j] = 1; // Only one substring (the character itself)
            continue;
        }
        ans[i][j] = is[i][j]; // 1 if s[i-1..j-1] is a palindrome, else 0
        // Add palindromes in [i+1, j] and [i, j-1], subtract overlap [i+1, j-1]
        ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
    }
}

int q;
cin >> q;
while (q--)
{
    int l, r;
    cin >> l >> r;
    // Output the number of palindromic substrings in s[l-1..r-1]
    cout << ans[l][r] << nl;
}
}

/*
You've got a string s = s1s2... s|s| of length |s|, consisting of lowercase English letters. There also are q queries, each query is described by two integers li, ri (1 ≤ li ≤ ri ≤ |s|). The answer to the query is the number of substrings of string s[li... ri], which are palindromes.

String s[l... r] = slsl + 1... sr (1 ≤ l ≤ r ≤ |s|) is a substring of string s = s1s2... s|s|.

String t is called a palindrome, if it reads the same from left to right and from right to left. Formally, if t = t1t2... t|t| = t|t|t|t| - 1... t1.

Input
The first line contains string s (1 ≤ |s| ≤ 5000). The second line contains a single integer q (1 ≤ q ≤ 106) — the number of queries. Next q lines contain the queries. The i-th of these lines contains two space-separated integers li, ri (1 ≤ li ≤ ri ≤ |s|) — the description of the i-th query.

It is guaranteed that the given string consists only of lowercase English letters.

Output
Print q integers — the answers to the queries. Print the answers in the order, in which the queries are given in the input. Separate the printed numbers by whitespaces.

Examples
InputCopy
caaaba
5
1 1
1 4
2 3
4 6
4 5
OutputCopy
1
7
3
4
2
Note
Consider the fourth query in the first test case. String s[4... 6] = «aba». Its palindrome substrings are: «a», «b», «a», «aba».
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
