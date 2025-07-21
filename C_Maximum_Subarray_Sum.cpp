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

/*
==================== PROBLEM EXPLANATION ====================

You are given:
  - An integer n (length of the array)
  - An integer k (target maximum subarray sum)
  - A binary string s of length n:
      * If s[i] == '1', you know the value of a[i] (given in the input)
      * If s[i] == '0', you do NOT know a[i] (input will be 0, but you can set it to any value |a[i]| <= 1e18)
  - An array v of length n:
      * If s[i] == '1', v[i] is the known value
      * If s[i] == '0', v[i] is 0 (but you can change it)

Your task:
  - Fill in the missing values (where s[i] == '0') so that the maximum subarray sum of the resulting array is exactly k.
  - If it is possible, print "YES" and the resulting array (with all values, including the ones you filled in).
  - If it is not possible, print "NO".

Definitions:
  - The maximum subarray sum is the largest sum of any contiguous subarray.
  - You can set missing values to any integer in [-1e18, 1e18].

Key points:
  - If the current known values already have a maximum subarray sum > k, it is impossible (print NO).
  - If the current known values have maximum subarray sum == k, you can set all missing values to a very negative number (e.g., -1e18) so they never contribute to a larger sum.
  - Otherwise, you must try to fill in one of the missing values to "boost" the sum to exactly k, and set all other missing values to a very negative number so they don't interfere.
  - If there are no missing values and the max subarray sum < k, it is impossible.

Example:
  n = 3, k = 5
  s = "011"
  v = [0, 0, 1]
  You can set v[0] = 4, so the array is [4, 0, 1], and the max subarray sum is 5.

============================================================
*/

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> v;
    string s;
    cin >> s;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a); // Read the array values (0 if unknown)
    }
    ll mx = 0;  // Current subarray sum for Kadane's algorithm
    ll res = 0; // Maximum subarray sum found so far
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            // Only consider known values for initial max subarray sum
            mx = max(mx + v[i], v[i]);
            res = max(res, mx);
        }
        else
        {
            mx = 0; // Reset sum at unknowns (since they could be anything)
        }
    }
    if (res > k)
    {
        // If the known values already exceed k, impossible
        cout << "NO" << endl;
    }
    else if (res == k)
    {
        // If the known values already achieve k, set all unknowns to -1e18
        cout << "YES" << endl;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                v[i] = -1e18; // Set unknowns to very negative so they don't affect max sum
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << nl;
        }
        cout << nl;
    }
    else
    {
        // Try to boost the sum to exactly k by setting one unknown appropriately
        ll zer = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zer = i; // Find the first unknown position
                break;
            }
        }
        if (zer == -1)
        {
            // No unknowns and sum < k, impossible
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        ll pref = 0; // Maximum prefix sum ending just before zer
        ll psum = 0;
        ll ssum = 0;
        for (int i = zer - 1; i >= 0; i--)
        {
            psum += v[i];
            pref = max(psum, pref); // Track max prefix sum
        }

        ll suff = 0; // Maximum suffix sum starting just after zer
        for (int i = zer + 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                break; // Stop at next unknown
            }
            else
            {
                ssum += v[i];
                suff = max(ssum, suff); // Track max suffix sum
            }
        }
        // Set the unknown so that the sum of prefix + this + suffix = k
        v[zer] = k - pref - suff;

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0' && i != zer)
            {
                v[i] = -1e18; // Set all other unknowns to very negative
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << nl;
        }
        cout << nl;
    }
}

/*
You are given an array a1,a2,…,an
 of length n
 and a positive integer k
, but some parts of the array a
 are missing. Your task is to fill the missing part so that the maximum subarray sum∗
 of a
 is exactly k
, or report that no solution exists.

Formally, you are given a binary string s
 and a partially filled array a
, where:

If you remember the value of ai
, si=1
 to indicate that, and you are given the real value of ai
.
If you don't remember the value of ai
, si=0
 to indicate that, and you are given ai=0
.
All the values that you remember satisfy |ai|≤106
. However, you may use values up to 1018
 to fill in the values that you do not remember. It can be proven that if a solution exists, a solution also exists satisfying |ai|≤1018
.

∗
The maximum subarray sum of an array a
 of length n
, i.e. a1,a2,…an
 is defined as max1≤i≤j≤nS(i,j)
 where S(i,j)=ai+ai+1+…+aj
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two numbers n,k
 (1≤n≤2⋅105,1≤k≤1012
).

The second line of each test case contains a binary (01
) string s
 of length n
.

The third line of each test case contains n
 numbers a1,a2,…,an
 (|ai|≤106
). If si=0
, then it's guaranteed that ai=0
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, first output Yes
 if a solution exists or No
 if no solution exists. You may print each character in either case, for example YES
 and yEs
 will also be accepted.

If there's at least one solution, print n
 numbers a1,a2,…,an
 on the second line. |ai|≤1018
 must hold.

Example
InputCopy
10
3 5
011
0 0 1
5 6
11011
4 -3 0 -2 1
4 4
0011
0 0 -4 -5
6 12
110111
1 2 0 5 -1 9
5 19
00000
0 0 0 0 0
5 19
11001
-8 6 0 0 -5
5 10
10101
10 0 10 0 10
1 1
1
0
3 5
111
3 -1 3
4 5
1011
-2 0 1 -5
OutputCopy
Yes
4 0 1
Yes
4 -3 5 -2 1
Yes
2 2 -4 -5
No
Yes
5 1 9 2 2
Yes
-8 6 6 7 -5
Yes
10 -20 10 -20 10
No
Yes
3 -1 3
Yes
-2 4 1 -5
Note
In test case 1
, only the first position is not filled. We can fill it with 4
 to get the array [4,0,1]
 which has maximum subarray sum of 5
.

In test case 2
, only the third position is not filled. We can fill it with 5
 to get the array [4,−3,5,−2,1]
. Here the maximum subarray sum comes from the subarray [4,−3,5]
 and it is 6
, as required.

In test case 3
, the first and second positions are unfilled. We can fill both with 2
 to get the array [2,2,−4,−5]
 which has a maximum subarray sum of 4
. Note that other outputs are also possible such as [0,4,−4,−5]
.

In test case 4
, it is impossible to get a valid array. For example, if we filled the third position with 0
, we get [1,2,0,5,−1,9]
, but this has a maximum subarray sum of 16
, not 12
 as required.
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
