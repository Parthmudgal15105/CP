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
    ll k;
    cin >> k;

    // We want to construct exactly k pairs (i, j) such that
    // the Euclidean distance squared equals the Manhattan distance.
    // This happens if and only if the two points are on the same row or column.
    // The easiest way is to put n points in a straight line (row or column).
    // For n points in a line, number of such pairs = n * (n-1) / 2.

    ll x = 0, y = 0;
    vector<pair<ll, ll>> ans;

    ll n = 500; // Start with the maximum allowed points in a line
    while (k > 0)
    {
        ll get = n * (n - 1) / 2; // Number of pairs for n points in a line
        if (get > k)
        {
            // If too many pairs, try with fewer points
            n--;
            continue;
        }

        // Use this line, subtract the pairs from k
        k -= get;
        // Place n points in a new row (x increases each time)
        for (ll i = 0; i < n; i++)
        {
            ans.push_back({x, ++y}); // Place at (x, y), increment y for each point
        }
        ++x; // Move to next row for next group of points (to keep all points distinct)
    }

    // Output the total number of points used
    cout << ans.size() << endl;
    // Output all the coordinates
    for (auto [x, y] : ans)
    {
        cout << x << " " << y << endl;
    }
}

/*
Akito decided to study a new powerful spell. Since it possesses immeasurable strength, it certainly requires a lot of space and careful preparation. For this, Akito went out into the field. Let's represent the field as a Cartesian coordinate system.

For the spell, Akito needs to place 0≤n≤500
 staffs at distinct integer coordinates in the field such that there will be exactly k
 pairs (i,j)
 such that 1≤i<j≤n
 and ρ(i,j)=d(i,j)
.

Here, for two points with integer coordinates a=(xa,ya)
 and b=(xb,yb)
, ρ(a,b)=(xa−xb)2+(ya−yb)2−−−−−−−−−−−−−−−−−−√
 and d(a,b)=|xa−xb|+|ya−yb|
.

Input
The first line of input contains a single number t
 (1≤t≤1000
) — the number of test cases.

In the only line of each test case, there is a single number k
 (0≤k≤105
) — the number of pairs of staffs for which the equality ρ(i,j)=d(i,j)
 must hold.

Output
For each test case, the first line of output should print the number n
 (0≤n≤500
) — the number of placed staffs.

In the following n
 lines, pairs of integers xi,yi
 (−109≤xi,yi≤109)
 should be printed — the coordinates of the i
-th staff. The points in which staffs stand must be distinct.

Example
InputCopy
3
0
2
5
OutputCopy
6
69 52
4 20
789 9308706
1337 1337
-1234 -5678
23456178 707
10
-236 -346262358
273568 6435267
2365437 31441367
246574 -45642372
-236 56
4743623 -192892
10408080 -8173135
-237415357 31441367
-78125638 278
56 143231
5
1 1
2 1
1 5
3 5
1 10


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
