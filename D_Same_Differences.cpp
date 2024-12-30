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

/*----------------------------------------------------------------------------*/
void solve()
{
    // Read the size of array
    int n;
    cin >> n;

    // Create and input array of size n
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // ans will store the count of valid pairs
    long long ans = 0;

    // freq map stores the frequency of (a[i] - i)
    // if a[j] - a[i] = j - i
    // then a[j] - j = a[i] - i
    // So we count elements having same value of (a[i] - i)
    unordered_map<long long, long long> freq;

    for (int i = 0; i < n; i++)
    {
        // Calculate a[i] - i for current element
        long long val = a[i] - i;

        // Add current frequency of val to answer
        // This counts all previous positions that can form a pair with current position
        ans += freq[val];

        // Increment frequency of current val
        freq[val]++;
    }

    // Print the total count of valid pairs
    cout << ans << nl;
}

/*
You are given an array a
 of n
 integers. Count the number of pairs of indices (i,j)
 such that i<j
 and aj−ai=j−i
.

Input
The first line contains one integer t
 (1≤t≤104
). Then t
 test cases follow.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case output the number of pairs of indices (i,j)
 such that i<j
 and aj−ai=j−i
.

Example
InputCopy
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
OutputCopy
1
3
3
10
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
