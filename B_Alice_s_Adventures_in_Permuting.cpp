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

/*----------------------------------------------------------------------------*/
void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;

    if (b == 0)
    {
        if (c >= n)
        {
            cout << n << '\n';
        }
        else if (c == n - 1 || c == n - 2)
        {
            cout << n - 1 << '\n';
        }
        else
        {
            cout << "-1\n";
        }
        return;
    }

    if (c > n - 1)
    {
        cout << n << '\n';
        return;
    }

    ll correct = (n - c + b - 1) / b;
    if (correct > n)
        correct = n;

       cout << n - correct << '\n';
}

/*
Alice mixed up the words transmutation and permutation! She has an array a
 specified via three integers n
, b
, c
: the array a
 has length n
 and is given via ai=b⋅(i−1)+c
 for 1≤i≤n
. For example, if n=3
, b=2
, and c=1
, then a=[2⋅0+1,2⋅1+1,2⋅2+1]=[1,3,5]
.

Now, Alice really enjoys permutations of [0,…,n−1]
∗
 and would like to transform a
 into a permutation. In one operation, Alice replaces the maximum element of a
 with the MEX
†
 of a
. If there are multiple maximum elements in a
, Alice chooses the leftmost one to replace.

Can you help Alice figure out how many operations she has to do for a
 to become a permutation for the first time? If it is impossible, you should report it.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 0
 to n−1
 in arbitrary order. Please note, this is slightly different from the usual definition of a permutation. For example, [1,2,0,4,3]
 is a permutation, but [0,1,1]
 is not a permutation (1
 appears twice in the array), and [0,2,3]
 is also not a permutation (n=3
 but there is 3
 in the array).

†
The MEX
 of an array is the smallest non-negative integer that does not belong to the array. For example, the MEX
 of [0,3,1,3]
 is 2
 and the MEX
 of [5]
 is 0
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤105
). The description of the test cases follows.

The only line of each test case contains three integers n
, b
, c
 (1≤n≤1018
; 0≤b
, c≤1018
) — the parameters of the array.

Output
For each test case, if the array can never become a permutation, output −1
. Otherwise, output the minimum number of operations for the array to become a permutation.

Example
InputCopy
7
10 1 0
1 2 3
100 2 1
3 0 1
3 0 0
1000000000000000000 0 0
1000000000000000000 1000000000000000000 1000000000000000000
OutputCopy
0
1
50
2
-1
-1
1000000000000000000
Note
In the first test case, the array is already [0,1,…,9]
, so no operations are required.

In the third test case, the starting array is [1,3,5,…,199]
. After the first operation, the 199
 gets transformed into a 0
. In the second operation, the 197
 gets transformed into a 2
. If we continue this, it will take exactly 50
 operations to get the array [0,1,2,3,…,99]
.

In the fourth test case, two operations are needed: [1,1,1]→[0,1,1]→[0,2,1]
.

In the fifth test case, the process is [0,0,0]→[1,0,0]→[2,0,0]→[1,0,0]→[2,0,0]
. This process repeats forever, so the array is never a permutation and the answer is −1
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
