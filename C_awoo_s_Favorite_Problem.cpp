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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    // 1) Quick check: if s and t are already identical, no moves are needed
    if (s == t)
    {
        cyes;
        return;
    }

    // 2) Remove all 'b's to compare only the relative order of 'a' and 'c'
    string s2, t2;
    for (char c : s)
        if (c != 'b')
            s2 += c;
    for (char c : t)
        if (c != 'b')
            t2 += c;

    // 3) If the filtered sequences differ, it's impossible to match
    if (s2 != t2)
    {
        cno;
        return;
    }

    // 4) Use two pointers to traverse s and t, skipping 'b's,
    //    and enforce movement constraints on 'a' and 'c'
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        // Skip over all 'b's in s
        while (i < n && s[i] == 'b')
            i++;
        // Skip over all 'b's in t
        while (j < n && t[j] == 'b')
            j++;

        if (i < n)
        {
            // 'a' can only move right: its original index in s must be ≤ that in t
            if (s[i] == 'a' && i > j)
            {
                cno;
                return;
            }
            // 'c' can only move left: its original index in s must be ≥ that in t
            if (s[i] == 'c' && i < j)
            {
                cno;
                return;
            }
            // Advance both pointers after validating the current character
            i++;
            j++;
        }
    }

    // 5) If all checks pass, transformation is possible
    cyes;
}

/*
You are given two strings s
 and t
, both of length n
. Each character in both string is 'a', 'b' or 'c'.

In one move, you can perform one of the following actions:

choose an occurrence of "ab" in s
 and replace it with "ba";
choose an occurrence of "bc" in s
 and replace it with "cb".
You are allowed to perform an arbitrary amount of moves (possibly, zero). Can you change string s
 to make it equal to string t
?

Input
The first line contains a single integer q
 (1≤q≤104
) — the number of testcases.

The first line of each testcase contains a single integer n
 (1≤n≤105
) — the length of strings s
 and t
.

The second line contains string s
 of length n
. Each character is 'a', 'b' or 'c'.

The third line contains string t
 of length n
. Each character is 'a', 'b' or 'c'.

The sum of n
 over all testcases doesn't exceed 105
.

Output
For each testcase, print "YES" if you can change string s
 to make it equal to string t
 by performing an arbitrary amount of moves (possibly, zero). Otherwise, print "NO".

Example
InputCopy
5
3
cab
cab
1
a
b
6
abbabc
bbaacb
10
bcaabababc
cbbababaac
2
ba
ab
OutputCopy
YES
NO
YES
YES
NO
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
