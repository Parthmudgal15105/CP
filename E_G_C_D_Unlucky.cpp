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
    // 1) Read input
    //    n = length of arrays p (pref) and s (suff)
    int n;
    cin >> n;
    vi pref(n), suff(n);
    for (int i = 0; i < n; i++)
        cin >> pref[i]; // p[i] = gcd(a[1..i])
    for (int i = 0; i < n; i++)
        cin >> suff[i]; // s[i] = gcd(a[i..n])

    // 2) Reconstruct candidate array a[]
    //    Key fact: any valid a[i] must be a multiple of both
    //    p[i] and s[i]. Taking the least common multiple (LCM)
    //    gives the minimal choice:
    //      a[i] = lcm(p[i], s[i])
    //    (Recall gcd(x,y)*lcm(x,y) = x*y)
    vl a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = lcm(pref[i], suff[i]);
    }

    // 3) Compute the prefix‐GCDs of a[] and compare to pref[]
    //    Build pref1 so that:
    //      pref1[i] = gcd(a[0], a[1], …, a[i])
    vl pref1(n);
    pref1[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref1[i] = gcd(pref1[i - 1], a[i]);
    }

    // 4) Compute the suffix‐GCDs of a[] and compare to suff[]
    //    Build suff1 so that:
    //      suff1[i] = gcd(a[i], a[i+1], …, a[n-1])
    vl suff1(n);
    suff1[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff1[i] = gcd(a[i], suff1[i + 1]);
    }

    // 5) Verify that the recomputed GCD arrays match the input
    //    If any position differs, no valid a[] can exist
    for (int i = 0; i < n; i++)
    {
        if (pref1[i] != pref[i] || suff1[i] != suff[i])
        {
            cno; // output "NO"
            return;
        }
    }

    // 6) All checks passed ⇒ the candidate a[] works
    cyes; // output "YES"
}
/*
Two arrays p
 and s
 of length n
 are given, where p
 is the prefix GCD∗
 of some array a
, and s
 is the suffix GCD of the same array a
. In other words, if the array a
 existed, then for each 1≤i≤n
, the following equalities would hold both:

pi=gcd(a1,a2,…,ai)
si=gcd(ai,ai+1,…,an)
.
Determine whether there exists such an array a
 for which the given arrays p
 and s
 can be obtained.
∗
gcd(x,y)
 denotes the greatest common divisor (GCD) of integers x
 and y
.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of three lines:

The first line of each test case contains a single integer n
 (1≤n≤105
) — the length of the array.

The second line of each test case contains n
 integers p1,p2,…,pn
 (1≤pi≤109
) — the elements of the array.

The third line of each test case contains n
 integers s1,s2,…,sn
 (1≤si≤109
) — the elements of the array.

It is guaranteed that the sum of all n
 across all test cases does not exceed 105
.

Output
For each test case, output "Yes" (without quotes) if there exists an array a
 for which the given arrays p
 and s
 can be obtained, and "No" (without quotes) otherwise.

You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
InputCopy
5
6
72 24 3 3 3 3
3 3 3 6 12 144
3
1 2 3
4 5 6
5
125 125 125 25 25
25 25 25 25 75
4
123 421 282 251
125 1981 239 223
3
124 521 125
125 121 121
OutputCopy
YES
NO
YES
NO
NO
Note
For the first test case, a possible array is: [72, 24, 3, 6, 12, 144
].

For the second test case, it can be shown that such arrays do not exist.

For the third test case, there exists an array: [125, 125, 125, 25, 75
].
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
