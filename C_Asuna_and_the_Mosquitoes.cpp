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
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
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
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll c0 = 0, c1 = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
            c1++;
        else
            c0++;
    }
    if (c1 == 0 || c0 == 0)
    {
        ll ans = *max_element(a.begin(), a.end());
        cout << ans << nl;
        return;
    }
    ll ans = accumulate(a.begin(), a.end(), 0LL) - (c1 - 1);
    cout << ans << nl;
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