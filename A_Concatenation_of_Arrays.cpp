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

bool compareArrays(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first + a.second) < (b.first + b.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arrays(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrays[i].first >> arrays[i].second;
    }
    sort(arrays.begin(), arrays.end(), compareArrays);
    for (auto &p : arrays)
    {
        cout << p.first << sp << p.second << sp;
    }
    cout << nl;
}

/*You are given n
 arrays a1
, …
, an
. The length of each array is two. Thus, ai=[ai,1,ai,2]
. You need to concatenate the arrays into a single array of length 2n
 such that the number of inversions†
 in the resulting array is minimized. Note that you do not need to count the actual number of inversions.

More formally, you need to choose a permutation‡
 p
 of length n
, so that the array b=[ap1,1,ap1,2,ap2,1,ap2,2,…,apn,1,apn,2]
 contains as few inversions as possible.

†
The number of inversions in an array c
 is the number of pairs of indices i
 and j
 such that i<j
 and ci>cj
.

‡
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤105
) — the number of arrays.

Each of the following n
 lines contains two integers ai,1
 and ai,2
 (1≤ai,j≤109
) — the elements of the i
-th array.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case, output 2n
 integers — the elements of the array you obtained. If there are multiple solutions, output any of them.

Example
InputCopy
4
2
1 4
2 3
3
3 2
4 3
2 1
5
5 10
2 3
9 6
4 1
8 7
1
10 20
OutputCopy
2 3 1 4
2 1 3 2 4 3
4 1 2 3 5 10 8 7 9 6
10 20
Note
In the first test case, we concatenated the arrays in the order 2,1
. Let's consider the inversions in the resulting array b=[2,3,1,4]
:

i=1
, j=3
, since b1=2>1=b3
;
i=2
, j=3
, since b2=3>1=b3
.
Thus, the number of inversions is 2
. It can be proven that this is the minimum possible number of inversions.

In the second test case, we concatenated the arrays in the order 3,1,2
. Let's consider the inversions in the resulting array b=[2,1,3,2,4,3]
:

i=1
, j=2
, since b1=2>1=b2
;
i=3
, j=4
, since b3=3>2=b4
;
i=5
, j=6
, since b5=4>3=b6
.
Thus, the number of inversions is 3
. It can be proven that this is the minimum possible number of inversions.

In the third test case, we concatenated the arrays in the order 4,2,1,5,3
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
