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

    // Read positions of air conditioners (1-based indexing)
    vi a(k), t(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    // Read temperatures of air conditioners
    for (int i = 0; i < k; i++)
    {
        cin >> t[i];
    }

    // Initialize all cells with a very large value (infinity)
    // This will be updated to the minimum possible temperature for each cell
    vector<ll> res(n, 1e18);

    // Set the temperature at the positions where air conditioners are placed
    // a[i] is 1-based, so subtract 1 for 0-based indexing
    for (int i = 0; i < k; i++)
    {
        res[a[i] - 1] = t[i];
    }

    // Left to right sweep:
    // For each cell, update its temperature to be at most 1 more than the previous cell
    // This simulates the effect of the closest air conditioner to the left
    for (int i = 1; i < n; i++)
    {
        res[i] = min(res[i], res[i - 1] + 1);
    }
    // Right to left sweep:
    // For each cell, update its temperature to be at most 1 more than the next cell
    // This simulates the effect of the closest air conditioner to the right
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = min(res[i], res[i + 1] + 1);
    }

    // Output the minimum temperature for each cell
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << sp;
    }
    cout << nl;
}

/*
On a strip of land of length n
 there are k
 air conditioners: the i
-th air conditioner is placed in cell ai
 (1≤ai≤n
). Two or more air conditioners cannot be placed in the same cell (i.e. all ai
 are distinct).

Each air conditioner is characterized by one parameter: temperature. The i
-th air conditioner is set to the temperature ti
.

Example of strip of length n=6
, where k=2
, a=[2,5]
 and t=[14,16]
.
For each cell i
 (1≤i≤n
) find it's temperature, that can be calculated by the formula
min1≤j≤k(tj+|aj−i|),

where |aj−i|
 denotes absolute value of the difference aj−i
.

In other words, the temperature in cell i
 is equal to the minimum among the temperatures of air conditioners, increased by the distance from it to the cell i
.

Let's look at an example. Consider that n=6,k=2
, the first air conditioner is placed in cell a1=2
 and is set to the temperature t1=14
 and the second air conditioner is placed in cell a2=5
 and is set to the temperature t2=16
. In that case temperatures in cells are:

temperature in cell 1
 is: min(14+|2−1|,16+|5−1|)=min(14+1,16+4)=min(15,20)=15
;
temperature in cell 2
 is: min(14+|2−2|,16+|5−2|)=min(14+0,16+3)=min(14,19)=14
;
temperature in cell 3
 is: min(14+|2−3|,16+|5−3|)=min(14+1,16+2)=min(15,18)=15
;
temperature in cell 4
 is: min(14+|2−4|,16+|5−4|)=min(14+2,16+1)=min(16,17)=16
;
temperature in cell 5
 is: min(14+|2−5|,16+|5−5|)=min(14+3,16+0)=min(17,16)=16
;
temperature in cell 6
 is: min(14+|2−6|,16+|5−6|)=min(14+4,16+1)=min(18,17)=17
.
For each cell from 1
 to n
 find the temperature in it.

Input
The first line contains one integer q
 (1≤q≤104
) — the number of test cases in the input. Then test cases follow. Before each test case, there is an empty line.

Each test case contains three lines. The first line contains two integers n
 (1≤n≤3⋅105
) and k
 (1≤k≤n
) — the length of the strip of land and the number of air conditioners respectively.

The second line contains k
 integers a1,a2,…,ak
 (1≤ai≤n
) — positions of air conditioners on the strip of land.

The third line contains k
 integers t1,t2,…,tk
 (1≤ti≤109
) — temperatures of air conditioners.

It is guaranteed that the sum of n
 over all test cases does not exceed 3⋅105
.

Output
For each test case output n
 integers separated by space: temperatures of air in cells.

Example
InputCopy
5

6 2
2 5
14 16

10 1
7
30

5 5
3 1 4 2 5
3 1 4 2 5

7 1
1
1000000000

6 3
6 1 3
5 5 5
OutputCopy
15 14 15 16 16 17
36 35 34 33 32 31 30 31 32 33
1 2 3 4 5
1000000000 1000000001 1000000002 1000000003 1000000004 1000000005 1000000006
5 6 5 6 6 5


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
