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
// bool isStable(vector<int> &a, int l, int r)
// {
//     vector<int> seg;
//     for (int i = l; i <= r; i++)
//     {
//         seg.push_back(a[i]);
//     }
//     // Check all possible combinations including repeats
//     for (int i = 0; i < seg.size(); i++)
//     {
//         for (int j = i; j < seg.size(); j++)
//         {
//             for (int k = j; k < seg.size(); k++)
//             {
//                 int x = seg[i], y = seg[j], z = seg[k];
//                 if (x + y <= z || y + z <= x || x + z <= y)
//                 {
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 2)
    {
        int x = a[0], y = a[1];
        if (x + x > y && y + y > x)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n"; // Can only partition as [x],[y]
        }
        return;
    }

    // For n ≥ 3, try to find any adjacent pair that forms stable segment
    for (int i = 0; i < n - 1; i++)
    {
        int x = a[i], y = a[i + 1];
        if (x + x > y && y + y > x)
        {
            cout << "YES\n"; // Found second valid partition
            return;
        }
    }

    cout << "NO\n"; // Could only find single-element partition
}

/*
Cocoly is given an array a1,a2,…,an
. Master calls a set of integers S
 stable if and only if, for any possible u
, v
, and w
 from the set S
 (note that u
, v
, and w
 do not necessarily have to be pairwise distinct), sticks of length u
, v
, and w
 can form a non-degenerate triangle∗
.

Cocoly is asked to partition the array a
 into several (possibly, 1
 or n
) non-empty continuous subsegments†
, such that: for each of the subsegments, the set containing all the elements in it is stable.

Master wants Cocoly to partition a
 in at least two different‡
 ways. You have to help him determine whether it is possible.

∗
A triangle with side lengths x
, y
, and z
 is called non-degenerate if and only if:

x+y>z
,
y+z>x
, and
z+x>y
.
†
A sequence b
 is a subsegment of a sequence c
 if b
 can be obtained from c
 by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

‡
Two partitions are considered different if and only if at least one of the following holds:

the numbers of continuous subsegments split in two partitions are different;
there is an integer k
 such that the lengths of the k
-th subsegment in two partitions are different.
Input
Each test contains multiple test cases. The first line of the input contains a single integer t
 (1≤t≤200
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤200
) — the length of the array a
.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤105
) — the elements in the array a
.

Output
For each test case, print YES
 if there are at least two ways to partition a
, and NO
 otherwise.

You can output the answer in any case (upper or lower). For example, the strings yEs
, yes
, Yes
, and YES
 will be recognized as positive responses.

Example
InputCopy
5
4
2 3 5 7
4
115 9 2 28
5
8 4 1 6 2
6
1 5 4 1 4 7
2
100000 100000
OutputCopy
YES
NO
NO
YES
YES
Note
In the first test case, here are two possible partitions:

[2,3],[5,7]
, since
[2,3]
 is stable because sticks of lengths (2,2,2),(2,2,3),(2,3,3),(3,3,3)
 respectively can all form non-degenerate triangles.
[5,7]
 is stable because sticks of lengths (5,5,5),(5,5,7),(5,7,7),(7,7,7)
 respectively can all form non-degenerate triangles.
and [2],[3,5],[7]
, since
[2]
 is stable because sticks of lengths (2,2,2)
 respectively can form a non-degenerate triangle.
[3,5]
 is stable because sticks of lengths (3,3,3),(3,3,5),(3,5,5),(5,5,5)
 respectively can all form non-degenerate triangles.
[7]
 is stable because sticks of lengths (7,7,7)
 respectively can form a non-degenerate triangle.
Note that some other partitions also satisfy the constraints, such as [2],[3],[5],[7]
 and [2],[3],[5,7]
.

In the second test case, Cocoly can only partition each element as a single subsegment, resulting in [115],[9],[2],[28]
. Since we only have one possible partition, the answer is NO
.

In the third test case, please note that the partition [8,4],[1],[6],[2]
 does not satisfy the constraints, because {8,4}
 is not a stable set: sticks of lengths 4
, 4
, and 8
 cannot form a non-degenerate triangle.
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
