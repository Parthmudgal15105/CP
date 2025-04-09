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
bool check(ll x, ll k, string &s, vector<ll> &v)
{
    bool flag = false;
    ll ops = 0;

    // Loop through each cell in the strip.
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] <= x)
        {
            // This cell's penalty is within the allowed threshold.
            continue;
        }
        // If the cell should be blue and no operation is in progress, start an operation.
        if (s[i] == 'B' && !flag)
        {
            ops++;       // Increment the operation counter.
            flag = true; // Mark that we've started a painting operation.
        }
        else if (s[i] == 'R')
        {
            // End any currently active operation upon encountering a red cell.
            flag = false;
        }
        else
        {
            continue;
        }
    }
    // Return true if the total operations used does not exceed the allowed number k.
    if (ops <= k)
    {
        return true;
    }
    return false;
}

void solve()
{
    int n, k;
    cin >> n >> k; // Read the number of cells and the maximum allowed operations.

    string s;
    cin >> s; // Desired final colors for each cell ('R' or 'B').

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i]; // Read the penalty for each cell.
    }

    // Binary search setup:
    ll l = 0, r = 1e9, ans = r;
    while (l <= r)
    {
        ll mid = (l + r) / 2; // Candidate penalty threshold.

        // Check if it's possible to repaint with a maximum penalty mid.
        if (check(mid, k, s, v))
        {
            ans = mid;   // Update answer since mid is feasible.
            r = mid - 1; // Search for a possibly lower threshold.
        }
        else
        {
            l = mid + 1; // Increase the threshold if mid isn't feasible.
        }
    }
    cout << ans << nl; // Output the minimum achievable penalty.
}

/*
You are given a strip, consisting of n
 cells, all cells are initially colored red.

In one operation, you can choose a segment of consecutive cells and paint them blue. Before painting, the chosen cells can be either red or blue. Note that it is not possible to paint them red. You are allowed to perform at most k
 operations (possibly zero).

For each cell, the desired color after all operations is specified: red or blue.

It is clear that it is not always possible to satisfy all requirements within k
 operations. Therefore, for each cell, a penalty is also specified, which is applied if the cell ends up the wrong color after all operations. For the i
-th cell, the penalty is equal to ai
.

The penalty of the final painting is calculated as the maximum penalty among all cells that are painted the wrong color. If there are no such cells, the painting penalty is equal to 0
.

What is the minimum penalty of the final painting that can be achieved?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤3⋅105
; 0≤k≤n
) — the length of the strip and the maximum number of operations.

The second line contains a string s
, consisting of n
 characters 'R' and/or 'B'. 'R' means that the cell should be painted red. 'B' means that the cell should be painted blue.

The third line contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the penalty for each cell.

The sum of n
 over all test cases does not exceed 3⋅105
.

Output
For each test case, print a single integer — the minimum penalty of the final painting.

Example
InputCopy
5
4 1
BRBR
9 3 5 4
4 1
BRBR
9 5 3 4
4 2
BRBR
9 3 5 4
10 2
BRBRBBRRBR
5 1 2 4 5 3 6 1 5 4
5 5
RRRRR
5 3 1 2 4
OutputCopy
3
3
0
4
0
Note
In the first test case, you can paint the cells from 1
 to 3
. The painting will be BBBR. So, only cell 2
 is painted the wrong color. Therefore, the penalty for it is the final penalty and equals 3
.

In the second test case, the painting BBBR will now result in a penalty of 5
. However, if you paint the cells from 1
 to 1
, resulting in BRRR, then only cell 3
 is painted the wrong color. The final penalty is 3
.

In the third test case, you can paint the cells from 1
 to 1
 and from 3
 to 3
. Then all cells will be the correct color, the penalty equals 0
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
