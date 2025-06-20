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
/*
Explanation of the solution:

- The goal is to maximize the sum of set bits (beauty) in the array after at most k increments.
- Each increment can be applied to any element, and increases its value by 1.
- To maximize the beauty, we want to set as many unset bits (0s) to 1 as possible, starting from the least significant bit (LSB) to the most significant bit (MSB), since lower bits require fewer increments.

Approach:
1. For each bit position from 0 to 64:
   - For each element in the array:
     - If the current bit is 0 and we have enough k to set it (i.e., k >= 2^i), set this bit by adding 2^i to the element and decrease k by 2^i.
     - Only perform the operation if k is still non-negative after the operation.
2. After all possible bit settings, calculate the total beauty by summing the number of set bits in all elements.
3. Output the result.

This greedy approach ensures that we use k efficiently to maximize the number of set bits in the array.
*/

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i]; // Read the array
    }

    // Try to set as many 0-bits to 1 as possible, starting from LSB to MSB
    for (ll i = 0; i <= 64; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            // If k is positive and the i-th bit of v[j] is 0
            if (k > 0 && (v[j] & (1ll << i)) == 0)
            {
                k -= (1ll << i); // Use k to set this bit

                if (k >= 0)
                {
                    v[j] = v[j] + (1ll << i); // Actually set the bit if k is still non-negative
                }
                // If k < 0 after subtracting, the bit is not set and k remains negative for the rest
            }
        }
    }
    ll ans = 0;

    // Calculate the total number of set bits (beauty) in the array
    for (ll i = 0; i < n; i++)
    {
        ans += __builtin_popcountll(v[i]);
    }

    cout << ans << endl; // Output the answer for this test case
}
/*
\You are given an array a
 of n
 integers. We define the beauty
 of a number x
 to be the number of 1
 bits in its binary representation. We define the beauty of an array to be the sum of beauties of the numbers it contains.

In one operation, you can select an index i
 (1≤i≤n)
 and increase ai
 by 1
.

Find the maximum beauty of the array after doing at most k
 operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤n≤5000
, 0≤k≤1018
) — the length of the array and the maximal number of operations.

The second line of each test case contains n
 integers a1,a2,…an
 (0≤ai≤109
) —denoting the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, output a single integer, the maximum beauty after at most k
 operations.

Example
InputCopy
5
5 2
0 1 7 2 4
5 3
0 1 7 2 4
1 1
3
3 0
2 0 3
1 100000000000
0
OutputCopy
8
9
2
3
36
Note
In the first test case, a=[0,1,7,2,4]
.

apply the first operation at i=1
, the new array is a=[1,1,7,2,4]
apply the second operation at i=4
, the new array is a=[1,1,7,3,4]
The beauty of this array is 1+1+3+2+1=8
. One of the other valid solutions with the same beauty is [0,1,7,3,5]
.
In the third test case, a=[3]
. Since you are not required to use exactly k
 operations, it is optimal to do none.
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
