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
    vector<int> a(n);

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /* Key insight: a[i] & a[j] >= a[i] ^ a[j] is true when
       the highest set bit position of both numbers is the same.

       Example: 6 (110) and 5 (101)
       6 & 5 = 100 (4)
       6 ^ 5 = 011 (3)
       4 > 3, so this is a valid pair
    */

    // Array to store count of numbers with same highest set bit position
    // count[i] = number of elements whose highest set bit is at position i
    vector<long long> count(31, 0);

    for (int i = 0; i < n; i++)
    {
        // __builtin_clz counts leading zeros
        // 31 - leading zeros = position of highest set bit
        // Example: for 6 (110) -> leading zeros = 29, so pos = 2
        int pos = 31 - __builtin_clz(a[i]);
        count[pos]++;
    }

    /* For each position, calculate number of pairs possible
       If we have k numbers with same highest bit position,
       number of pairs = k * (k-1) / 2

       Example: if we have 3 numbers with highest bit at pos 2
       pairs possible = 3 * 2 / 2 = 3 pairs
    */
    long long ans = 0;
    for (int i = 0; i < 31; i++)
    {
        ans += (count[i] * (count[i] - 1)) / 2;
    }

    cout << ans << '\n';
}

/*
Danik urgently needs rock and lever! Obviously, the easiest way to get these things is to ask Hermit Lizard for them.

Hermit Lizard agreed to give Danik the lever. But to get a stone, Danik needs to solve the following task.

You are given a positive integer n
, and an array a
 of positive integers. The task is to calculate the number of such pairs (i,j)
 that i<j
 and ai
 &
 aj≥ai⊕aj
, where &
 denotes the bitwise AND operation, and ⊕
 denotes the bitwise XOR operation.

Danik has solved this task. But can you solve it?

Input
Each test contains multiple test cases.

The first line contains one positive integer t
 (1≤t≤10
) denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer n
 (1≤n≤105
) — length of the array.

The second line contains n
 positive integers ai
 (1≤ai≤109
) — elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For every test case print one non-negative integer — the answer to the problem.

Example
InputCopy
5
5
1 4 3 7 10
3
1 1 1
4
6 2 5 3
2
2 4
1
1
OutputCopy
1
3
2
0
0
Note
In the first test case there is only one pair: (4,7)
: for it 4
 &
 7=4
, and 4⊕7=3
.

In the second test case all pairs are good.

In the third test case there are two pairs: (6,5)
 and (2,3)
.

In the fourth test case there are no good pairs.
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
