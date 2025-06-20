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
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Sort weights in non-decreasing order
    sort(all(v));

    ll ans = 0;
    // Pattern 1:
    // Consider splitting so that the two "middle" bricks are v[i] and v[i+1],
    // and the third brick is the heaviest v[n-1].
    // Bu Dengklek will pick:
    //   from bag1: v[i]  (the best choice within that bag),
    //   from bag2: v[i+1],
    //   from bag3: v[n-1].
    // Score = |v[i+1] - v[i]| + |v[n-1] - v[i]|
    //       = (v[i+1] - v[i]) + (v[n-1] - v[i])
    for (ll i = 0; i < n - 1; i++)
    {
        ans = max(ans, (v[i + 1] - v[i]) + (v[n - 1] - v[i]));
    }

    // Pattern 2:
    // Consider splitting so that the two "middle" bricks are v[i] and v[i+1],
    // and the third brick is the lightest v[0].
    // Bu Dengklek will pick:
    //   from bag1: v[0],
    //   from bag2: v[i],
    //   from bag3: v[i+1].
    // Score = |v[i+1] - v[i]| + |v[i+1] - v[0]|
    //       = (v[i+1] - v[i]) + (v[i+1] - v[0])
    for (ll i = 1; i < n - 1; i++)
    {
        ans = max(ans, (v[i + 1] - v[i]) + (v[i + 1] - v[0]));
    }

    cout << ans << nl;
}

/*
There are n
 bricks numbered from 1
 to n
. Brick i
 has a weight of ai
.

Pak Chanek has 3
 bags numbered from 1
 to 3
 that are initially empty. For each brick, Pak Chanek must put it into one of the bags. After this, each bag must contain at least one brick.

After Pak Chanek distributes the bricks, Bu Dengklek will take exactly one brick from each bag. Let wj
 be the weight of the brick Bu Dengklek takes from bag j
. The score is calculated as |w1−w2|+|w2−w3|
, where |x|
 denotes the absolute value of x
.

It is known that Bu Dengklek will take the bricks in such a way that minimises the score. What is the maximum possible final score if Pak Chanek distributes the bricks optimally?

Input
Each test contains multiple test cases. The first line contains an integer t
 (1≤t≤2⋅104
) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer n
 (3≤n≤2⋅105
) — the number of bricks.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the weights of the bricks.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a line containing an integer representing the maximum possible final score if Pak Chanek distributes the bricks optimally.

Example
InputCopy
3
5
3 1 5 2 3
4
17 8 19 45
8
265 265 265 265 265 265 265 265
OutputCopy
6
63
0
Note
In the first test case, one way of achieving a final score of 6
 is to do the following:

Put bricks 1
, 4
, and 5
 into bag 1
.
Put brick 3
 into bag 2
.
Put brick 2
 into bag 3
.
If Pak Chanek distributes the bricks that way, a way Bu Dengklek can take the bricks is:

Take brick 5
 from bag 1
.
Take brick 3
 from bag 2
.
Take brick 2
 from bag 3
.
The score is |a5−a3|+|a3−a2|=|3−5|+|5−1|=6
. It can be shown that Bu Dengklek cannot get a smaller score from this distribution.

It can be shown that there is no other distribution that results in a final score bigger than 6
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
