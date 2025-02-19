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
    for(int i=0; i<n; i++)
        cin>>arr[i];
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
    vector<int> a(1001);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int now = n;
    long long ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int i = 1; i <= now; i++)
        {
            sum = (sum + a[i]);
        }
        if (i == 1)
        {
            ans = max(ans, sum);
        }
        else
        {
            ans = max(ans, max(sum, (-sum)));
        }
        for (int i = 1; i < now; i++)
        {
            a[i] = (a[i + 1] - a[i]);
        }
        now--;
    }
    cout << ans << endl;
}

/*
The first line of input contains a single integer t
 (1≤t≤100
) — the number of input test cases.

The first line of each test case contains a single integer n
 (1≤n≤50
) — the length of sequence a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (|ai|≤1000
) — the sequence a
.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
