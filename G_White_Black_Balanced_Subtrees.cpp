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
ll n;
ll ans;
string s;
vll root;
vector<bool> check;
vector<vector<ll>> graph;
pair<ll, ll> dfs(ll root)
{
    if (check[root])
    {
        return {0, 0};
    }
    check[root] = true;
    ll b = 0, w = 0;
    if (s[root - 1] == 'B')
    {
        b++;
    }
    else
    {
        w++;
    }
    for (int i = 0; i < graph[root].size(); i++)
    {
        if (check[graph[root][i]] == false)
        {
            pair<ll, ll> temp = dfs(graph[root][i]);
            b += temp.first;
            w += temp.second;
        }
    }
    if (b == w)
    {
        ans++;
    }
    return {b, w};
}
ll solve()
{
    cin >> n;
    root.resize(n + 1, 0);
    graph.resize(n + 1, vector<ll>());
    check.resize(n + 1, false);
    root[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        cin >> root[i];
        graph[root[i]].push_back(i);
        graph[i].push_back(root[i]);
    }
    cin >> s;
    ans = 0;
    dfs(1);
    cout << ans << endl;
    s.clear();
    ans = 0;
    n = 0;
    graph.clear();
    root.clear();
    check.clear();
    return 0;
}

/*
You are given a rooted tree consisting of n
 vertices numbered from 1
 to n
. The root is vertex 1
. There is also a string s
 denoting the color of each vertex: if si=B
, then vertex i
 is black, and if si=W
, then vertex i
 is white.

A subtree of the tree is called balanced if the number of white vertices equals the number of black vertices. Count the number of balanced subtrees.

A tree is a connected undirected graph without cycles. A rooted tree is a tree with a selected vertex, which is called the root. In this problem, all trees have root 1
.

The tree is specified by an array of parents a2,…,an
 containing n−1
 numbers: ai
 is the parent of the vertex with the number i
 for all i=2,…,n
. The parent of a vertex u
 is a vertex that is the next vertex on a simple path from u
 to the root.

The subtree of a vertex u
 is the set of all vertices that pass through u
 on a simple path to the root. For example, in the picture below, 7
 is in the subtree of 3
 because the simple path 7→5→3→1
 passes through 3
. Note that a vertex is included in its subtree, and the subtree of the root is the entire tree.

The picture shows the tree for n=7
, a=[1,1,2,3,3,5]
, and s=WBBWWBW
. The subtree at the vertex 3
 is balanced.
Input
The first line of input contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains an integer n
 (2≤n≤4000
) — the number of vertices in the tree.

The second line of each test case contains n−1
 integers a2,…,an
 (1≤ai<i
) — the parents of the vertices 2,…,n
.

The third line of each test case contains a string s
 of length n
 consisting of the characters B
 and W
 — the coloring of the tree.

It is guaranteed that the sum of the values n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of balanced subtrees.

Example
InputCopy
3
7
1 1 2 3 3 5
WBBWWBW
2
1
BW
8
1 2 3 4 5 6 7
BWBWBWBW
OutputCopy
2
1
4
Note
The first test case is pictured in the statement. Only the subtrees at vertices 2
 and 3
 are balanced.

In the second test case, only the subtree at vertex 1
 is balanced.

In the third test case, only the subtrees at vertices 1
, 3
, 5
, and 7
 are balanced.
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
