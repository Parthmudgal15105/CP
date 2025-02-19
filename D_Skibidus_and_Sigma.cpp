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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    vector<ll> sumArr(n, 0);

    for (int i = 0; i < n; i++)
    {
        ll s = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            s += arr[i][j];
        }
        sumArr[i] = s;
    }

    vector<pair<ll, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({sumArr[i], i});
    }
    sort(v.begin(), v.end(), [&](auto &a, auto &b)
         { return a.first > b.first; });

    vector<ll> merged;
    merged.reserve(n * m);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            merged.push_back(arr[v[i].second][j]);
        }
    }

    ll ans = 0, partial = 0;
    for (int i = 0; i < merged.size(); i++)
    {
        partial += merged[i];
        ans += partial;
    }
    cout << ans << nl;
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
