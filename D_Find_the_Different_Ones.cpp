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
    // Read array size
    ll n;
    cin >> n;

    // Create and read array of size n
    vll arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Store indices where adjacent elements are different
    vector<int> diff;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            diff.push_back(i);
        }
    }

    // Process queries
    int q;
    cin >> q;
    while (q--)
    {
        // Read query range [l,r]
        ll l, r;
        cin >> l >> r;
        // Convert to 0-based indexing
        l--;
        r--;

        // Find first position in diff array >= l using binary search
        ll pos = lower_bound(diff.begin(), diff.end(), l) - diff.begin();

        // Check if we found a valid different pair within range [l,r]
        if (pos < diff.size() && diff[pos] < r)
        {
            // Output the pair of indices (1-based indexing)
            cout << diff[pos] + 1 << " " << diff[pos] + 2 << "\n";
        }
        else
        {
            // No different pair found in range
            cout << "-1 -1\n";
        }
    }
}

/*
You are given an array a
 of n
 integers, and q
 queries.

Each query is represented by two integers l
 and r
 (1≤l≤r≤n
). Your task is to find, for each query, two indices i
 and j
 (or determine that they do not exist) such that:

l≤i≤r
;
l≤j≤r
;
ai≠aj
.
In other words, for each query, you need to find a pair of different elements among al,al+1,…,ar
, or report that such a pair does not exist.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) — the length of the array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤106
) — the elements of the array a
.

The third line of each test case contains a single integer q
 (1≤q≤2⋅105
) — the number of queries.

The next q
 lines contain two integers each, l
 and r
 (1≤l<r≤n
) — the boundaries of the query.

It is guaranteed that the sum of the values of n
 across all test cases does not exceed 2⋅105
. Similarly, it is guaranteed that the sum of the values of q
 across all test cases does not exceed 2⋅105
.

Output
For each query, output two integers separated by space: i
 and j
 (l≤i,j≤r
), for which ai≠aj
. If such a pair does not exist, output i=−1
 and j=−1
.

You may separate the outputs for the test cases with empty lines. This is not a mandatory requirement.
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
