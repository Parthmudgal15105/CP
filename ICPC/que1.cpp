#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// Types
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

// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
ll nCk(ll n, ll k)
{
    ll res = 1;
    for (ll i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
/*----------------------------------------------------------------------------*/
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    // Sort prices in ascending order to ensure we always get cheaper items for free
    sort(c.begin(), c.end());

    // dp[m] represents minimum cost to buy m items
    vector<long long> dp(n + 1, 0);

    for (int m = 1; m <= n; ++m)
    {
        // By default, we add the cost of current item to previous state
        dp[m] = dp[m - 1] + c[m - 1];

        // If we have enough items to use the offer (more than k items)
        if (m > k)
        {
            // Two choices:
            // 1. Don't use offer: dp[m-1] + c[m-1] (already calculated above)
            // 2. Use offer: dp[m-k-1] + c[m-1]
            //    Here we go back k+1 items (k items to buy + 1 free item)
            //    and add cost of current item
            dp[m] = min(dp[m], dp[m - k - 1] + c[m - 1]);
        }
    }

    // Print minimum cost for each number of items from 1 to n
    for (int m = 1; m <= n; ++m)
    {
        cout << dp[m] << ' ';
    }
    cout << '\n';
}

/*
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
/*You are at a shop with n items numbered 1, 2, . . . n. For each i, the price of the item number i equals Ci
.
There is an offer under which, if you buy any k items, you can get any other item for free, whose price
does not exceed the cheapest of the k items. Please note that, the offer can be used any (including 0)
number of times.
For each m = 1, 2, . . . n, find the minimum amount that you need to pay in order to buy m items.*/