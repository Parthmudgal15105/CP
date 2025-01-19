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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> power(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vector<ll> p(x);
        ll mxp = -1;
        ;
        for (int j = 0; j < x; j++)
        {
            cin >> p[j];
            mxp = max(mxp, p[j] - j + 1);
        }
        power[i] = {mxp, x};
    }
    sort(power.begin(), power.end());
    ll l = power[0].first, r = power[n - 1].first;
    ll ans = 1e12;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll curr = mid;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (curr >= power[i].first)
            {
                curr += power[i].second;
            }
            else
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
