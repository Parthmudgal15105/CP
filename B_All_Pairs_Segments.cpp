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
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;
    map<ll, ll> mp;

    // Main algorithm: Calculate how many integer points are contained in exactly k segments
    // The map 'mp' will store: mp[k] = number of points contained in exactly k segments

    for (ll i = 0; i < n; i++)
    {
        // For each point v[i], calculate how many segments contain it
        // A point v[i] is contained in segments formed by:
        // - Points to the left (i+1 choices) and points to the right (n-i choices)
        // - Minus 1 because we don't count the point itself
        ll temp = (i + 1) * (n - i) - 1;

        // Increment count for points that are contained in exactly 'temp' segments
        mp[temp]++;

        // For points between v[i-1] and v[i] (if i > 0)
        if (i > 0)
        {
            // Number of segments containing a point between v[i-1] and v[i]
            // These points are contained in segments formed by:
            // - i points to the left and (n-i) points to the right
            ll temp2 = (n - i) * i;

            // There are (v[i] - v[i-1] - 1) points between v[i-1] and v[i]
            // All these points are contained in exactly temp2 segments
            mp[temp2] += (v[i] - v[i - 1] - 1);
        }
    }

    // Process queries
    while (q--)
    {
        ll k;
        cin >> k;
        // Output how many points are contained in exactly k segments
        if (mp.find(k) == mp.end())
        {
            cout << 0 << " ";
        }
        else
            cout << mp[k] << " ";
    }
    cout << endl;
}

/*
You are given n
 points on the x
 axis, at increasing positive integer coordinates x1<x2<…<xn
.

For each pair (i,j)
 with 1≤i<j≤n
, you draw the segment [xi,xj]
. The segments are closed, i.e., a segment [a,b]
 contains the points a,a+1,…,b
.

You are given q
 queries. In the i
-th query, you are given a positive integer ki
, and you have to determine how many points with integer coordinates are contained in exactly ki
 segments.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
, q
 (2≤n≤105
, 1≤q≤105
) — the number of points and the number of queries.

The second line of each test case contains n
 integers x1,x2,…,xn
 (1≤x1<x2<…<xn≤109
) — the coordinates of the n
 points.

The third line of each test case contains q
 integers k1,k2,…,kq
 (1≤ki≤1018
) — the parameters of the q
 queries.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
, and the sum of q
 over all test cases does not exceed 105
.

Output
For each test case, output a single line with q
 integers: the i
-th integer is the answer to the i
-th query.

Example
InputCopy
3
2 2
101 200
2 1
6 15
1 2 3 5 6 7
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
5 8
254618033 265675151 461318786 557391198 848083778
6 9 15 10 6 9 4 4294967300
OutputCopy
0 100
0 0 0 0 2 0 0 0 3 0 2 0 0 0 0
291716045 0 0 0 291716045 0 301749698 0
Note
In the first example, you only draw the segment [101,200]
. No point is contained in exactly 2
 segments, and the 100
 points 101,102,…,200
 are contained in exactly 1
 segment.

In the second example, you draw 15
 segments: [1,2],[1,3],[1,5],[1,6],[1,7],[2,3],[2,5],[2,6],[2,7],[3,5],[3,6],[3,7],[5,6],[5,7],[6,7]
. Points 1,7
 are contained in exactly 5
 segments; points 2,4,6
 are contained in exactly 9
 segments; points 3,5
 are contained in exactly 11
 segments.
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
