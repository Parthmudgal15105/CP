#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define mod 998244353
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vl = vector<ll>;

// Precompute powers of 2 up to max N for “odd‐label” choices
// power2[i] = 2^i mod `mod`
vl power2(300005, 1);

// Graph and helper arrays (will be resized per test)
int n, m;
vvi adj; // adjacency list
vi col;  // col[u] = 0 or 1, bipartite color
vb vis;  // vis[u] = visited flag

// Counters for current component
ll c0, c1;

// DFS to 2‐color the component and detect conflicts
// Returns false if the graph is not bipartite
bool dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        // If neighbor has same color ⇒ cannot 2‐color ⇒ no solution
        if (col[v] == col[u])
            return false;
        // If neighbor unvisited, assign opposite color and recurse
        if (!vis[v])
        {
            col[v] = !col[u];
            if (col[v])
                c1++; // count of color‐1 nodes
            else
                c0++; // count of color‐0 nodes

            if (!dfs(v))
                return false;
        }
    }
    return true;
}

void solve()
{
    // Read number of vertices `n` and edges `m`
    cin >> n >> m;

    // Resize helper arrays to size `n+1` (1‐based indexing)
    adj.assign(n + 1, {});
    col.assign(n + 1, -1);
    vis.assign(n + 1, false);

    // Read edges into adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // `ans` will accumulate total ways modulo `mod`
    ll ans = 1;

    // Iterate over all vertices to cover every connected component
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // Start a new component, pick initial color=1 for node `i`
            col[i] = 1;
            c1 = 1; // one node in color‐1
            c0 = 0; // zero nodes in color‐0

            // Run DFS to 2‐color this component
            if (!dfs(i))
            {
                // Not bipartite ⇒ no valid labeling exists
                cout << 0 << nl;
                return;
            }

            // For this component we have two ways:
            //  - assign color‐0 nodes with odd labels (1 or 3) and
            //    color‐1 nodes with the single even label (2), or
            //  - vice versa.
            // Each odd‐labeled node has 2 choices (1 or 3),
            // even‐labeled nodes have exactly 1 choice.
            // So total for this component = 2^c0 + 2^c1.
            ll ways = (power2[c0] + power2[c1]) % mod;
            ans = (ans * ways) % mod;
        }
    }

    // Print the total number of beautiful labelings
    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute powers of 2 once
    for (int i = 1; i < (int)power2.size(); i++)
        power2[i] = (power2[i - 1] * 2) % mod;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
Solution Explanation:

We need to assign each vertex a label in {1,2,3} so that for every edge
(u,v), the sum of labels is odd.  That forces one endpoint even (label 2)
and the other odd (label 1 or 3).

1) This “even‐odd” assignment is exactly a 2‐coloring of the graph: color
   0 = even side, color 1 = odd side.  Edges must go between different colors.

2) If the graph is not bipartite, no such labeling exists → answer 0.

3) If it is bipartite, each connected component splits into two sets of
   sizes c0 and c1.  We have two choices per component:
     A) color-0 vertices get odd labels (2 choices each), color-1 get label 2 (1 choice each)
     B) color-1 vertices get odd labels, color-0 get label 2

   #ways = 2^c0 (odd choices on c0) * 1^c1 + 1^c0 * 2^c1 = 2^c0 + 2^c1.

4) Multiply the counts for all components (mod 998244353) to get final answer.
*/
