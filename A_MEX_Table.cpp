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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;

    if (n == 1 && m == 1)
    {
        cout << 2 << endl;
        return;
    }
    else
    {
        ans = max(n, m) + 1;
    }

    cout << ans << endl;
}

/*
One day, the schoolboy Mark misbehaved, so the teacher Sasha called him to the whiteboard.

Sasha gave Mark a table with n
 rows and m
 columns. His task is to arrange the numbers 0,1,…,n⋅m−1
 in the table (each number must be used exactly once) in such a way as to maximize the sum of MEX∗
 across all rows and columns. More formally, he needs to maximize
∑i=1nmex({ai,1,ai,2,…,ai,m})+∑j=1mmex({a1,j,a2,j,…,an,j}),
where ai,j
 is the number in the i
-th row and j
-th column.

Sasha is not interested in how Mark arranges the numbers, so he only asks him to state one number — the maximum sum of MEX across all rows and columns that can be achieved.

∗
The minimum excluded (MEX) of a collection of integers c1,c2,…,ck
 is defined as the smallest non-negative integer x
 which does not occur in the collection c
.

For example:

mex([2,2,1])=0
, since 0
 does not belong to the array.
mex([3,1,0,1])=2
, since 0
 and 1
 belong to the array, but 2
 does not.
mex([0,3,1,2])=4
, since 0
, 1
, 2
, and 3
 belong to the array, but 4
 does not.
Input
Each test contains multiple test cases. The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n,m≤109
) — the number of rows and columns in the table, respectively.

Output
For each test case, output the maximum possible sum of mex
 across all rows and columns.

Example
InputCopy
3
1 1
2 2
3 5
OutputCopy
2
3
6
Note
In the first test case, the only element is 0
, and the sum of the mex
 of the numbers in the first row and the mex
 of the numbers in the first column is mex({0})+mex({0})=1+1=2
.

In the second test case, the optimal table may look as follows:

3
0
2
1
Then ∑i=1nmex({ai,1,ai,2,…,ai,m})+∑j=1mmex({a1,j,a2,j,…,an,j})=mex({3,0})+mex({2,1})
 +mex({3,2})+mex({0,1})=1+0+0+2=3
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
