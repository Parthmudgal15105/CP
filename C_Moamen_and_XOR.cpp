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
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
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
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/

// Computes (a^b) % m using fast (binary) exponentiation in O(log b)
long long mpow(long long a, long long b, long long m)
{
    long long res = 1; // accumulator for the result
    a %= m;            // ensure base is within [0, m)
    while (b > 0)
    {
        if (b & 1)
        {                        // if the current least‐significant bit of b is 1
            res = (res * a) % m; // multiply res by the current base
        }
        a = (a * a) % m; // square the base for the next bit
        b >>= 1;         // shift exponent right to process the next bit
    }
    return res;
}

ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;

    // Special case: if k == 0, all array elements are in [0, 1),
    // so the only possible array is all zeros: AND = 0, XOR = 0 ⇒ AND ≥ XOR
    if (k == 0)
    {
        cout << 1 << nl;
        return;
    }

    // We’ll build a DP over bits: dp[b] = number of winning arrays
    // when each element is in [0, 2^(b+1)), i.e. considering bits 0..b.
    vector<long long> dp(k, 0);

    // Process bit 0 (the least significant bit) separately:
    //  - There are 2^n total assignments of 0/1 to n positions.
    //  - XOR = 0 whenever the number of 1s is even ⇒ exactly 2^(n-1) ways.
    //  - AND = 1 only when all bits = 1 ⇒ exactly 1 way.
    // For AND ≥ XOR on this single bit:
    //  - If n is even: only XOR=0 cases count ⇒ 2^(n-1).
    //  - If n is odd: XOR=0 gives 2^(n-1), plus the all-1s case has AND=1, XOR=1 ⇒ +1.
    long long base = mpow(2, n - 1, mod);
    if (n % 2 == 0)
        dp[0] = base;
    else
        dp[0] = (base + 1) % mod;

    // Now build dp for bits 1..k-1
    // At each new bit b:
    //  - We split on how we set bit b over all n elements.
    //  - The condition AND ≥ XOR is equivalent to saying that
    //    at the highest bit where AND and XOR differ, AND must have 1 and XOR 0.
    //  - One can show this recurrence holds and, in fact,
    //    dp[b] = (dp[b-1] * dp[0]) % mod  ⇒ dp[b] = dp[0]^(b+1).
    // Here’s how the code arrives at it:
    for (ll bit = 1; bit < k; bit++)
    {
        long long ways = 0;
        if (n % 2 == 0)
        {
            // n even:
            // 1) All entries have bit=0 ⇒ no effect on AND/XOR at this bit:
            //    number of ways to choose bits 0..bit−1 is 2^(bit*n).
            ways = mpow(2, bit * n, mod);

            // 2) Choose bit=1 in an odd number of positions (so XOR=1, AND=0):
            //    there are (2^(n-1) − 1) such assignments of this bit,
            //    and for each we need a winning lower-bit pattern ⇒ dp[bit−1].
            long long tmp = ((base - 1 + mod) % mod) * dp[bit - 1] % mod;
            ways = (ways + tmp) % mod;
        }
        else
        {
            // n odd:
            // 1) All bit=0 ⇒ inherit dp[bit−1].
            ways = dp[bit - 1];

            // 2) All bit=1 ⇒ XOR=1 and AND=1 at this bit ⇒ still AND≥XOR,
            //    times the number of ways to choose this bit pattern (2^(n-1)) and lower bits.
            long long tmp = base * dp[bit - 1] % mod;
            ways = (ways + tmp) % mod;
        }
        dp[bit] = ways;
    }

    // Our answer is the count for elements < 2^k ⇒ dp[k-1]
    cout << dp[k - 1] << nl;
}
/*
Moamen and Ezzat are playing a game. They create an array a
 of n
 non-negative integers where every element is less than 2k
.

Moamen wins if a1&a2&a3&…&an≥a1⊕a2⊕a3⊕…⊕an
.

Here &
 denotes the bitwise AND operation, and ⊕
 denotes the bitwise XOR operation.

Please calculate the number of winning for Moamen arrays a
.

As the result may be very large, print the value modulo 1000000007
 (109+7
).

Input
The first line contains a single integer t
 (1≤t≤5
)— the number of test cases.

Each test case consists of one line containing two integers n
 and k
 (1≤n≤2⋅105
, 0≤k≤2⋅105
).

Output
For each test case, print a single value — the number of different arrays that Moamen wins with.

Print the result modulo 1000000007
 (109+7
).

Example
InputCopy
3
3 1
2 1
4 0
OutputCopy
5
2
1
Note
In the first example, n=3
, k=1
. As a result, all the possible arrays are [0,0,0]
, [0,0,1]
, [0,1,0]
, [1,0,0]
, [1,1,0]
, [0,1,1]
, [1,0,1]
, and [1,1,1]
.

Moamen wins in only 5
 of them: [0,0,0]
, [1,1,0]
, [0,1,1]
, [1,0,1]
, and [1,1,1]
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
