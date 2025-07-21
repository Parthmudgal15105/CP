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
#define MOD 1000000007
/*----------------------------------------------------------------------------*/

void solve()
{
    int x, n;
    cin >> n;
    vi a(1000001); // a[k] = number of good subsequences of length k
    a[0] = 1;      // Base case: empty subsequence (used for transitions, not counted in answer)
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vi dp;
        // Find all divisors of x (these are possible positions in the subsequence)
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                dp.push_back(j);
                if (j * j != x)
                {
                    dp.push_back(x / j);
                }
            }
        }
        // Sort divisors in decreasing order to avoid using updated values in this round
        sort(dp.begin(), dp.end());
        reverse(all(dp));

        // For each possible length d (divisor), update the number of good subsequences of length d
        for (auto d : dp)
        {
            // If we append x as the d-th element, and x is divisible by d,
            // then any good subsequence of length d-1 can be extended to length d
            a[d] += a[d - 1];
            a[d] %= MOD;
        }
    }
    // Sum up all good subsequences of length >= 1
    for (int i = 1; i <= 1000000; i++)
    {
        ans += a[i];
        ans %= MOD;
    }
    cout << ans;
}
/*
You are given an integer array a1,a2,…,an
.

The array b
 is called to be a subsequence of a
 if it is possible to remove some elements from a
 to get b
.

Array b1,b2,…,bk
 is called to be good if it is not empty and for every i
 (1≤i≤k
) bi
 is divisible by i
.

Find the number of good subsequences in a
 modulo 109+7
.

Two subsequences are considered different if index sets of numbers included in them are different. That is, the values ​of the elements ​do not matter in the comparison of subsequences. In particular, the array a
 has exactly 2n−1
 different subsequences (excluding an empty subsequence).

Input
The first line contains an integer n
 (1≤n≤100000
) — the length of the array a
.

The next line contains integers a1,a2,…,an
 (1≤ai≤106
).

Output
Print exactly one integer — the number of good subsequences taken modulo 109+7
.

Examples
InputCopy
2
1 2
OutputCopy
3
InputCopy
5
2 2 1 22 14
OutputCopy
13
Note
In the first example, all three non-empty possible subsequences are good: {1}
, {1,2}
, {2}

In the second example, the possible good subsequences are: {2}
, {2,2}
, {2,22}
, {2,14}
, {2}
, {2,22}
, {2,14}
, {1}
, {1,22}
, {1,14}
, {22}
, {22,14}
, {14}
.

Note, that some subsequences are listed more than once, since they occur in the original array multiple times.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
