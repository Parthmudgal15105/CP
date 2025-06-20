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
    // We perform c copy-paste ops on string s of initial length n.
    // For op i (1…c) copying [l_i, r_i] (1-based) we record:
    //   left[i]  = starting index of this segment in the new string (0-based)
    //   right[i] = one past its end
    //   diff[i]  = left[i] - (l_i-1), so an index k in [left[i],right[i])
    //              maps back to k - diff[i] in the original/source string.
    //
    // To answer a query k (1-based), we:
    // 1) convert to 0-based: k--
    // 2) walk operations in reverse (i=c…1):
    //    if k lies in [left[i], right[i]) then set k = k - diff[i]
    // 3) after rollback, k points into the initial s, so output s[k].
    //
    // This runs in O(c + q·c) per test case, with c≤40 and q≤1e4.

    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    vector<ll> left(c + 1), right(c + 1), diff(c + 1);
    left[0] = 0;
    right[0] = n;

    for (int i = 1; i <= c; ++i)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        left[i] = right[i - 1];
        right[i] = left[i] + (r - l + 1);
        diff[i] = left[i] - l;
    }

    while (q--)
    {
        ll k;
        cin >> k;
        k--;
        for (int i = c; i >= 1; --i)
        {
            if (k < left[i])
                continue;
            else
                k -= diff[i];
        }
        cout << s[k] << "\n";
    }
}
/*
One night, Mark realized that there is an essay due tomorrow. He hasn't written anything yet, so Mark decided to randomly copy-paste substrings from the prompt to make the essay.

More formally, the prompt is a string s
 of initial length n
. Mark will perform the copy-pasting operation c
 times. Each operation is described by two integers l
 and r
, which means that Mark will append letters slsl+1…sr
 to the end of string s
. Note that the length of s
 increases after this operation.

Of course, Mark needs to be able to see what has been written. After copying, Mark will ask q
 queries: given an integer k
, determine the k
-th letter of the final string s
.

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases.

The first line of each test case contains three integers n
, c
, and q
 (1≤n≤2⋅105
, 1≤c≤40
, and 1≤q≤104
) — the length of the initial string s
, the number of copy-pasting operations, and the number of queries, respectively.

The second line of each test case contains a single string s
 of length n
. It is guaranteed that s
 only contains lowercase English letters.

The following c
 lines describe the copy-pasting operation. Each line contains two integers l
 and r
 (1≤l≤r≤1018
). It is also guaranteed that r
 does not exceed the current length of s
.

The last q
 lines of each test case describe the queries. Each line contains a single integer k
 (1≤k≤1018
). It is also guaranteed that k
 does not exceed the final length of s
.

It is guaranteed that the sum of n
 and q
 across all test cases does not exceed 2⋅105
 and 104
, respectively.

Output
For each query, print the k
-th letter of the final string s
.

Example
InputCopy
2
4 3 3
mark
1 4
5 7
3 8
1
10
12
7 3 3
creamii
2 3
3 4
2 9
9
11
12
OutputCopy
m
a
r
e
a
r
Note
In the first test case, the copy-paste process is as follows.

The first step is pasting string mark
 at the end, yielding the string markmark
.
The second step is pasting string mar
 at the end, yielding the string markmarkmar
.
The third step is pasting string rkmark
 at the end, yielding the string markmarkmarrkmark
.
In the second test case, the copy-paste process is as follows.

The first step is pasting string re
 at the end, yielding the string creamiire
.
The second step is pasting string ea
 at the end, yielding the string creamiireea
.
The third step is pasting string reamiire
 at the end, yielding the string creamiireeareamiire
.
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
