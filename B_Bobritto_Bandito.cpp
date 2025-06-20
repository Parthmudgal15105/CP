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
check all edge cases
check for integer overflow
check for corner cases
check for constraints
check for time complexity
check for array bounds
check for negative values
*/
/*
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/

void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    if (n == m)
    {
        cout << l << sp << r << nl;
        return;
    }
    int low = max(0, m - r);
    int high = min(m, -l);
    int x = low;
    cout << -x << sp << (m - x) << nl;
}

/*
In Bobritto Bandito's home town of residence, there are an infinite number of houses on an infinite number line, with houses at …,−2,−1,0,1,2,…
. On day 0
, he started a plague by giving an infection to the unfortunate residents of house 0
. Each succeeding day, the plague spreads to exactly one healthy household that is next to an infected household. It can be shown that each day the infected houses form a continuous segment.

Let the segment starting at the l
-th house and ending at the r
-th house be denoted as [l,r]
. You know that after n
 days, the segment [l,r]
 became infected. Find any such segment [l′,r′]
 that could have been infected on the m
-th day (m≤n
).

Input
The first line contains an integer t
 (1≤t≤100
) – the number of independent test cases.

The only line of each test case contains four integers n
, m
, l
, and r
 (1≤m≤n≤2000,−n≤l≤0≤r≤n,r−l=n
).

Output
For each test case, output two integers l′
 and r′
 on a new line. If there are multiple solutions, output any.

Example
InputCopy
4
4 2 -2 2
4 1 0 4
3 3 -1 2
9 8 -6 3
OutputCopy
-1 1
0 1
-1 2
-5 3
Note
In the first test case, it is possible that on the 1
-st, 2
-nd, and 3
-rd days the interval of houses affected is [−1,0]
, [−1,1]
, [−2,1]
. Therefore, [−1,1]
 is a valid output.
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
