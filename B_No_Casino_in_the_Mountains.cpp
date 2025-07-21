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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    int i = 0;
    while (i <= n - k)
    {
        bool yes = true;
        for (int j = 0; j < k; j++)
        {
            if (a[i + j] != 0)
            {
                yes = false;
                break;
            }
        }
        if (yes)
        {
            ans++;
            i += k + 1;
        }
        else
        {
            i++;
        }
    }
    cout << ans << nl;
}
/*
You are given an array a
 of n
 numbers and a number k
. The value ai
 describes the weather on the i
-th day: if it rains on the i
-th day, then ai=1
; otherwise, if the weather is good on the i
-th day, then ai=0
.

Jean wants to visit as many peaks as possible. One hike to a peak takes exactly k
 days, and during each of these days, the weather must be good (ai=0
). That is, formally, he can start a hike on day i
 only if all aj=0
 for all j
 (i≤j≤i+k−1)
.

After each hike, before starting the next one, Jean must take a break of at least one day, meaning that on the day following a hike, he cannot go on another hike.

Find the maximum number of peaks that Jean can visit.

Input
Each test consists of several test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤n≤105
, 1≤k≤n
).

The second line contains n
 numbers ai
 (ai∈{0,1}
), where ai
 denotes the weather on the i
-th day.

It is guaranteed that the total value of n
 across all test cases does not exceed 105
.

Output
For each test case, output a single integer: the maximum number of hikes that Jean can make.

Example
InputCopy
5
5 1
0 1 0 0 0
7 3
0 0 0 0 0 0 0
3 1
1 1 1
4 2
0 1 0 1
6 2
0 0 1 0 0 0
OutputCopy
3
2
0
0
2
Note
In the first sample:

Day 1
 — good weather, Jean goes on a hike. (a1=0
)
Day 2
 — mandatory break.
Day 3
 — again good weather, Jean goes on the second hike. (a3=0
)
Day 4
 — break.
Day 5
 — good weather, third hike. (a5=0
)
Thus, Jean can make 3 hikes, alternating each with a mandatory day of rest.
In the second sample:

From day 1
 to day 3
 — three days of good weather, Jean goes on a hike. (a1=a2=a3=0
)
Day 4
 — mandatory break.
From day 5
 to day 7
 — again three days of good weather, Jean goes on the second hike. (a5=a6=a7=0
)
In total, Jean makes 2 hikes.
In the third sample:

There are no days with good weather (ai=1
 for all i
)
Jean cannot make any hikes. Answer: 0
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
