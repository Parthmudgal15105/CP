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

void solve()
{
    // 1) Read the number of vertices in this test case
    int n;
    cin >> n;

    // 2) Read the value at each vertex (0-indexed internally)
    //    v[i] = initial a_{i+1} from the problem statement
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 3) Build the tree via an adjacency list
    //    Parent of node 1 (index 0) is implicit (root).
    //    For i = 2..n, read p_i and connect p_i → i.
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        --p; // convert to 0-based
        adj[p].push_back(i);
    }

    // 4) Define a DFS that returns the maximum "value" we can push up
    //    from the subtree rooted at `node` after doing all allowed operations
    function<ll(int)> dfs = [&](int node) -> ll
    {
        // Track the minimum child‐subtree return value
        // If this node is a leaf, `mini` stays as LLONG_MAX
        ll mini = LLONG_MAX;

        // Recurse on children, keep the smallest returned value
        for (int child : adj[node])
        {
            ll childValue = dfs(child);
            mini = min(mini, childValue);
        }

        // 4a) Leaf node: no children
        if (mini == LLONG_MAX)
        {
            // We cannot perform any operation here (no subtree),
            // so the value that bubbles up is just v[node].
            return v[node];
        }

        // 4b) Internal node logic
        if (node == 0)
        {
            // At the root, we can freely add its own value
            // to the minimum of its children's bubbled values.
            // This corresponds to performing the operation
            // at the root as many times as possible.
            return mini + v[0];
        }
        else
        {
            // For a non-root internal node:
            // – If v[node] >= mini, we can “harvest” mini from below
            //   without decreasing further: return mini.
            // – Otherwise, each operation at this node
            //   effectively averages its own value with the
            //   bottleneck (mini), so we return floor((mini + v[node]) / 2).
            if (v[node] >= mini)
                return mini;
            else
                return (mini + v[node]) / 2;
        }
    };

    // 5) Kick off DFS from the root (node 0) and print the answer
    cout << dfs(0) << nl;
}

/*
How the code maps to the problem:

- Input:
    t test cases
    for each:
      n
      a1 a2 … an      (stored in v[0..n-1])
      p2 p3 … pn      (each p_i → parent relationship)

- adj[p].push_back(i) builds the children list.

- dfs(node) computes the **maximum value** that can be
  transferred up from this subtree after any number
  of allowed operations (increase v[node] by 1 and
  decrease every descendant by 1, keeping all ≥ 0).

- Leaves simply return their own value.
- Internal nodes compute the “bottleneck” (minimum child
  return) and combine it with their own value according to
  the rules:
    • Root can add its full v[0] to its bottleneck.
    • Other nodes are limited by how many operations they
      can “pull up” without driving descendants
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
