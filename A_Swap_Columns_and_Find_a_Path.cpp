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
    int n;
    cin >> n;
    vector<int> row1(n), row2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> row1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> row2[i];
    }

    ll total = 0;
    int bonus = -100000000000LL; // A very small number (safe because |a_i,j| <= 1e5)

    for (int i = 0; i < n; i++)
    {
        int a = row1[i], b = row2[i];
        total += max(a, b);
        bonus = max(bonus, min(a, b));
    }

    cout << total + bonus << "\n";
}
/*
There is a matrix consisting of 2
 rows and n
 columns. The rows are numbered from 1
 to 2
 from top to bottom; the columns are numbered from 1
 to n
 from left to right. Let's denote the cell on the intersection of the i
-th row and the j
-th column as (i,j)
. Each cell contains an integer; initially, the integer in the cell (i,j)
 is ai,j
.

You can perform the following operation any number of times (possibly zero):

choose two columns and swap them (i. e. choose two integers x
 and y
 such that 1≤x<y≤n
, then swap a1,x
 with a1,y
, and then swap a2,x
 with a2,y
).
After performing the operations, you have to choose a path from the cell (1,1)
 to the cell (2,n)
. For every cell (i,j)
 in the path except for the last, the next cell should be either (i+1,j)
 or (i,j+1)
. Obviously, the path cannot go outside the matrix.

The cost of the path is the sum of all integers in all (n+1)
 cells belonging to the path. You have to perform the operations and choose a path so that its cost is maximum possible.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5000
). The description of the test cases follows.

Each test case consists of three lines:

the first line contains one integer n
 (1≤n≤5000
) — the number of columns in the matrix;
the second line contains n
 integers a1,1,a1,2,…,a1,n
 (−105≤ai,j≤105
) — the first row of the matrix;
the third line contains n
 integers a2,1,a2,2,…,a2,n
 (−105≤ai,j≤105
) — the second row of the matrix.
It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, print one integer — the maximum cost of a path you can obtain.

Example
InputCopy
3
1
-10
5
3
1 2 3
10 -5 -3
4
2 8 5 3
1 10 3 4
OutputCopy
-5
16
29
Note
Here are the explanations of the first three test cases of the example. The left matrix is the matrix given in the input, the right one is the state of the matrix after several column swaps (possibly zero). The optimal path is highlighted in green.
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
