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
    vl a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/
int n = 1e5 + 5, m; // n: max nodes, m: max consecutive cats allowed
vvi adj(n);         // adjacency list for the tree
vi a(n);            // a[i]: 1 if node i has a cat, 0 otherwise
int ans = 0;        // answer: number of valid restaurants (leaves)

// DFS to count valid leaves (restaurants)
// u: current node
// p: parent node (to avoid going back)
// numC: current consecutive cats on the path
// maxC: max consecutive cats seen so far on the path
void dfs(int u, int p, int numC, int maxC)
{
    // If current node has a cat, increment consecutive count
    // Else, reset consecutive count to 0
    if (a[u])
        numC++;
    else
        numC = 0;

    // Update the max consecutive cats seen so far on this path
    maxC = max(maxC, numC);

    int numChild = 0; // count children to detect leaves
    for (int v : adj[u])
    {
        if (v != p) // don't revisit parent
        {
            dfs(v, u, numC, maxC);
            numChild++;
        }
    }

    // If leaf node (no children) and max consecutive cats <= m, it's a valid restaurant
    if (numChild == 0 && maxC <= m)
    {
        ans++;
    }
}

void solve()
{
    cin >> n >> m;

    // Read cat info for each node (1-based input)
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // Read edges and build the tree (undirected)
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from root (node 1), parent is -1, no cats yet
    dfs(1, -1, 0, 0);

    // Output the answer
    cout << ans;
}

/*
Explanation:
- The tree is built using adjacency lists.
- Each node may or may not have a cat.
- We want to count the number of leaf nodes (restaurants) such that the path from root to leaf never has more than m consecutive nodes with cats.
- DFS is used to traverse the tree, keeping track of the current streak of consecutive cats and the maximum streak seen on the path.
- When a leaf is reached, if the max streak is <= m, increment the answer.
- The solution efficiently checks all paths from root to leaves.
*/

/*
Kefa decided to celebrate his first big salary by going to the restaurant.

He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1. Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats. Kefa has already found out what are the vertices with cats in them.

The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go, but unfortunately he is very afraid of cats, so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats.

Your task is to help Kefa count the number of restaurants where he can go.

Input
The first line contains two integers, n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ n) — the number of vertices of the tree and the maximum number of consecutive vertices with cats that is still ok for Kefa.

The second line contains n integers a1, a2, ..., an, where each ai either equals to 0 (then vertex i has no cat), or equals to 1 (then vertex i has a cat).

Next n - 1 lines contains the edges of the tree in the format "xi yi" (without the quotes) (1 ≤ xi, yi ≤ n, xi ≠ yi), where xi and yi are the vertices of the tree, connected by an edge.

It is guaranteed that the given set of edges specifies a tree.

Output
A single integer — the number of distinct leaves of a tree the path to which from Kefa's home contains at most m consecutive vertices with cats.

Examples
InputCopy
4 1
1 1 0 0
1 2
1 3
1 4
OutputCopy
2
InputCopy
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
OutputCopy
2
Note
Let us remind you that a tree is a connected graph on n vertices and n - 1 edge. A rooted tree is a tree with a special vertex called root. In a rooted tree among any two vertices connected by an edge, one vertex is a parent (the one closer to the root), and the other one is a child. A vertex is called a leaf, if it has no children.

Note to the first sample test:The vertices containing cats are marked red. The restaurants are at vertices 2, 3, 4. Kefa can't go only to the restaurant located at vertex 2.

Note to the second sample test:The restaurants are located at vertices 4, 5, 6, 7. Kefa can't go to restaurants 6, 7.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
