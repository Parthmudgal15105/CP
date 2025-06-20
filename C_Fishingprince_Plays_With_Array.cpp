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

/**
 * This function transforms the array into a canonical form that's invariant under the allowed operations
 *
 * Key insight: The two operations (splitting elements divisible by m, combining m equal elements)
 * are inverses of each other. This means we can represent each element as (base, count) where:
 * - base is the value after dividing out all factors of m
 * - count is the original coefficient (multiplied by powers of m)
 *
 * For example, with m=3:
 * - 12 becomes (4, 3) since 12 = 4 × 3¹
 * - 9 becomes (1, 9) since 9 = 1 × 3²
 *
 * Adjacent elements with the same base can be combined, as they could be created/merged
 * using the allowed operations.
 */
vector<array<ll, 2>> process(vector<ll> &v, ll m)
{
    ll n = v.size();
    vector<array<ll, 2>> res;
    for (ll i = 0; i < n; i++)
    {
        ll x = v[i], cnt = 1;
        // Extract all factors of m from x
        while (x % m == 0)
        {
            x /= m;
            cnt *= m; // Accumulate the power of m
        }
        // If this has the same base as the previous element, combine them
        if (!res.empty() && res.back()[0] == x)
        {
            res.back()[1] += cnt;
        }
        else
        {
            res.push_back({x, cnt}); // Store as [base, coefficient]
        }
    }
    return res;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    // The rest of the function will:
    // 1. Read array b
    // 2. Process both arrays to their canonical forms
    // 3. Compare the canonical forms - if they match, the transformation is possible

    ll k;
    cin >> k;
    vector<ll> b(k);
    for (ll i = 0; i < k; i++)
        cin >> b[i];

    vector<array<ll, 2>> pa = process(a, m);
    vector<array<ll, 2>> pb = process(b, m);

    if (pa == pb)
        cout << "Yes\n";
    else
        cout << "No\n";
}

/*
Fishingprince is playing with an array [a1,a2,…,an]
. He also has a magic number m
.

He can do the following two operations on it:

Select 1≤i≤n
 such that ai
 is divisible by m
 (that is, there exists an integer t
 such that m⋅t=ai
). Replace ai
 with m
 copies of aim
. The order of the other elements doesn't change. For example, when m=2
 and a=[2,3]
 and i=1
, a
 changes into [1,1,3]
.
Select 1≤i≤n−m+1
 such that ai=ai+1=⋯=ai+m−1
. Replace these m
 elements with a single m⋅ai
. The order of the other elements doesn't change. For example, when m=2
 and a=[3,2,2,3]
 and i=2
, a
 changes into [3,4,3]
.
Note that the array length might change during the process. The value of n
 above is defined as the current length of the array (might differ from the n
 in the input).

Fishingprince has another array [b1,b2,…,bk]
. Please determine if he can turn a
 into b
 using any number (possibly zero) of operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). Description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n≤5⋅104
, 2≤m≤109
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
).

The third line of each test case contains one integer k
 (1≤k≤5⋅104
).

The fourth line of each test case contains k
 integers b1,b2,…,bk
 (1≤bi≤109
).

It is guaranteed that the sum of n+k
 over all test cases does not exceed 2⋅105
.

Output
For each testcase, print Yes if it is possible to turn a
 into b
, and No otherwise. You can print each letter in any case (upper or lower).

Example
InputCopy
5
5 2
1 2 2 4 2
4
1 4 4 2
6 2
1 2 2 8 2 2
2
1 16
8 3
3 3 3 3 3 3 3 3
4
6 6 6 6
8 3
3 9 6 3 12 12 36 12
16
9 3 2 2 2 3 4 12 4 12 4 12 4 12 4 4
8 3
3 9 6 3 12 12 36 12
7
12 2 4 3 4 12 56
OutputCopy
Yes
Yes
No
Yes
No
Note
In the first test case of the sample, we can do the second operation with i=2
: [1,2,2,4,2]→[1,4,4,2]
.

In the second testcase of the sample, we can:

do the second operation with i=2
: [1,2,2,8,2,2]→[1,4,8,2,2]
.
do the second operation with i=4
: [1,4,8,2,2]→[1,4,8,4]
.
do the first operation with i=3
: [1,4,8,4]→[1,4,4,4,4]
.
do the second operation with i=2
: [1,4,4,4,4]→[1,8,4,4]
.
do the second operation with i=3
: [1,8,4,4]→[1,8,8]
.
do the second operation with i=2
: [1,8,8]→[1,16]
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
