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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<ll> pairs;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            pairs.push_back(arr[i]);
            i++;
        }
    }
    if (pairs.size() >= 2)
    {
        cout << pairs[0] << " " << pairs[0] << " " << pairs[1] << " " << pairs[1] << "\n";
        return;
    }
    if (pairs.size() == 1)
    {
        ll c = pairs[0];
        vector<ll> temp;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && arr[i] == arr[i + 1] && arr[i] == c)
            {
                i++;
                continue;
            }
            temp.push_back(arr[i]);
        }
        for (int i = 0; i < temp.size() - 1; i++)
        {
            ll a = temp[i], b = temp[i + 1];
            if (abs(a - b) < 2LL * c)
            {
                cout << a << " " << b << " " << c << " " << c << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

/*
Kevin has n
 sticks with length a1,a2,…,an
.

Kevin wants to select 4
 sticks from these to form an isosceles trapezoid∗
 with a positive area. Note that rectangles and squares are also considered isosceles trapezoids. Help Kevin find a solution. If no solution exists, output −1
.

∗
An isosceles trapezoid is a convex quadrilateral with a line of symmetry bisecting one pair of opposite sides. In any isosceles trapezoid, two opposite sides (the bases) are parallel, and the two other sides (the legs) are of equal length.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (4≤n≤2⋅105
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤108
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 4
 integers — the lengths of sticks. If no solution exists, output −1
.

If there are multiple solutions, print any of them.

Example
InputCopy
7
4
5 5 5 10
4
10 5 10 5
4
1 2 3 4
4
1 1 1 3
6
4 2 1 5 7 1
6
10 200 30 300 30 100
4
100000000 100000000 1 2
OutputCopy
5 5 5 10
5 5 10 10
-1
-1
1 1 4 5
-1
100000000 100000000 1 2
Note
In the first test case, you can form an isosceles trapezoid with bases of length 5
 and 10
, and two legs of length 5
.

In the second test case, you can form an isosceles trapezoid with two bases of length 5
 and two legs of length 10
. A rectangle is considered an isosceles trapezoid here.

In the third test case, there are no sticks with the same length. It's impossible to form an isosceles trapezoid.

In the fourth test case, it's impossible to form an isosceles trapezoid with a positive area.

ANSWER
Let a
 and b
 be the lengths of the two bases, and let c
 be the length of the two legs. A necessary and sufficient condition for forming an isosceles trapezoid with a positive area is |a−b|<2c
, as the longest edge must be shorter than the sum of the other three edges.

To determine whether an isosceles trapezoid can be formed, consider the following cases:

If there are two distinct pairs of identical numbers that do not overlap, these pairs can always form an isosceles trapezoid.
If there are no pairs of identical numbers, it is impossible to form an isosceles trapezoid.
If there is exactly one pair of identical numbers, denoted by c
, we will use them as the legs. Remove this pair and check whether there exist two other numbers whose difference is less than 2c
. This can be efficiently done by sorting the remaining numbers and checking adjacent pairs.
The time complexity of this approach is O(nlogn)
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
