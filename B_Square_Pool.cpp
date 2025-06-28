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
    int n, s;
    cin >> n >> s;
    int potted = 0;
    for (int i = 0; i < n; ++i)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        int tx, ty;
        // Calculate distance to wall in x direction
        if (dx == 1)
            tx = s - x;
        else
            tx = x;
        // Calculate distance to wall in y direction
        if (dy == 1)
            ty = s - y;
        else
            ty = y;
        // If both distances are equal, the ball will reach a corner (pocket)
        if (tx == ty)
            ++potted;
    }
    cout << potted << nl;
}

/*
Aryan and Harshith are playing pool in universe AX120 on a fixed square pool table of side s
 with pockets at its 4
 corners. The corners are situated at (0,0)
, (0,s)
, (s,0)
, and (s,s)
. In this game variation, n
 identical balls are placed on the table with integral coordinates such that no ball lies on the edge or corner of the table. Then, they are all simultaneously shot at 10100
 units/sec speed (only at 45
 degrees with the axes).

In universe AX120, balls and pockets are almost point-sized, and the collisions are elastic, i.e., the ball, on hitting any surface, bounces off at the same angle and with the same speed.


Harshith shot the balls, and he provided Aryan with the balls' positions and the angles at which he shot them. Help Aryan determine the number of balls potted into the pockets by Harshith.

It is guaranteed that multiple collisions do not occur at the same moment and position.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and s
 (1≤n≤103
, 2≤s≤109
) — the number of balls placed on the table and the side length of the square pool table.

The i
-th of the next n
 lines contains four integers dx
, dy
, xi
, and yi
 (dx,dy∈{−1,1}
, 0<xi,yi<s
) — the direction vectors of the launch on the X
-axis and Y
-axis respectively, and the coordinates of the location where the i
-th ball was placed. It is guaranteed that no two balls coincide at the initial moment.

It is also guaranteed that the sum of n
 over all test cases does not exceed 103
.

Output
For each test case, print a single integer — the number of balls potted in that game.

Example
InputCopy
2
1 2
1 1 1 1
5 4
1 -1 1 1
1 -1 2 2
-1 1 2 3
1 -1 1 3
-1 1 3 1
OutputCopy
1
3
Note
In the first test case, there is a single ball and it's shot directly towards the pocket at (2,2)
, thus potted.

In the second test case, the state progresses as
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
