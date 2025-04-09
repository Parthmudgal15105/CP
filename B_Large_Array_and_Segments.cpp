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
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
////////////////////////////////////////////////////////// SQR ROOT

ll sqrt(ll x)
{
    ll s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        ll m = (s + e) / 2;
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
    // Read input: n = size of array, k = number of repetitions, x = target sum.
    int n, k, x;
    cin >> n >> k >> x;

    // Read array a and initialize a suffix sum array ss.
    vector<int> a(n), ss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // ...existing code...
    }

    // Compute suffix sums: ss[i] stores sum from a[i] to a[n-1].
    for (int i = n - 1; i >= 0; i--)
    {
        ss[i] = a[i];
        if (i + 1 < n)
            ss[i] += ss[i + 1];
    }

    // Total sum of the array (sum for one block) is stored in ss[0]
    int ans = 0;
    int sum = ss[0];

    // Iterate over each repeated block in the array b.
    for (int i = 1; i <= k; i++)
    {
        // If the sum of all remaining blocks is enough to meet or exceed x,
        // then every starting position in the current block is valid.
        if (sum * (k - i) >= x)
        {
            ans += n;
            continue;
        }
        // If even the current block plus all remaining blocks can't reach x,
        // then no starting position in this block will work.
        if (sum * (k - i + 1) < x)
        {
            continue;
        }

        // Otherwise, check each possible starting position in the current block.
        for (int j = 0; j < n; j++)
        {
            // If the sum of the remaining full blocks plus the suffix starting at j meets x,
            // count that starting position.
            if (sum * (k - i) + ss[j] >= x)
            {
                ans++;
            }
        }
    }

    // Output the total count of valid starting positions.
    cout << ans << '\n';
}
/*
There is an array a
 consisting of n
 positive integers, and a positive integer k
. An array b
 is created from array a
 according to the following rules:

b
 contains n⋅k
 numbers;
the first n
 numbers of array b
 are the same as the numbers of array a
, that is, bi=ai
 for i≤n
;
for any i>n
, it holds that bi=bi−n
.
For example, if a=[2,3,1,4]
 and k=3
, then b=[2,3,1,4,2,3,1,4,2,3,1,4]
.

Given a number x
, it is required to count the number of such positions l
 (1≤l≤n⋅k
), for which there exists a position r≥l
, such that the sum of the elements of array b
 on the segment [l,r]
 is at least x
 (in other words, bl+bl+1+⋯+br≥x
).

Input
Each test consists of several test cases. The first line contains one integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers n
, k
, x
 (1≤n,k≤105
; 1≤x≤1018
).

The second line of each test case contains n
 integers ai
 (1≤ai≤108
).

Additional constraints on the input:

the sum of n
 across all test cases does not exceed 2⋅105
;
the sum of k
 across all test cases does not exceed 2⋅105
.
Output
For each test case, output one integer — the number of suitable positions l
 in the array b
.

Example
InputCopy
7
5 3 10
3 4 2 1 5
15 97623 1300111
105 95 108 111 118 101 95 118 97 108 111 114 97 110 116
1 100000 1234567891011
1
1 1 1
1
1 1 1
2
2 1 2
1 1
2 1 5
2 1
OutputCopy
12
1452188
0
1
1
1
0
Note
In the first test case, the array b
 looks like this:

[3,4,2,1,5,3,4,2,1,5,3,4,2,1,5]

There are 12
 positions l
 for which there exists a suitable position r
. Here are some (not all) of them:

l=1
, for which there is a position r=6
, the sum over the segment [1,6]
 equals 18
;
l=2
, for which there is a position r=5
, the sum over the segment [2,5]
 equals 12
;
l=6
, for which there is a position r=9
, the sum over the segment [6,9]
 equals 10
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
