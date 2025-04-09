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
    int n, m;
    cin >> n >> m;
    vector<ll> c(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    vector<pair<ll, ll>> pts;
    for (int i = 0; i < n; i++)
    {
        for (ll x = c[i] - r[i]; x <= c[i] + r[i]; x++)
        {
            ll dx = x - c[i];
            ll rem = r[i] * r[i] - dx * dx;

            ll limit = floor(sqrt(rem));
            for (ll y = -limit; y <= limit; y++)
            {
                pts.push_back({x, y});
            }
        }
    }

    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    cout << pts.size() << nl;
}

/*
The pink soldiers drew n
 circles with their center on the x
-axis of the plane. Also, they have told that the sum of radii is exactly m
∗
.

Please find the number of integer points inside or on the border of at least one circle. Formally, the problem is defined as follows.

You are given an integer sequence x1,x2,…,xn
 and a positive integer sequence r1,r2,…,rn
, where it is known that ∑ni=1ri=m
.

You must count the number of integer pairs (x,y)
 that satisfy the following condition.

There exists an index i
 such that (x−xi)2+y2≤r2i
 (1≤i≤n
).
∗
Is this information really useful? Don't ask me; I don't really know.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n≤m≤2⋅105
).

The second line of each test case contains x1,x2,…,xn
 — the centers of the circles (−109≤xi≤109
).

The third line of each test case contains r1,r2,…,rn
 — the radii of the circles (1≤ri
, ∑ni=1ri=m
).

It is guaranteed that the sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the number of integer points satisfying the condition on a separate line.

Example
InputCopy
4
2 3
0 0
1 2
2 3
0 2
1 2
3 3
0 2 5
1 1 1
4 8
0 5 10 15
2 2 2 2
OutputCopy
13
16
14
52
Note
On the first test case, the circle with r1=1
 is completely inside the circle with r2=2
. Therefore, you only have to count the number of integer points inside the latter. There are 13
 integer points such that x2+y2≤22
, so the answer is 13
.

On the second test case, the circle with r1=1
 is not completely inside the circle with r2=2
. There are 3
 additional points that are inside the first circle but not inside the second circle, so the answer is 3+13=16
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
