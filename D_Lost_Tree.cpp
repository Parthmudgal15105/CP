#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#define pb push_back
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
int n = 2005;
vi dist(n);
vvi edges;
void query(int node)
{
    cout << "? " << node << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> dist[i];
    }
}
void addEdge(int u, int v)
{
    edges.pb({u, v});
}
void solve()
{
    // Read the number of nodes in the hidden tree
    cin >> n;

    // 1) Query node 1 to learn its distance to every other node
    //    dist[i] == 1 means i is a direct neighbor of 1
    query(1);
    // Save the distances from node 1 for later use
    vi InitialDistance = dist;

    // We will collect two parity‐groups of nodes:
    //  - blackNodes  = those at even distance from 1 (except 1 itself)
    //  - yellowNodes = those at odd distance from 1
    vi blackNodes, yellowNodes;

    // 2) Process the distances from node 1:
    //    • Build the two parity lists
    //    • Immediately record every edge (i,1) where dist[i]==1
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] % 2 == 0)
            blackNodes.pb(i);
        else
            yellowNodes.pb(i);

        // If dist[i]==1 ⇒ direct edge between i and 1
        if (dist[i] == 1)
            addEdge(i, 1);
    }

    // 3) To reconstruct the rest of the tree, we need to learn
    //    the neighbors of every other node. But we are limited
    //    to ⌈n/2⌉ queries, so we choose the smaller parity group
    //    to query each of its nodes:
    //
    //    In a tree, every edge connects nodes of opposite parity
    //    relative to node 1.  Querying a node u returns dist[u][v]
    //    for all v, so we can pull out all edges (u,v) where
    //    dist[u][v]==1.
    //
    //    We pick the color‐group with fewer nodes to stay under
    //    the query limit.
    vi &toQuery = (blackNodes.size() < yellowNodes.size()
                       ? blackNodes
                       : yellowNodes);

    // 4) Query each chosen node, and for any reply dist[i]==1,
    //    record the edge (i,u).
    for (int u : toQuery)
    {
        query(u);
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == 1)
                addEdge(i, u);
        }
    }

    // 5) Finally, print the reconstructed edge list.
    //    We have recorded exactly n−1 edges.
    cout << "!" << endl;
    for (auto &edge : edges)
    {
        cout << edge[0] << " " << edge[1] << endl;
    }
}
/*
This is an interactive problem.

Little Dormi was faced with an awkward problem at the carnival: he has to guess the edges of an unweighted tree of n
 nodes! The nodes of the tree are numbered from 1
 to n
.

The game master only allows him to ask one type of question:

Little Dormi picks a node r
 (1≤r≤n
), and the game master will reply with an array d1,d2,…,dn
, where di
 is the length of the shortest path from node r
 to i
, for all 1≤i≤n
.
Additionally, to make the game unfair challenge Little Dormi the game master will allow at most ⌈n2⌉
 questions, where ⌈x⌉
 denotes the smallest integer greater than or equal to x
.

Faced with the stomach-churning possibility of not being able to guess the tree, Little Dormi needs your help to devise a winning strategy!

Note that the game master creates the tree before the game starts, and does not change it during the game.

Input
The first line of input contains the integer n
 (2≤n≤2000
), the number of nodes in the tree.

You will then begin interaction.

Output
When your program has found the tree, first output a line consisting of a single "!" followed by n−1
 lines each with two space separated integers a
 and b
, denoting an edge connecting nodes a
 and b
 (1≤a,b≤n
). Once you are done, terminate your program normally immediately after flushing the output stream.

You may output the edges in any order and an edge (a,b)
 is considered the same as an edge (b,a)
. Answering is not considered as a query.

Interaction
After taking input, you may make at most ⌈n2⌉
 queries. Each query is made in the format "? r", where r
 is an integer 1≤r≤n
 that denotes the node you want to pick for that query.

You will then receive n
 space separated integers d1,d2,…,dn
, where di
 is the length of the shortest path from node r
 to i
, followed by a newline.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages.
If at any point you make an invalid query or try to make more than ⌈n2⌉
 queries, the interaction will terminate immediately and you will receive a Wrong Answer verdict.

Hacks

To hack a solution, use the following format.

The first line contains the integer n
 (2≤n≤2000
).

The next n−1
 lines contain two integers u
 and v
 (1≤u,v≤n
) denoting an edge between u
 and v
 (u≠v
). These n−1
 edges must form a tree.

Examples
InputCopy
4

0 1 2 2

1 0 1 1
OutputCopy
? 1

? 2

!
4 2
1 2
2 3
InputCopy
5

2 2 1 1 0
OutputCopy
? 5

!
4 5
3 5
2 4
1 3
Note
Here is the tree from the first example.


Notice that the edges can be output in any order.

Additionally, here are the answers for querying every single node in example 1
:

1
: [0,1,2,2]
2
: [1,0,1,1]
3
: [2,1,0,2]
4
: [2,1,2,0]
Below is the tree from the second example interaction.


Lastly, here are the answers for querying every single node in example 2
:

1
: [0,4,1,3,2]
2
: [4,0,3,1,2]
3
: [1,3,0,2,1]
4
: [3,1,2,0,1]
5
: [2,2,1,1,0]


 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
