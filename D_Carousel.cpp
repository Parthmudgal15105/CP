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
#define mod 1000000007

// Types of declarations /////////////////////////////////
#define all(x) x.begin(), x.end()
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

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
////////////////////////////////////////////////////////// BINOMIAL COEFF
vl fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}

/*
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/
// maximum possible n across all test cases
static const int MAXN = 200000 + 5;

// adjacency list for the “difference‐only” graph
// we only connect i↔i+1 (and wrap) if t[i] != t[i+1]
vvi adj(MAXN);

// visited flag and color array for DFS
vb vis(MAXN);
vi col(MAXN, -1);

/*
  DFS‐based coloring:
  We try to 2‐color the graph with colors {1,2}.
  If we find an edge u–v where col[u]==col[v],
  we mark u with color=3 (third color) to break the conflict.
*/
void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        // conflict: same color on both ends ⇒ need a third color here
        if (col[v] == col[u])
        {
            col[u] = 3;
            continue;
        }
        // if neighbor unseen, assign opposite (or default) color
        if (!vis[v])
        {
            if (col[u] == 1)
                col[v] = 2;
            else if (col[u] == 2)
                col[v] = 1;
            else
                col[v] = 1; // starting default
            dfs(v);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    // clear per‐test adjacency, visited, and colors
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        col[i] = -1;
    }

    // read carousel types, 1‐based
    vi t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    // build edges only between consecutive figures with different types
    // this ensures same‐type neighbors can share color
    for (int i = 1; i < n; i++)
    {
        if (t[i] != t[i + 1])
        {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
    }
    // wrap‐around edge between 1 and n
    if (t[1] != t[n])
    {
        adj[1].push_back(n);
        adj[n].push_back(1);
    }

    // run DFS on each component to assign colors
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            col[i] = 1; // start component with color 1
            dfs(i);
        }
    }

    // determine how many colors we used (max over col[])
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        k = max(k, col[i]);
    }

    // output the minimal number of colors
    cout << k << nl;
    // then the color assignment for each vertex
    for (int i = 1; i <= n; i++)
    {
        cout << col[i] << sp;
    }
    cout << nl;
}
/*
The round carousel consists of n
 figures of animals. Figures are numbered from 1
 to n
 in order of the carousel moving. Thus, after the n
-th figure the figure with the number 1
 follows. Each figure has its own type — the type of the animal corresponding to this figure (the horse, the tiger and so on). The type of animal of the i
-th figure equals ti
.

The example of the carousel for n=9
 and t=[5,5,1,15,1,5,5,1,1]
.
You want to color each figure in one of the colors. You think that it's boring if the carousel contains two different figures (with the distinct types of animals) going one right after another and colored in the same color.

Your task is to color the figures in such a way that the number of distinct colors used is the minimum possible and there are no figures of the different types going one right after another and colored in the same color. If you use exactly k
 distinct colors, then the colors of figures should be denoted with integers from 1
 to k
.

Input
The input contains one or more test cases.

The first line contains one integer q
 (1≤q≤104
) — the number of test cases in the test. Then q
 test cases follow. One test case is given on two lines.

The first line of the test case contains one integer n
 (3≤n≤2⋅105
) — the number of figures in the carousel. Figures are numbered from 1
 to n
 in order of carousel moving. Assume that after the n
-th figure the figure 1
 goes.

The second line of the test case contains n
 integers t1,t2,…,tn
 (1≤ti≤2⋅105
), where ti
 is the type of the animal of the i
-th figure.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
Print q
 answers, for each test case print two lines.

In the first line print one integer k
 — the minimum possible number of distinct colors of figures.

In the second line print n
 integers c1,c2,…,cn
 (1≤ci≤k
), where ci
 is the color of the i
-th figure. If there are several answers, you can print any.

Example
InputCopy
4
5
1 2 1 2 2
6
1 2 2 1 2 2
5
1 2 1 2 3
3
10 10 10
OutputCopy
2
1 2 1 2 2
2
2 1 2 1 2 1
3
2 3 2 3 1
1
1 1 1


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
