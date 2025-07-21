#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define nl '\n'
#define sp ' '
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

// Maximum possible n over all test cases
static const int MAXN = 200000 + 5;

// Graph data structures (will be resized per test)
int n;              // number of vertices
vvi adj(MAXN);      // adjacency list
vi par(MAXN);       // parent in DFS tree
vb vis(MAXN);       // visited flag for cycle search
vb isOnCycle(MAXN); // marks nodes on the unique cycle
vi cycle;           // stores the nodes forming the cycle
vb foundCycle(1);   // flag to stop DFS once cycle is found
vi sub(MAXN);       // subtree sizes hanging off each cycle node

// 1) dfs: find the unique cycle in an n-node, n-edge connected graph.
//    We do a standard DFS, track parents, and when we see a back-edge
//    (v != parent), we walk back through par[] to collect the cycle nodes.
void dfs(int u, int p)
{
    if (foundCycle[0])
        return; // already found cycle, unwind immediately

    vis[u] = true;
    par[u] = p;

    for (int v : adj[u])
    {
        if (foundCycle[0])
            return; // stop if cycle already recorded

        if (!vis[v])
        {
            dfs(v, u);
        }
        else if (v != p)
        {
            // back-edge found ⇒ we detected the cycle
            foundCycle[0] = true;
            // walk back from u to v via parent pointers
            int cur = u;
            while (cur != v)
            {
                isOnCycle[cur] = true;
                cycle.pb(cur);
                cur = par[cur];
            }
            // finally add the meeting node v
            isOnCycle[v] = true;
            cycle.pb(v);
            return;
        }
    }
}

// 2) dfs2: compute the size of the hanging tree rooted at u,
//    excluding any edges that lead back into the cycle.
//    sub[u] = number of nodes in this component.
int dfs2(int u, int p)
{
    sub[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue; // don't go back to parent
        if (isOnCycle[v])
            continue; // skip cycle edges
        sub[u] += dfs2(v, u);
    }
    return sub[u];
}

// solve() handles one test case:
//  - read n edges, build graph
//  - run dfs to identify the cycle
//  - for each cycle node, run dfs2 to get hanging subtree size
//  - apply formula: total simple paths = n*(n-1) - sum_{u in cycle}[sub[u]*(sub[u]-1)] / 2
void solve()
{
    int m = 0;
    cin >> n;
    // initialize/reset data structures
    cycle.clear();
    foundCycle[0] = false;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
        isOnCycle[i] = false;
        sub[i] = 0;
        par[i] = -1;
    }
    // read the n edges of this special connected graph
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // 1) detect the unique cycle
    dfs(1, -1);

    // 2) initial count: double the unordered pairs n*(n-1)
    //    (we'll subtract twice the internal pairs of each hanging subtree)
    ll ans = 1LL * n * (n - 1);

    // 3) for each node on the cycle, compute subtree size and subtract internal pairs
    for (int u : cycle)
    {
        dfs2(u, -1);
        ll val = sub[u];
        // subtract twice C(val,2) = val*(val-1)
        ans -= val * (val - 1);
    }

    // 4) ans now equals 2*(# of undirected simple paths)
    //    but the problem asks for undirected paths (direction does not matter),
    //    so we divide by 2:
    cout << (ans / 2) << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
