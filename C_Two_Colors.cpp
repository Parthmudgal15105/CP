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
    // Read number of planks and number of colors
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    // Sort the paint capacities to enable binary search for counting eligible colors
    sort(a.begin(), a.end());

    ll ans = 0;
    // Loop through every possible partition of the fence into two continuous parts
    for (ll k = 1; k < n; k++)
    {
        // x: count of colors that can paint at least k planks
        ll x = m - (lower_bound(a.begin(), a.end(), k) - a.begin());
        // y: count of colors that can paint at least (n - k) planks
        ll y = m - (lower_bound(a.begin(), a.end(), n - k) - a.begin());

        // Add the ways based on the combination of eligible colors
        // Subtract min(x, y) to avoid double counting identical color assignments
        ans += x * y - min(x, y);
    }
    // Output the computed number of valid ways for this test case
    cout << ans << nl;
}

/*
Monocarp has installed a new fence at his summer house. The fence consists of n
 planks of the same size arranged in a row.

Monocarp decided that he would paint his fence according to the following rules:

each plank of the fence will be painted in exactly one color;
the number of different colors that the planks will be painted in is exactly two;
the planks of the fence that are painted in the same color must form a continuous sequence, meaning that for all pairs of planks painted in the same color, there will be no planks painted in a different color between them.
Monocarp has m
 different paints, and the paint of the i
-th color is sufficient to paint no more than ai
 planks of the fence. Monocarp will not buy any additional paints.

Your task is to determine the number of different ways to paint the fence that satisfy all of Monocarp's described wishes. Two ways to paint are considered different if there exists a plank that is painted in different colors in these two ways.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and m
 (2≤n,m≤2⋅105
) — the number of planks in the fence and the number of different colors of paint that Monocarp has.

The second line contains m
 integers a1,a2,…,am
 (1≤ai≤n
), where ai
 is the maximum number of planks that can be painted with the paint of color i
.

The sum of n
 over all test cases does not exceed 2⋅105
. The sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the number of different ways to paint the fence that satisfy all of Monocarp's described wishes.

Example
InputCopy
3
5 2
2 4
5 2
3 4
12 3
5 9 8
OutputCopy
4
6
22
Note
In the first test case, there are 4
 different ways to paint the fence (the sequences of color numbers in which the planks can be painted from left to right are listed below):

[1,2,2,2,2]
;
[1,1,2,2,2]
;
[2,2,2,1,1]
;
[2,2,2,2,1]
.
In the second test case, there are 6
 different ways to paint the fence (the sequences of color numbers in which the planks can be painted from left to right are listed below):

[1,2,2,2,2]
;
[1,1,2,2,2]
;
[1,1,1,2,2]
;
[2,2,1,1,1]
;
[2,2,2,1,1]
;
[2,2,2,2,1]
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
