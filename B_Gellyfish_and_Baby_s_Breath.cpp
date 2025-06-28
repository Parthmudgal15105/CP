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
static const int MAXN = 100000;
const ll MOD = 998244353;
static int pw2[MAXN + 1];

// Precompute powers of 2 modulo MOD up to MAXN
void precompute()
{
    pw2[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
}

// Main logic for a single test case
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    // pMax, qMax: current maximums in p and q up to i
    // ind1, ind2: indices where pMax and qMax were last updated
    int pMax = -1, ind1 = -1;
    int qMax = -1, ind2 = -1;
    vector<int> r(n);

    // For each i, compute r[i] as described in the problem
    for (int i = 0; i < n; i++)
    {
        // Update pMax and its index if current p[i] is greater
        if (p[i] > pMax)
        {
            pMax = p[i];
            ind1 = i;
        }
        // Update qMax and its index if current q[i] is greater
        if (q[i] > qMax)
        {
            qMax = q[i];
            ind2 = i;
        }

        // L is the maximum value among all p[0..i] and q[0..i]
        int L = max(pMax, qMax);
        int secondExp = -1;

        // Find the "second" exponent for the max term
        // If pMax is the current max, try to pair it with q[k] where k = i - ind1
        if (pMax == L)
        {
            int k = i - ind1;
            if (k >= 0 && k < n)
                secondExp = max(secondExp, q[k]);
        }
        // If qMax is the current max, try to pair it with p[j] where j = i - ind2
        if (qMax == L)
        {
            int j = i - ind2;
            if (j >= 0 && j < n)
                secondExp = max(secondExp, p[j]);
        }

        // r[i] = 2^L + 2^secondExp (modulo MOD)
        r[i] = (pw2[L] + pw2[secondExp]) % MOD;
    }

    // Output the result for this test case
    for (int i = 0; i < n; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}

/*
Flower gives Gellyfish two permutations∗
 of [0,1,…,n−1]
: p0,p1,…,pn−1
 and q0,q1,…,qn−1
.

Now Gellyfish wants to calculate an array r0,r1,…,rn−1
 through the following method:

For all i
 (0≤i≤n−1
), ri=maxj=0i(2pj+2qi−j)
But since Gellyfish is very lazy, you have to help her figure out the elements of r
.

Since the elements of r
 are very large, you are only required to output the elements of r
 modulo 998244353
.

∗
An array b
 is a permutation of an array a
 if b
 consists of the elements of a
 in arbitrary order. For example, [4,2,3,4]
 is a permutation of [3,2,4,4]
 while [1,2,2]
 is not a permutation of [1,2,3]
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤105
).

The second line of each test case contains n
 integers p0,p1,…,pn−1
 (0≤pi<n
).

The third line of each test case contains n
 integers q0,q1,…,qn−1
 (0≤qi<n
).

It is guaranteed that both p
 and q
 are permutations of [0,1,…,n−1]
.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case, output n
 integers r0,r1,…,rn−1
 in a single line, modulo 998244353
.

Example
InputCopy
3
3
0 2 1
1 2 0
5
0 1 2 3 4
4 3 2 1 0
10
5 8 9 3 4 0 2 7 1 6
9 5 1 4 0 3 2 8 7 6
OutputCopy
3 6 8
17 18 20 24 32
544 768 1024 544 528 528 516 640 516 768
Note
In the first test case:

r0=2p0+2q0=1+2=3
r1=max(2p0+2q1,2p1+2q0)=max(1+4,4+2)=6
r2=max(2p0+2q2,2p1+2q1,2p2+2q0)=(1+1,4+4,2+2)=8
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute(); // Precompute all powers of 2 modulo MOD
    int t = 1;
    cin >> t;
    while (t--)
        solve(); // Solve each test case
}
