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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> grid(n, vector<ll>(m));
    vector<ll> v(n * m + 5, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            v[grid[i][j]] = 1;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i + 1 < n && grid[i][j] == grid[i + 1][j])
            {
                v[grid[i][j]]++;
            }

            if (j + 1 < m && grid[i][j] == grid[i][j + 1])
            {
                v[grid[i][j]]++;
            }
        }
    }

    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for (ll i = 1; i < v.size(); i++)
    {
        ans += min(2ll, v[i]);
    }

    cout << ans << endl;
    return;
}

/*
You are given a table of n
 rows and m
 columns. Initially, the cell at the i
-th row and the j
-th column has color ai,j
.

Let's say that two cells are strangers if they don't share a side. Strangers are allowed to touch with corners.

Let's say that the set of cells is a set of strangers if all pairs of cells in the set are strangers. Sets with no more than one cell are sets of strangers by definition.

In one step, you can choose any set of strangers such that all cells in it have the same color and paint all of them in some other color. You can choose the resulting color.

What is the minimum number of steps you need to make the whole table the same color?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. Next, t
 cases follow.

The first line of each test case contains two integers n
 and m
 (1≤n≤m≤700
) — the number of rows and columns in the table.

The next n
 lines contain the colors of cells in the corresponding row ai,1,…,ai,m
 (1≤ai,j≤nm
).

It's guaranteed that the total sum of nm
 doesn't exceed 5⋅105
 over all test cases.

Output
For each test case, print one integer — the minimum number of steps to paint all cells of the table the same color.

Example
InputCopy
4
1 1
1
3 3
1 2 1
2 3 2
1 3 1
1 6
5 4 5 4 4 5
3 4
1 4 2 2
1 4 3 5
6 6 3 5
OutputCopy
0
2
1
10
Note
In the first test case, the table is painted in one color from the start.

In the second test case, you can, for example, choose all cells with color 1
 and paint them in 3
. Then choose all cells with color 2
 and also paint them in 3
.

In the third test case, you can choose all cells with color 5
 and paint them in color 4
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
