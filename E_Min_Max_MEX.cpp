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

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Binary search to find the maximum possible MEX value
    // For each potential MEX value, we check if we can form at least k subarrays
    // where each subarray has a MEX value of at least 'mid'
    int l = 0, r = n + 1;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        // 'here' tracks if a number is present in the current subarray
        vector<bool> here(mid, false);
        // 'total' counts how many subarrays we can form with MEX >= mid
        int total = 0;
        // 'missing' tracks how many numbers below 'mid' are still missing
        // (for MEX to be 'mid', all numbers 0 to mid-1 must be present)
        int missing = mid;

        for (int i = 0; i < n; i++)
        {
            // If we find a number that's less than mid and we haven't seen it yet
            // in the current subarray, mark it as present and decrease missing count
            if (a[i] < mid && !here[a[i]])
            {
                here[a[i]] = true;
                missing--;
            }

            // When we've found all numbers from 0 to mid-1, we've completed a subarray
            // with MEX >= mid
            if (missing == 0)
            {
                total++;
                // Reset for the next subarray
                for (int j = 0; j < mid; j++)
                {
                    here[j] = false;
                }
                missing = mid;
            }
        }

        // If we can form at least k subarrays with MEX >= mid,
        // we can potentially increase mid further
        if (total >= k)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << l << nl;
}

/*
You are given an array a
 of length n
 and a number k
.

A subarray is defined as a sequence of one or more consecutive elements of the array. You need to split the array a
 into k
 non-overlapping subarrays b1,b2,…,bk
 such that the union of these subarrays equals the entire array. Additionally, you need to maximize the value of x
, which is equal to the minimum MEX(bi)
, for i∈[1..k]
.

MEX(v)
 denotes the smallest non-negative integer that is not present in the array v
.

Input
The first line contains an integer t
 (1≤t≤104)
  — the number of test cases.

The first line of each test case contains two integers n
, k
 (1≤k≤n≤2⋅105)
  — the length of the array and the number of segments to split the array into.

The second line of each test case contains n
 integers ai
 (0≤ai≤109)
  — the elements of the array.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each query, output a single number  — the maximum value x
 such that there exists a partition of the array a
 into k
 subarrays where the minimum MEX equals x
.

Example
InputCopy
7
1 1
0
5 1
0 1 3 2 4
6 2
2 1 0 0 1 2
5 5
0 0 0 0 0
5 2
2 3 4 5 6
6 2
0 0 1 1 2 2
4 4
1 0 0 0
OutputCopy
1
5
3
1
0
1
0
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
