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
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << 1 << nl;
        cout << 1 << nl;
        return;
    }
    if (k == 1 || k == n)
    {
        cout << -1 << nl;
        return;
    }
    if (k % 2 == 0 && (n - k) % 2 == 0)
    {
        cout << 1 << sp <<
    }
}

/*
You are given an array a=[1,2,…,n]
, where n
 is odd, and an integer k
.

Your task is to choose an odd positive integer m
 and to split a
 into m
 subarrays†
 b1,b2,…,bm
 such that:

Each element of the array a
 belongs to exactly one subarray.
For all 1≤i≤m
, |bi|
 is odd, i.e., the length of each subarray is odd.
median([median(b1),median(b2),…,median(bm)])=k
, i.e., the median‡
 of the array of medians of all subarrays must equal k
. median(c)
 denotes the median of the array c
.
†
A subarray of the array a
 of length n
 is the array [al,al+1,…,ar]
 for some integers 1≤l≤r≤n
.

‡
A median of the array of odd length is the middle element after the array is sorted in non-decreasing order. For example: median([1,2,5,4,3])=3
, median([3,2,1])=2
, median([2,1,2,1,2,2,2])=2
.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤5000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤k≤n<2⋅105
, n
 is odd) — the length of array a
 and the desired median of the array of medians of all subarrays.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case:

If there is no suitable partition, output −1
 in a single line.
Otherwise, in the first line, output an odd integer m
 (1≤m≤n
), and in the second line, output m
 distinct integers p1,p2,p3,…,pm
 (1=p1<p2<p3<…<pm≤n
) — denoting the left borders of each subarray.
In detail, for a valid answer [p1,p2,…,pm]
:

b1=[ap1,ap1+1,…,ap2−1]
b2=[ap2,ap2+1,…,ap3−1]
…
bm=[apm,apm+1,…,an]
.
If there are multiple solutions, you can output any of them.

Example
InputCopy
4
1 1
3 2
3 3
15 8
OutputCopy
1
1
3
1 2 3
-1
5
1 4 7 10 13
Note
In the first test case, the given partition has m=1
 and b1=[1]
. It is obvious that median([median([1])])=median([1])=1
.

In the second test case, the given partition has m=3
 and:

b1=[1]
b2=[2]
b3=[3]
Therefore, median([median([1]),median([2]),median([3])])=median([1,2,3])=2
.

In the third test case, there is no valid partition for k=3
.

In the fourth test case, the given partition has m=5
 and:

b1=[1,2,3]
b2=[4,5,6]
b3=[7,8,9]
b4=[10,11,12]
b5=[13,14,15]
Therefore, median([median([1,2,3]),median([4,5,6]),median([7,8,9]),median([10,11,12]),median([13,14,15])])=median([2,5,8,11,14])=8
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
