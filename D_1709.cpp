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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<pair<int, int>> ops;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j + 1 < n; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ops.push_back({1, j + 1});
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j + 1 < n; ++j)
        {
            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
                ops.push_back({2, j + 1});
            }
        }
    }

    cout << ops.size() << nl;
    for (auto &op : ops)
    {
        cout << op.first << sp << op.second << nl;
    }
}

/*
You are given two arrays of integers a1,a2,…,an
 and b1,b2,…,bn
. It is guaranteed that each integer from 1
 to 2⋅n
 appears in exactly one of the arrays.

You need to perform a certain number of operations (possibly zero) so that both of the following conditions are satisfied:

For each 1≤i<n
, it holds that ai<ai+1
 and bi<bi+1
.
For each 1≤i≤n
, it holds that ai<bi
.
During each operation, you can perform exactly one of the following three actions:

Choose an index 1≤i<n
 and swap the values ai
 and ai+1
.
Choose an index 1≤i<n
 and swap the values bi
 and bi+1
.
Choose an index 1≤i≤n
 and swap the values ai
 and bi
.
You do not need to minimize the number of operations, but the total number must not exceed 1709
. Find any sequence of operations that satisfies both conditions.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤40
) — the length of the arrays a
 and b
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤2⋅n
).

The third line of each test case contains n
 integers b1,b2,…,bn
 (1≤bi≤2⋅n
).

It is guaranteed that each integer from 1
 to 2⋅n
 appears either in array a
 or in array b
.

Output
For each test case, output the sequence of operations.

In the first line for each test case, output the number of operations k
. Note that 0≤k≤1709
.

In the following k
 lines for each test case, output the operations themselves:

If you want to swap the values ai
 and ai+1
, output two integers 1
 and i
. Note that 1≤i<n
.
If you want to swap the values bi
 and bi+1
, output two integers 2
 and i
. Note that 1≤i<n
.
If you want to swap the values ai
 and bi
, output two integers 3
 and i
. Note that 1≤i≤n
.
It can be shown that under the given constraints, a solution always exists.

Example
InputCopy
6
1
1
2
1
2
1
2
1 3
4 2
2
1 4
3 2
3
6 5 4
3 2 1
3
5 3 4
2 6 1
OutputCopy
0
1
3 1
1
2 1
1
3 2
9
3 1
3 2
3 3
1 1
2 1
2 2
1 2
1 1
2 1
6
2 2
1 1
1 2
2 1
3 1
3 2
Note
In the first test case, a1<b1
, so no operations need to be applied.

In the second test case, a1>b1
. After applying the operation, these values will be swapped.

In the third test case, after applying the operation, a=[1,3]
 and b=[2,4]
.

In the fourth test case, after applying the operation, a=[1,2]
 and b=[3,4]
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
