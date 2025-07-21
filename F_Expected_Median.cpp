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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            zero++;
        else
            one++;
    }

    // The median of a binary subsequence of odd length k is 1
    // if and only if there are at least (k/2)+1 ones in the subsequence.
    // So, for each possible number of ones x in the subsequence,
    // where x ranges from req = (k/2)+1 to min(one, k):
    //   - Pick x ones from all available ones: C(one, x)
    //   - Pick (k-x) zeros from all available zeros: C(zero, k-x)
    //   - Each such combination forms a unique subsequence of length k with median 1.
    // The total number of such subsequences is C(one, x) * C(zero, k-x).
    // The sum of medians over all subsequences is just the count of those with median 1,
    // since subsequences with median 0 contribute nothing to the sum.

    ll req = (k / 2) + 1; // Minimum number of ones needed for median to be 1
    ll ans = 0;
    for (ll x = req; x <= min(one, k); x++)
    {
        // If not enough zeros to fill the rest of the subsequence, skip
        if (k - x > zero)
            continue;
        // PnC Trick:
        // Number of ways to pick x ones from 'one' ones: C(one, x)
        // Number of ways to pick (k-x) zeros from 'zero' zeros: C(zero, k-x)
        // Multiply because choices are independent (multiplication principle)
        ll ways = binom(one, x) * binom(zero, k - x) % mod;
        ans = (ans + ways) % mod;
    }
    cout << ans << nl;
}

/*
PnC Tricks and Explanation:

- For a binary array, the median of a subsequence of odd length k is 1
  if and only if there are at least (k/2)+1 ones in the subsequence.
- To count the number of subsequences of length k with exactly x ones:
    - Choose x ones from all available ones: C(one, x)
    - Choose (k-x) zeros from all available zeros: C(zero, k-x)
    - The total number of such subsequences is C(one, x) * C(zero, k-x)
      (multiplication principle: independent choices).
- The answer is the sum of all such counts for x = (k/2)+1 to min(one, k).
- Each such subsequence contributes 1 to the sum of medians.
- All other subsequences (with fewer ones) have median 0 and contribute nothing.

- binom(n, r) is computed using precomputed factorials and modular inverses:
    binom(n, r) = n! / (r! * (n-r)!) mod MOD

- Always precompute factorials up to the maximum possible n for efficiency and correctness.

- This approach is efficient because it avoids generating all subsequences,
  and instead counts them using combinatorics.
*/

/*
Arul has a binary array∗
 a
 of length n
.

He will take all subsequences†
 of length k
 (k
 is odd) of this array and find their median.‡

What is the sum of all these values?

As this sum can be very large, output it modulo 109+7
. In other words, print the remainder of this sum when divided by 109+7
.

∗
A binary array is an array consisting only of zeros and ones.

†
An array b
 is a subsequence of an array a
 if b
 can be obtained from a
 by the deletion of several (possibly, zero or all) elements. Subsequences don't have to be contiguous.

‡
The median of an array of odd length k
 is the k+12
-th element when sorted.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤2⋅105
, k
 is odd) — the length of the array and the length of the subsequence, respectively.

The second line of each test case contains n
 integers ai
 (0≤ai≤1
) — the elements of the array.

It is guaranteed that sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print the sum modulo 109+7
.

Example
InputCopy
8
4 3
1 0 0 1
5 1
1 1 1 1 1
5 5
0 1 0 1 0
6 3
1 0 1 0 1 1
4 3
1 0 1 1
5 3
1 0 1 1 0
2 1
0 0
34 17
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
OutputCopy
2
5
0
16
4
7
0
333606206
Note
In the first test case, there are four subsequences of [1,0,0,1]
 with length k=3
:

[1,0,0]
: median =0
.
[1,0,1]
: median =1
.
[1,0,1]
: median =1
.
[0,0,1]
: median =0
.
The sum of the results is 0+1+1+0=2
.
In the second test case, all subsequences of length 1
 have median 1
, so the answer is 5
.



 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
