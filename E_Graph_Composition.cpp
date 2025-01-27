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
class UnionFind
{
private:
    vector<int> par;
    vector<int> sz;

public:
    UnionFind(int n)
    {
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }

    int find(int u)
    {
        // this optimisation was good.
        if (par[u] != par[par[u]])
            par[u] = find(par[par[u]]);
        return par[u];
    }

    bool connected(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        return false;
    }

    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] <= sz[v])
        {
            sz[v] += sz[u];
            par[u] = v;
        }
        else
        {
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
};

void solve()
{
    ll n;
    cin >> n;
    UnionFind uf1(n), uf2(n);
    ll m1, m2;
    cin >> m1 >> m2;
    vector<pair<ll, ll>> e1(m1), e2(m2);
#define f(i, n) for (ll i = 0; i < (n); i++)
    f(i, m1)
    {
        ll a, b;
        cin >> a >> b;
        // store edge directly instead of using push_back
        e1[i] = {a - 1, b - 1};
    }
    f(i, m2)
    {
        ll a, b;
        cin >> a >> b;
        // store edge directly instead of using push_back
        e2[i] = {a - 1, b - 1};
    }

    for (auto [a, b] : e2)
    {
        uf2.join(a, b);
    }

    ll ans = 0;

    for (auto [a, b] : e1)
    {
        if (uf2.connected(a, b))
        {
            uf1.join(a, b);
        }
        else
        {
            ans++;
        }
    }

    set<ll> s1, s2;
    f(i, n)
    {
        s1.insert(uf1.find(i));
        s2.insert(uf2.find(i));
    }

    cout << ans + s1.size() - s2.size() << nl;
}

/*
You are given two simple undirected graphs F
 and G
 with n
 vertices. F
 has m1
 edges while G
 has m2
 edges. You may perform one of the following two types of operations any number of times:

Select two integers u
 and v
 (1≤u,v≤n
) such that there is an edge between u
 and v
 in F
. Then, remove that edge from F
.
Select two integers u
 and v
 (1≤u,v≤n
) such that there is no edge between u
 and v
 in F
. Then, add an edge between u
 and v
 in F
.
Determine the minimum number of operations required such that for all integers u
 and v
 (1≤u,v≤n
), there is a path from u
 to v
 in F
 if and only if there is a path from u
 to v
 in G
.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of independent test cases.

The first line of each test case contains three integers n
, m1
, and m2
 (1≤n≤2⋅105
, 0≤m1,m2≤2⋅105
) — the number of vertices, the number of edges in F
, and the number of edges in G
.

The following m1
 lines each contain two integers u
 and v
 (1≤u,v≤n
) — there is an edge between u
 and v
 in F
. It is guaranteed that there are no repeated edges or self loops.

The following m2
 lines each contain two integers u
 and v
 (1≤u,v≤n
) — there is an edge between u
 and v
 in G
. It is guaranteed that there are no repeated edges or self loops.

It is guaranteed that the sum of n
, the sum of m1
, and the sum of m2
 over all test cases do not exceed 2⋅105
.

Output
For each test case, output a single integer denoting the minimum operations required on a new line.

Example
InputCopy
5
3 2 1
1 2
2 3
1 3
2 1 1
1 2
1 2
3 2 0
3 2
1 2
1 0 0
3 3 1
1 2
1 3
2 3
1 2
OutputCopy
3
0
2
0
2
Note
In the first test case you can perform the following three operations:

Add an edge between vertex 1
 and vertex 3
.
Remove the edge between vertex 1
 and vertex 2
.
Remove the edge between vertex 2
 and vertex 3
.
It can be shown that fewer operations cannot be achieved.
In the second test case, F
 and G
 already fulfill the condition in the beginning.

In the fifth test case, the edges from 1
 to 3
 and from 2
 to 3
 must both be removed.
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
