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
void solve()
{
}

/*
With the approach of Valentine's Day, Skibidus desperately needs a way to rizz up his crush! Fortunately, he knows of just the way: creating the perfect Binary String!

Given a binary string∗
 t
, let x
 represent the number of 0
 in t
 and y
 represent the number of 1
 in t
. Its balance-value is defined as the value of max(x−y,y−x)
.

Skibidus gives you three integers n
, m
, and k
. He asks for your help to construct a binary string s
 of length n+m
 with exactly n
 0
's and m
 1
's such that the maximum balance-value among all of its substrings†
 is exactly k
. If it is not possible, output -1.

∗
A binary string only consists of characters 0
 and 1
.

†
A string a
 is a substring of a string b
 if a
 can be obtained from b
 by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first and only line of each test case contains three integers n
, m
, and k
 (0≤n,m≤2⋅105
, 1≤k≤n+m
, n+m≥1
).

It is guaranteed that the sum of n
 and the sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if it is possible to construct s
, output it on a new line. If there are multiple possible s
, output any. Otherwise, output -1 on a new line.

Example
InputCopy
6
1 2 1
4 3 2
2 4 3
8 3 2
5 0 4
5 0 5
OutputCopy
101
0100101
011011
-1
-1
00000
Note
In the first test case, we must construct s
 such that it contains one 0
, two 1
, and a maximum balance of 1
 among all of its substrings. One possible valid s
 is 101
 because:

Consider the substring bounded by indices [1,1]
. Its balance-value is max(0−1,1−0)=1
.
Consider the substring bounded by indices [1,2]
. Its balance-value is max(1−1,1−1)=0
.
Consider the substring bounded by indices [1,3]
. Its balance-value is max(1−2,2−1)=1
.
Consider the substring bounded by indices [2,2]
. Its balance-value is max(1−0,0−1)=1
.
Consider the substring bounded by indices [2,3]
. Its balance-value is max(1−1,1−1)=0
.
Consider the substring bounded by indices [3,3]
. Its balance-value is max(0−1,1−0)=1
.
Among all possible substrings, the maximum balance-value is 1
.

In the second test case, the substring with the maximum balance-value is 0100
, which has a balance of max(3−1,1−3)=2
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
