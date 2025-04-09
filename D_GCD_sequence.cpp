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
const int N = 2e5 + 5;
int n;
int a[N], b[N], c[N];

bool check(int x)
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
        {
            continue;
        }
        c[++t] = a[i];
    }
    int last = 1;
    for (int i = 1; i < t; i++)
    {
        int y = __gcd(c[i], c[i + 1]);
        if (y < last)
            return false;
        last = y;
    }
    return true;
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        b[i] = __gcd(a[i], a[i + 1]);

    int x = -1;
    for (int i = 1; i < n - 1; i++)
    {
        if (b[i] > b[i + 1])
        {
            x = i;
            break;
        }
    }

    if (x == -1)
        cout << "YES\n";
    else if (check(x) || check(x + 1) || check(x + 2) || check(x - 1))
        cout << "YES\n";
    else
        cout << "NO\n";
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
