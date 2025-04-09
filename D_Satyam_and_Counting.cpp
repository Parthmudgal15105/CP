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
    ll n, ans = 0;
    cin >> n;

    map<pair<ll, ll>, ll> m;
    vector<ll> cnt(2);

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        m[{x, y}]++;
        cnt[y]++;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        ll x = it->first.first, y = it->first.second;
        if (m.count({x, 1 - y}))
        {
            ans += cnt[y] - 1;
        }
        if (m.count({x + 1, 1 - y}) && m.count({x - 1, 1 - y}))
            ans++;
    }
    cout << ans << nl;
}

/*
Satyam is given n
 distinct points on the 2D coordinate plane. It is guaranteed that 0≤yi≤1
 for all given points (xi,yi)
. How many different nondegenerate right triangles∗
 can be formed from choosing three different points as its vertices?

Two triangles a
 and b
 are different if there is a point v
 such that v
 is a vertex of a
 but not a vertex of b
.

∗
A nondegenerate right triangle has positive area and an interior 90∘
 angle.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains an integer n
 (3≤n≤2⋅105
) — the number of points.

The following n
 lines contain two integers xi
 and yi
 (0≤xi≤n
, 0≤yi≤1
) — the i
'th point that Satyam can choose from. It is guaranteed that all (xi,yi)
 are pairwise distinct.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
Output an integer for each test case, the number of distinct nondegenerate right triangles that can be formed from choosing three points.

Example
InputCopy
3
5
1 0
1 1
3 0
5 0
2 1
3
0 0
1 0
3 0
9
1 0
2 0
3 0
4 0
5 0
2 1
7 1
8 1
9 1
OutputCopy
4
0
8
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
