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
    // Arrays to store input, output, and intermediate values
    vector<ll> a(n), b(n), d1(n), d2(n);
    vector<ll> k(n); // k[i] stores the maximum valid b value for position i

    // Read input arrays
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    // Calculate k array from right to left
    // k[i] represents the maximum value from b that a[i] can be paired with
    k[n - 1] = b[n - 1]; // Last element can always be paired with b[n-1]
    for (int i = n - 2; i > -1; --i)
    {
        // If a[i+1] <= b[i], we can use the same k value as i+1
        // This is because a[i+1] already provides a constraint
        if (a[i + 1] <= b[i])
        {
            k[i] = k[i + 1];
        }
        // Otherwise, the maximum we can use is b[i] itself
        else
        {
            k[i] = b[i];
        }
    }

    // Calculate minimum differences (d1)
    // For each a[i], find the smallest b[j] ≥ a[i]
    for (int i = 0; i < n; ++i)
    {
        // lower_bound finds the first element >= a[i]
        d1[i] = *(lower_bound(b.begin(), b.end(), a[i])) - a[i];
    }

    // Calculate maximum differences (d2)
    // Using the precomputed k array that respects the ordering constraints
    for (int i = 0; i < n - 1; ++i)
    {
        d2[i] = k[i] - a[i];
    }
    d2[n - 1] = k[n - 1] - a[n - 1]; // Last element's maximum difference

    // Output the results
    for (int i = 0; i < n; ++i)
        cout << d1[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
        cout << d2[i] << ' ';
    cout << '\n';
}

/*
You are given an array a1,a2,…,an
, which is sorted in non-descending order. You decided to perform the following steps to create array b1,b2,…,bn
:

Create an array d
 consisting of n
 arbitrary non-negative integers.
Set bi=ai+di
 for each bi
.
Sort the array b
 in non-descending order.
You are given the resulting array b
. For each index i
, calculate what is the minimum and maximum possible value of di
 you can choose in order to get the given array b
.

Note that the minimum (maximum) di
-s are independent of each other, i. e. they can be obtained from different possible arrays d
.

Input
The first line contains the single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the length of arrays a
, b
 and d
.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤109
; ai≤ai+1
) — the array a
 in non-descending order.

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤109
; bi≤bi+1
) — the array b
 in non-descending order.

Additional constraints on the input:

there is at least one way to obtain the array b
 from the a
by choosing an array d
 consisting of non-negative integers;
the sum of n
 doesn't exceed 2⋅105
.
Output
For each test case, print two lines. In the first line, print n
 integers dmin1,dmin2,…,dminn
, where dmini
 is the minimum possible value you can add to ai
.

Secondly, print n
 integers dmax1,dmax2,…,dmaxn
, where dmaxi
 is the maximum possible value you can add to ai
.

All dmini
 and dmaxi
 values are independent of each other. In other words, for each i
, dmini
 is just the minimum value among all possible values of di
.

Example
InputCopy
4
3
2 3 5
7 11 13
1
1000
5000
4
1 2 3 4
1 2 3 4
4
10 20 30 40
22 33 33 55
OutputCopy
5 4 2
11 10 8
4000
4000
0 0 0 0
0 0 0 0
12 2 3 15
23 13 3 15
Note
In the first test case, in order to get dmin1=5
, we can choose, for example, d=[5,10,6]
. Then b
 =
 [2+5,3+10,5+6]
 =
 [7,13,11]
 =
 [7,11,13]
.

For dmin2=4
, we can choose d
 =
 [9,4,8]
. Then b
 =
 [2+9,3+4,5+8]
 =
 [11,7,13]
 =
 [7,11,13]
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
