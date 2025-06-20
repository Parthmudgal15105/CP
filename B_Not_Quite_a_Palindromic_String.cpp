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
    int n, k;
    cin >> n >> k; // Fixed: Use >> instead of , to read both values
    string s;
    cin >> s;

    int z = 0;
    int o = 0;
    for (char c : s)
    {
        if (c == '0')
            z++;
        else
            o++;
    }

    // Minimum number of good pairs possible
    int min_k = max(n / 2 - z, n / 2 - o);
    // Maximum number of good pairs possible
    int max_k = n / 2;

    // Check if k is valid:
    // 1. It must be between min_k and max_k
    // 2. (z + k - n/2) must be even for a valid arrangement
    if (min_k <= k && k <= max_k && (z + k - n / 2) % 2 == 0)
    {
        cyes;
    }
    else
    {
        cno;
    }
}

/*
Vlad found a binary string∗
 s
 of even length n
. He considers a pair of indices (i,n−i+1
), where 1≤i<n−i+1
, to be good if si=sn−i+1
 holds true.

For example, in the string '010001' there is only 1
 good pair, since s1≠s6
, s2≠s5
, and s3=s4
. In the string '0101' there are no good pairs.

Vlad loves palindromes, but not too much, so he wants to rearrange some characters of the string so that there are exactly k
 good pairs of indices.

Determine whether it is possible to rearrange the characters in the given string so that there are exactly k
 good pairs of indices (i,n−i+1
).

∗
A string s
 is called binary if it consists only of the characters '0' and '1'

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (2≤n≤2⋅105
, 0≤k≤n2
, n
 is even) — the length of the string and the required number of good pairs.

The second line of each test case contains a binary string s
 of length n
.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if there is a way to rearrange the characters of the string so that there are exactly k
 good pairs, otherwise output "NO".

You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
InputCopy
6
6 2
000000
2 1
01
4 1
1011
10 2
1101011001
10 1
1101011001
2 1
11
OutputCopy
NO
NO
YES
NO
YES
YES
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
