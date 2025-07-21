#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
#define cno cout << "NO\n"
#define cyes cout << "YES\n"

void solve()
{
    int n, m;
    cin >> n >> m;

    // Build adjacency list and store edges in input order
    vvi adj(n + 1);
    vector<pair<int, int>> el(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        el[i] = {u, v}; // store edge for output order
    }

    // Prepare color and visited arrays (1-based nodes)
    vi col(n + 1, -1);    // col[i]: color of node i (0 or 1)
    vb vis(n + 1, false); // vis[i]: whether node i has been visited

    // DFS to 2-color the graph and detect conflicts
    // If the graph is bipartite, we can orient edges so no path of length ≥2 exists
    function<bool(int)> dfs = [&](int u) -> bool
    {
        vis[u] = true;
        for (int v : adj[u])
        {
            // If neighbor has same color, not bipartite ⇒ impossible
            if (col[v] == col[u])
                return false;
            // If neighbor not colored, assign opposite color and recurse
            if (!vis[v])
            {
                col[v] = !col[u];
                if (!dfs(v))
                    return false;
            }
        }
        return true;
    };

    // Start DFS from node 1 (arbitrary) with color 0
    col[1] = 0;
    if (!dfs(1))
    {
        // If not bipartite, print NO and exit
        cno;
        return;
    }

    // If 2-coloring succeeded, print YES
    cyes;
    string ans;
    ans.reserve(m);
    // For each edge in input order, orient from color 0 to color 1
    for (auto &e : el)
    {
        int u = e.first;
        // If u is color 0, direct edge u→v as '0', else '1'
        ans += (col[u] == 0 ? '0' : '1');
    }
    cout << ans << nl;
}

/*
You are given a connected undirected graph consisting of n
 vertices and m
 edges. There are no self-loops or multiple edges in the given graph.

You have to direct its edges in such a way that the obtained directed graph does not contain any paths of length two or greater (where the length of path is denoted as the number of traversed edges).

Input
The first line contains two integer numbers n
 and m
 (2≤n≤2⋅105
, n−1≤m≤2⋅105
) — the number of vertices and edges, respectively.

The following m
 lines contain edges: edge i
 is given as a pair of vertices ui
, vi
 (1≤ui,vi≤n
, ui≠vi
). There are no multiple edges in the given graph, i. e. for each pair (ui,vi
) there are no other pairs (ui,vi
) and (vi,ui
) in the list of edges. It is also guaranteed that the given graph is connected (there is a path between any pair of vertex in the given graph).

Output
If it is impossible to direct edges of the given graph in such a way that the obtained directed graph does not contain paths of length at least two, print "NO" in the first line.

Otherwise print "YES" in the first line, and then print any suitable orientation of edges: a binary string (the string consisting only of '0' and '1') of length m
. The i
-th element of this string should be '0' if the i
-th edge of the graph should be directed from ui
 to vi
, and '1' otherwise. Edges are numbered in the order they are given in the input.

Example
InputCopy
6 5
1 5
2 1
1 4
3 1
6 1
OutputCopy
YES
10100
Note
The picture corresponding to the first example:

And one of possible answers:
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();
    return 0;
}
