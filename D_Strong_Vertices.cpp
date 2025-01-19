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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> diff(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        diff[i] = a[i] - b[i];
        maxi = max(maxi, diff[i]);
    }
    int countMaxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == maxi)
            countMaxi++;
    }
    cout << countMaxi << endl;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == maxi)
            cout << (i + 1) << sp;
    }
    cout << endl;
}

/*
Given two arrays a
 and b
, both of length n
. Elements of both arrays indexed from 1
 to n
. You are constructing a directed graph, where edge from u
 to v
 (u≠v
) exists if au−av≥bu−bv
.

A vertex V
 is called strong if there exists a path from V
 to all other vertices.

A path in a directed graph is a chain of several vertices, connected by edges, such that moving from the vertex u
, along the directions of the edges, the vertex v
 can be reached.

Your task is to find all strong vertices.

For example, if a=[3,1,2,4]
 and b=[4,3,2,1]
, the graph will look like this:

The graph has only one strong vertex with number 4
Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — the length of a
 and b
.

The second line of each test case contains n
 integers a1,a2…an
 (−109≤ai≤109
) — the array a
.

The third line of each test case contains n
 integers b1,b2…bn
 (−109≤bi≤109
) — the array b
.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output two lines: in the first line, output the number of strong vertices, and in the second line, output all strong vertices in ascending order.

Example
InputCopy
5
4
3 1 2 4
4 3 2 1
5
1 2 4 1 2
5 2 3 3 1
2
1 2
2 1
3
0 2 1
1 3 2
3
5 7 4
-2 -3 -6
OutputCopy
1
4
2
3 5
1
2
3
1 2 3
2
2 3
Note
The first sample is covered in the problem statement.

For the second sample, the graph looks like this:

The graph has two strong vertices with numbers 3
 and 5
. Note that there is a bidirectional edge between vertices 3
 and 5
.
In the third sample, the vertices are connected by a single directed edge from vertex 2
 to vertex 1
, so the only strong vertex is 2
.

In the fourth sample, all vertices are connected to each other by bidirectional edges, so there is a path from every vertex to any other vertex.



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
