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
    // Input size of adjacency matrix
    ll n;
    cin >> n;

    // Read the adjacency matrix where '1' means edge exists between vertices
    vector<string> adj(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> adj[i];
    }

    // ans: stores final permutation
    // l,r: track left and right boundaries for each position
    vi ans(n);
    vi l(n, 0);     // Initialize left boundaries to 0
    vi r(n, n - 1); // Initialize right boundaries to n-1

    // Process each vertex to find its position in permutation
    for (ll i = 0; i < n; i++)
    {
        // Count how many edges vertex i has with vertices in same boundary range
        ll cnt = 0;
        for (ll j = 0; j < n; j++)
        {
            // Check if j is in same boundary range and has edge with i
            if (l[j] == l[i] && r[j] == r[i] && adj[i][j] == '1')
            {
                cnt++;
            }
        }

        // Calculate position for vertex i
        // pos = right boundary - number of larger elements
        ll pos = r[i] - cnt;
        ans[pos] = i + 1;

        // Update boundaries for remaining vertices
        for (ll j = 0; j < n; j++)
        {
            if (l[j] == l[i] && r[j] == r[i] && i != j)
            {
                if (adj[i][j] == '0')
                {
                    // If no edge exists, j must be smaller than i
                    r[j] = pos - 1;
                }
                else
                {
                    // If edge exists, j must be larger than i
                    l[j] = pos + 1;
                }
            }
        }
        // Lock position for vertex i
        l[i] = r[i] = pos;
    }

    // Print the reconstructed permutation
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i + 1 < n ? ' ' : '\n');
    }

    /*
    Detailed Example:
    For n=3 and adjacency matrix:
    0 1 0
    1 0 1
    0 1 0

    Initial state:
    l = [0,0,0], r = [2,2,2]

    i=0: cnt=1 (one '1' in row)
    pos = 2-1 = 1
    ans[1] = 1
    Update boundaries...

    i=1: cnt=2 (two '1's in row)
    pos = 2-2 = 0
    ans[0] = 2
    Update boundaries...

    i=2: remaining position
    ans[2] = 3

    Final permutation: [2,1,3]
    */
}

/*
You are given an undirected graph with n
 vertices, labeled from 1
 to n
. This graph encodes a hidden permutation∗
 p
 of size n
. The graph is constructed as follows:

For every pair of integers 1≤i<j≤n
, an undirected edge is added between vertex pi
 and vertex pj
 if and only if pi<pj
. Note that the edge is not added between vertices i
 and j
, but between the vertices of their respective elements. Refer to the notes section for better understanding.
Your task is to reconstruct and output the permutation p
. It can be proven that permutation p
 can be uniquely determined.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤1000
).

The i
-th of the next n
 lines contains a string of n
 characters gi,1gi,2…gi,n
 (gi,j=0
 or gi,j=1
) — the adjacency matrix. gi,j=1
 if and only if there is an edge between vertex i
 and vertex j
.

It is guaranteed that there exists a permutation p
 which generates the given graph. It is also guaranteed that the graph is undirected and has no self-loops, meaning gi,j=gj,i
 and gi,i=0
.

It is guaranteed that the sum of n
 over all test cases does not exceed 1000
.

Output
For each test case, output n
 integers p1,p2,…,pn
 representing the reconstructed permutation.

Example
InputCopy
3
1
0
5
00101
00101
11001
00001
11110
6
000000
000000
000000
000000
000000
000000
OutputCopy
1
4 2 1 3 5
6 5 4 3 2 1
Note
In the first case p=[1]
. Since there are no pairs 1≤i<j≤n
, there are no edges in the graph.

The graph in the second case is shown below. For example, when we choose i=3
 and j=4
, we add an edge between vertices pi=1
 and pj=3
, because pi<pj
. However, when we choose i=2
 and j=3
, pi=2
 and pj=1
, so pi<pj
 doesn't hold. Therefore, we don't add an edge between 2
 and 1
.



In the third case, there are no edges in the graph, so there are no pairs of integers 1≤i<j≤n
 such that pi<pj
. Therefore, p=[6,5,4,3,2,1]
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
