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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    int maxi = 0;

    // Read the matrix and find the maximum value in the matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            maxi = max(maxi, a[i][j]);
        }

    // Count how many times the maximum value appears in each row and column
    map<int, int> rowcount, colcount;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == maxi)
            {
                rowcount[i]++; // row i has a maximum at column j
                colcount[j]++; // column j has a maximum at row i
            }

    // Count the total number of maximum elements in the matrix
    int totalmaxi = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == maxi)
                totalmaxi++;

    bool reduce = false;
    // Try all combinations of rows and columns that contain the maximum value
    for (auto &r : rowcount)
    {
        for (auto &c : colcount)
        {
            // Check if the cell at (r.first, c.first) is a maximum (to avoid double counting)
            int overlap = 0;
            if (a[r.first][c.first] == maxi)
                overlap = 1;
            // If all maximums are covered by this row and column, we can reduce the answer by 1
            if (r.second + c.second - overlap == totalmaxi)
            {
                reduce = true;
                break;
            }
        }
        if (reduce)
            break;
    }

    // Output the minimal possible maximum value after the operation
    if (reduce)
        cout << maxi - 1 << nl;
    else
        cout << maxi << nl;
}

/*
You are given a matrix of integers with n
 rows and m
 columns. The cell at the intersection of the i
-th row and the j
-th column contains the number aij
.

You can perform the following operation exactly once:

Choose two numbers 1≤r≤n
 and 1≤c≤m
.
For all cells (i,j)
 in the matrix such that i=r
 or j=c
, decrease aij
 by one.
You need to find the minimal possible maximum value in the matrix a
 after performing exactly one such operation.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (1≤n⋅m≤105
) — the number of rows and columns in the matrix.

The next n
 lines of each test case describe the matrix a
. The i
-th line contains m
 integers ai1,ai2,…,aim
 (1≤aij≤100
) — the elements in the i
-th row of the matrix.

It is guaranteed that the sum of n⋅m
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum maximum value in the matrix a
 after performing exactly one operation.

Example
InputCopy
10
1 1
1
1 2
1 2
2 1
2
1
2 2
4 2
3 4
3 4
1 2 3 2
3 2 1 3
2 1 3 2
4 3
1 5 1
3 1 3
5 5 5
3 5 1
4 4
1 3 3 2
2 3 2 2
1 2 2 1
3 3 2 3
2 2
2 2
1 2
3 2
1 2
2 1
1 2
3 3
2 1 1
1 2 1
1 1 2
OutputCopy
0
1
1
3
2
4
3
1
1
2
Note
In the first three test cases, you can choose r=1
 and c=1
.

In the fourth test case, you can choose r=1
 and c=2
.


In the fifth test case, you can choose r=2
 and c=3
.


In the sixth test case, you can choose r=3
 and c=2
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
