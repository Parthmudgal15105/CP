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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
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
    string a;
    cin >> a;
    int n = a.size();
    if (n == 1)
    {
        cout << -1 << nl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
        {
            cout << a[i] << a[i] << nl;
            return;
        }
        if (a[i - 1] != a[i] && i + 1 < n && a[i + 1] != a[i] && a[i - 1] != a[i + 1])
        {
            cout << a[i - 1] << a[i] << a[i + 1] << nl;
            return;
        }
    }
    cout << -1 << nl;
}

/*
For a string p
, let f(p)
 be the number of distinct non-empty substrings∗
 of p
.

Shohag has a string s
. Help him find a non-empty string p
 such that p
 is a substring of s
 and f(p)
 is even or state that no such string exists.

∗
A string a
 is a substring of a string b
 if a
 can be obtained from b
 by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first and only line of each test case contains a string s
 (1≤|s|≤105
) consisting of lowercase English letters.

It is guaranteed that the sum of the length of s
 over all test cases doesn't exceed 3⋅105
.

Output
For each test case, print a non-empty string that satisfies the conditions mentioned in the statement, or −1
 if no such string exists. If there are multiple solutions, output any.

Example
InputCopy
5
dcabaac
a
youknowwho
codeforces
bangladesh
OutputCopy
abaa
-1
youknowwho
eforce
bang
Note
In the first test case, we can set p=
 abaa because it is a substring of s
 and the distinct non-empty substrings of p
 are a, b, aa, ab, ba, aba, baa and abaa, so it has a total of 8
 distinct substrings which is even.

In the second test case, we can only set p=
 a but it has one distinct non-empty substring but this number is odd, so not valid.

In the third test case, the whole string contains 52
 distinct non-empty substrings, so the string itself is a valid solution.
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
