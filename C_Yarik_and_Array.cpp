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
    ll n;
    cin >> n;

    // sum: keeps track of current subarray sum
    // maxi: stores maximum sum found so far
    // par: stores parity (odd/even) of previous element
    ll sum = 0, maxi = INT_MIN, par = -1;

    for (ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;

        if (i == 0)
        {
            // For first element, initialize all values
            sum = b;
            maxi = b;
            par = abs(b) % 2; // get parity (0 for even, 1 for odd)
        }
        else
        {
            // For subsequent elements
            if (abs(b) % 2 != par)
            {
                // If current element has different parity than previous
                // We can extend our current subarray
                sum += b;
            }
            else
            {
                // If same parity, we need to start a new subarray
                // from current element
                sum = b;
            }

            // If current element is greater than current sum
            // start new subarray from this element
            if (b > sum)
            {
                sum = b;
            }

            // Update parity for next iteration
            par = abs(b) % 2;

            // Update maximum sum found so far
            maxi = max(sum, maxi);
        }
    }
    cout << maxi << endl;
}

/*
A subarray is a continuous part of array.

Yarik recently found an array a
 of n
 elements and became very interested in finding the maximum sum of a non empty subarray. However, Yarik doesn't like consecutive integers with the same parity, so the subarray he chooses must have alternating parities for adjacent elements.

For example, [1,2,3]
 is acceptable, but [1,2,4]
 is not, as 2
 and 4
 are both even and adjacent.

You need to help Yarik by finding the maximum sum of such a subarray.

Input
The first line contains an integer t
 (1≤t≤104)
 — number of test cases. Each test case is described as follows.

The first line of each test case contains an integer n
 (1≤n≤2⋅105)
 — length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (−103≤ai≤103)
 — elements of the array.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the answer to the problem.

Example
InputCopy
7
5
1 2 3 4 5
4
9 9 8 8
6
-1 4 -1 0 5 -4
4
-1 2 4 -3
1
-1000
3
101 -99 101
20
-10 5 -8 10 6 -10 7 9 -2 -6 7 2 -4 6 -1 7 -6 -7 4 1
OutputCopy
15
17
8
4
-1000
101
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
