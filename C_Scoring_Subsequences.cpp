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
    // Read the size of the array
    int n;
    cin >> n;

    // Read the non-decreasing array
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Initialize cost to represent the length of the valid subsequence that maximizes the score
    int cost = 0;
    vector<int> res(n);

    // Iterate over each prefix of the array
    for (int k = 0; k < n; k++)
    {
        // Try to extend the subsequence length (cost) for the current prefix
        while (cost <= k && a[k - cost] >= cost + 1)
        {
            cost++;
        }
        // Store the maximum valid subsequence length for the current prefix
        res[k] = cost;
    }

    // Print the results for each prefix
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

/*
The score of a sequence [s1,s2,…,sd]
 is defined as s1⋅s2⋅…⋅sdd!
, where d!=1⋅2⋅…⋅d
. In particular, the score of an empty sequence is 1
.

For a sequence [s1,s2,…,sd]
, let m
 be the maximum score among all its subsequences. Its cost is defined as the maximum length of a subsequence with a score of m
.

You are given a non-decreasing sequence [a1,a2,…,an]
 of integers of length n
. In other words, the condition a1≤a2≤…≤an
 is satisfied. For each k=1,2,…,n
, find the cost of the sequence [a1,a2,…,ak]
.

A sequence x
 is a subsequence of a sequence y
 if x
 can be obtained from y
 by deletion of several (possibly, zero or all) elements.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤105
) — the length of the given sequence.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the given sequence. It is guaranteed that its elements are in non-decreasing order.

It is guaranteed that the sum of n
 over all test cases does not exceed 5⋅105
.

Output
For each test case, output n
 integers — the costs of sequences [a1,a2,…,ak]
 in ascending order of k
.

Example
InputCopy
3
3
1 2 3
2
1 1
5
5 5 5 5 5
OutputCopy
1 1 2
1 1
1 2 3 4 5
Note
In the first test case:

The maximum score among the subsequences of [1]
 is 1
. The subsequences [1]
 and []
 (the empty sequence) are the only ones with this score. Thus, the cost of [1]
 is 1
.
The maximum score among the subsequences of [1,2]
 is 2
. The only subsequence with this score is [2]
. Thus, the cost of [1,2]
 is 1
.
The maximum score among the subsequences of [1,2,3]
 is 3
. The subsequences [2,3]
 and [3]
 are the only ones with this score. Thus, the cost of [1,2,3]
 is 2
.
Therefore, the answer to this case is 112
, which are the costs of [1],[1,2]
 and [1,2,3]
 in this order.
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
