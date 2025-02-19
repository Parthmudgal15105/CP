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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
/*
    Main helper function that constructs the permutation for even-length inputs
    Strategy:
    1. Handle special cases for n=4 and n=6
    2. For other cases:
       - Find largest power of 2 less than or equal to n (y)
       - Construct permutation to maximize bitwise operations
*/
vector<int> func(int n)
{
    // Special case handling for n=4
    if (n == 4)
    {
        vector<int> ans = {2, 1, 3, 4};
        return ans;
    }
    // Special case handling for n=6
    if (n == 6)
    {
        vector<int> ans = {1, 2, 4, 6, 5, 3};
        return ans;
    }

    // Find largest power of 2 less than or equal to n
    int x = log2(n);
    int y = (1 << x); // y = 2^x

    // Construct the optimal permutation
    vector<int> ans;
    // Add key elements to maximize bitwise operations
    ans.push_back(y);     // Add largest power of 2
    ans.push_back(y - 1); // Add y-1
    ans.push_back(y - 2); // Add y-2
    ans.push_back(3);
    ans.push_back(1);
    ans.push_back(2);

    // Fill remaining numbers in specific order
    for (int i = 4; i < y - 2; i++)
        ans.push_back(i);
    for (int i = y + 1; i <= n; i++)
        ans.push_back(i);

    // Reverse to get optimal arrangement for AND/OR operations
    reverse(ans.begin(), ans.end());
    return ans;
}

/*
    Main solving function:
    1. For odd n:
       - Get permutation for n-1 and append n
       - Maximum value will be n
    2. For even n:
       - Use func() to get optimal permutation
       - Maximum value will be (2^(log2(n)+1)) - 1
*/
void solve()
{
    int n;
    cin >> n;
    if (n % 2) // Odd case
    {
        vector<int> ans = func(n - 1);
        ans.push_back(n);
        cout << n << '\n'; // For odd n, maximum value is n itself
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    else // Even case
    {
        vector<int> ans = func(n);
        // Calculate maximum value: 2^(log2(n)+1) - 1
        int k = 1 << ((int)log2(n) + 1);
        k--;
        cout << k << '\n';
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}
/*
Alya has been given a hard problem. Unfortunately, she is too busy running for student council. Please solve this problem for her.

Given an integer n
, construct a permutation p
 of integers 1,2,…,n
 that maximizes the value of k
 (which is initially 0
) after the following process.

Perform n
 operations, on the i
-th operation (i=1,2,…,n
),

If i
 is odd, k=k&pi
, where &
 denotes the bitwise AND operation.
If i
 is even, k=k|pi
, where |
 denotes the bitwise OR operation.
Input
The first line contains a single integer t
 (1≤t≤500
) — the number of test cases.

The only line of each test case contains a single integer n
 (5≤n≤2⋅105
) — the length of the permutation.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum value of k
 in the first line and output the permutation p1,p2,…,pn
 in the second line.

If there are multiple such permutations, output any.

Example
InputCopy
6
5
6
7
8
9
10
OutputCopy
5
2 1 3 4 5
7
1 2 4 6 5 3
7
2 4 5 1 3 6 7
15
2 4 5 1 3 6 7 8
9
2 4 5 6 7 1 3 8 9
15
1 2 3 4 5 6 8 10 9 7
Note
For the first test case, the value of k
 is determined as follows:

k=0
 initially.

On the 1
st operation, 1
 is odd, so Alya sets k
 to be k&p1=0&2=0
.
On the 2
nd operation, 2
 is even, so Alya sets k
 to be k|p2=0|1=1
.
On the 3
rd operation, 3
 is odd, so Alya sets k
 to be k&p3=1&3=1
.
On the 4
th operation, 4
 is even, so Alya sets k
 to be k|p4=1|4=5
.
On the 5
th operation, 5
 is odd, so Alya sets k
 to be k&p5=5&5=5
.
The final value of k
 is 5
. It can be shown that the final value of k
 is at most 5
 for all permutations of length 5
. Another valid output is [2,3,1,4,5]
.

For the second test case, the final value of k
 is 7
. It can be shown that the final value of k
 is at most 7
 for all permutations of length 6
. Other valid outputs include [2,4,1,6,3,5]
 and [5,2,6,1,3,4]
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
