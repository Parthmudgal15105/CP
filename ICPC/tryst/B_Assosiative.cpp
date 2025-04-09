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
Soumil is really fond of permutations and he has recently become aware of the concept of prefix MEX
 arrays. A permutation P
 of 1,...,n
 has its prefix MEX
 array A
 defined as

A[i]=MEX(P[1:i])
for 1≤i≤n
, where P[1:i]
 denotes the elements P[1],...P[i]
 and MEX
 of an array is defined as the smallest positive integer not present in it. More formally, for an array B
,

MEX(B)=min{x≥1 | x∉B}
You are given an array A
 of length n
, where 1≤A[j]≤n+1
. Your task is to determine how many permutations P
 of 1,...,n
 exist such that their prefix MEX array is exactly A
. Since the answer can be large, output it modulo 109+7
.

Input
The first line of input contains a number t
 (1≤t≤5⋅103)
 — the number of test cases.

In the first line of each test case, there is a single integer n
 (1≤n≤105)
 — the length of the array A
.

In the second line of each test case, there are n
 space separated integers A[j]
 −
 (1≤A[j]≤n+1)
 — the elements of the array A
.

It is guaranteed that the sum of n
 across all test cases does not exceed 106
.

Output
For each test case, output the number of permutations (modulo 109+7
) of length n
 which have the given array A
 as their prefix MEX
 array.

Example
InputCopy
2
2
1 3
4
1 2 2 5
OutputCopy
1
2
Note
In the first test case, n=2
. The only possible permutations are [1,2]
 and [2,1]
 which have [2,3]
 and [1,3]
 as their prefix MEX
 arrays respectively. So, for A=[1,3]
, answer is 1
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
