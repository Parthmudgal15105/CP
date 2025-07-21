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
#define pb push_back
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
int n = 2e5 + 5, m;
vvi adj(n);
vb vis(n);
bool isCycle;
void dfs(int u, const vvi &adj, vb &vis, bool &isCycle)
{
    vis[u] = true;
    // must have exactly 2 neighbors in a pure cycle
    if (adj[u].size() != 2)
        isCycle = false;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis, isCycle);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // build fresh containers sized to n+1
    vvi adj(n + 1);
    vb vis(n + 1, false);

    // read edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    // explore each connected component
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool isCycle = true;
            dfs(i, adj, vis, isCycle);
            if (isCycle)
                ans++;
        }
    }

    cout << ans << "\n";
}

/*
#include <bits/stdc++.h>
using namespace std;
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
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int n = 2e5 + 5,m;
vvi adj(n);
vb vis(n);
bool isCycle;
void dfs(int u)
{
    //if the # of adjacent nodes to u is exactly 2
    //adj[u].size() gives the # of adjacent nodes to u
    vis[u] = 1;
    if (adj[u].size() != 2){//dont return here but visit all nodes in this cc
        isCycle = false;
    }
    for (int v:adj[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    setIO();
    cin>>n>>m;
    while (m--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 1;i<=n;i++){
        if (!vis[i]){
            isCycle = true;
            dfs(i);
            if (isCycle)ans++;
        }
    }
    cout<<ans;
    return 0;
}
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
