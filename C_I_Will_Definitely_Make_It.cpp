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
        cin >> a[i];

    ll start = a[k - 1];
    sort(all(a));
    int pos = lower_bound(all(a), start) - a.begin();

    ll time = 0, curH = start;
    bool ok = true;

    for (int i = pos + 1; i < n; i++)
    {
        ll diff = a[i] - curH;
        if (time + diff > curH)
        {
            ok = false;
            break;
        }
        time += diff;
        curH = a[i];
    }

    if (ok)
    {
        cyes;
    }
    else
    {
        cno;
    }
}
/*
You are given n
 towers, numbered from 1
 to n
. Tower i
 has a height of hi
. At time 0
, you are on the tower with index k
, and the current water level is 1
.

Every second, the water level rises by 1
 unit. At any moment, if the water level becomes strictly greater than the height of the tower you are on, you perish.

You have a magical ability: at moment x
, you can start teleporting from tower i
 to tower j
, which will take |hi−hj|
 seconds. That is, until moment x+|hi−hj|
, you will be on tower i
, and at moment x+|hi−hj|
, you will move to tower j
. You can start a new teleportation at the same moment you just arrived at tower j
.

For example, if n=k=4
, h=[4,4,4,2]
, then if you start teleporting from tower 4
 to tower 1
 at moment 0
, the movement will look as follows:


Note that if the height of tower 1
 were 5
, you would not be able to teleport to it immediately, as you would be submerged at moment 2
.

Your goal is to reach any tower with the maximum height before the water covers you.

Determine if this is possible.

Input
Each test consists of several test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤105
) — the number of towers and the index of the tower you are initially on.

The second line contains n
 integers h1,h2,…,hn
 (1≤hi≤109
) — the heights of the towers.

It is guaranteed that the sum of all n
 across all test cases does not exceed 105
.

Output
For each test case, output one line: "YES", if you can reach the tower with the maximum height before the water covers you, or "NO" otherwise.

You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
InputCopy
5
5 3
3 2 1 4 5
3 1
1 3 4
4 4
4 4 4 2
6 2
2 3 6 9 1 2
4 2
1 2 5 6
OutputCopy
YES
NO
YES
YES
NO
Note
In the first test case, the only possible path is: 3→2→1→4→5
.

In the second test case, regardless of the order, it will not be possible to reach the tallest tower.

In the third test case, one of the possible paths is: 4→1
.
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
