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
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
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
    int n;
    cin >> n;
    ll a[n + 1], b[n + 1], c[n + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum = (sum + 2) / 3;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    vector<ll> p1(n + 5), p2(n + 5), p3(n + 5);
    vector<ll> s1(n + 5), s2(n + 5), s3(n + 5);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1] + a[i];
        p2[i] = p2[i - 1] + b[i];
        p3[i] = p3[i - 1] + c[i];
    }
    for (int i = n; i >= 1; i--)
    {
        s1[i] = s1[i + 1] + a[i];
        s2[i] = s2[i + 1] + b[i];
        s3[i] = s3[i + 1] + c[i];
    }
    // a b c
    int i = 1, j = n;
    while (p1[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s3[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p2[j] - p2[i - 1] >= sum)
    {
        cout << 1 << ' ' << i - 1 << ' ' << i << ' ' << j << ' ' << j + 1 << ' ' << n << endl;
        return;
    }
    // a c b
    i = 1, j = n;
    while (p1[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s2[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p3[j] - p3[i - 1] >= sum)
    {
        cout << 1 << ' ' << i - 1 << ' ' << j + 1 << ' ' << n << ' ' << i << ' ' << j << endl;
        return;
    }
    // b  c a
    i = 1, j = n;
    while (p2[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s1[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p3[j] - p3[i - 1] >= sum)
    {
        cout << j + 1 << ' ' << n << ' ' << 1 << ' ' << i - 1 << ' ' << i << ' ' << j << endl;
        return;
    }
    // b a c
    i = 1, j = n;
    while (p2[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s3[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p1[j] - p1[i - 1] >= sum)
    {
        cout << i << ' ' << j << ' ' << 1 << ' ' << i - 1 << ' ' << j + 1 << ' ' << n << endl;
        return;
    }
    // c a b
    i = 1, j = n;
    while (p3[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s2[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p1[j] - p1[i - 1] >= sum)
    {
        cout << i << ' ' << j << ' ' << j + 1 << ' ' << n << ' ' << 1 << ' ' << i - 1 << endl;
        return;
    }
    //  c b a
    i = 1, j = n;
    while (p3[i - 1] < sum && i <= n)
    {
        i++;
    }
    while (s1[j + 1] < sum && j >= 1)
    {
        j--;
    }
    if (i <= j && p2[j] - p2[i - 1] >= sum)
    {
        cout << j + 1 << ' ' << n << ' ' << i << ' ' << j << ' ' << 1 << ' ' << i - 1 << endl;
        return;
    }
    cout << -1 << endl;

    return;
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
