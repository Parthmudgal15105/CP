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
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    for (auto &x : a)
        cout << x << " ";
    cout << nl;
}

/*
You are given an array a1,a2,…,an
. Array is good if for each pair of indexes i<j
 the condition j−aj≠i−ai
 holds. Can you shuffle this array so that it becomes good? To shuffle an array means to reorder its elements arbitrarily (leaving the initial order is also an option).

For example, if a=[1,1,3,5]
, then shuffled arrays [1,3,5,1]
, [3,5,1,1]
 and [5,3,1,1]
 are good, but shuffled arrays [3,1,5,1]
, [1,1,3,5]
 and [1,1,5,3]
 aren't.

It's guaranteed that it's always possible to shuffle an array to meet this condition.

Input
The first line contains one integer t
 (1≤t≤100
) — the number of test cases.

The first line of each test case contains one integer n
 (1≤n≤100
) — the length of array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤100
).

Output
For each test case print the shuffled version of the array a
 which is good.

Example
InputCopy
3
1
7
4
1 1 3 5
6
3 2 1 5 6 4
OutputCopy
7
1 5 1 3
2 4 6 1 3 5


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
