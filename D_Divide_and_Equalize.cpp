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
    // Read input size
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Map to store prime factors and their frequencies
    // Key: prime factor, Value: count of occurrences
    map<ll, ll> freq;

    // For each number in array
    for (auto &val : a)
    {
        ll x = val;
        // Try all possible factors from 2 to sqrt(x)
        for (ll f = 2; f * f <= x; f++)
        {
            // While f divides x, keep dividing and counting
            while (x % f == 0)
            {
                freq[f]++; // Increment frequency of prime factor f
                x /= f;
            }
        }
        // If remaining x > 1, it's a prime factor itself
        if (x > 1)
            freq[x]++;
    }

    // For all numbers to become equal, each prime factor's frequency
    // must be divisible by n (array size)
    for (auto &p : freq)
    {
        if (p.second % n != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

/*
You are given an array a
 consisting of n
 positive integers. You can perform the following operation on it:

Choose a pair of elements ai
 and aj
 (1≤i,j≤n
 and i≠j
);
Choose one of the divisors of the integer ai
, i.e., an integer x
 such that aimodx=0
;
Replace ai
 with aix
 and aj
 with aj⋅x
.
Determine whether it is possible to make all elements in the array the same by applying the operation a certain number of times (possibly zero).
For example, let's consider the array a
 = [100,2,50,10,1
] with 5
 elements. Perform two operations on it:

Choose a3=50
 and a2=2
, x=5
. Replace a3
 with a3x=505=10
, and a2
 with a2⋅x=2⋅5=10
. The resulting array is a
 = [100,10,10,10,1
];
Choose a1=100
 and a5=1
, x=10
. Replace a1
 with a1x=10010=10
, and a5
 with a5⋅x=1⋅10=10
. The resulting array is a
 = [10,10,10,10,10
].
After performing these operations, all elements in the array a
 become equal to 10
.
Input
The first line of the input contains a single integer t
 (1≤t≤2000
) — the number of test cases.

Then follows the description of each test case.

The first line of each test case contains a single integer n
 (1≤n≤104
) — the number of elements in the array a
.

The second line of each test case contains exactly n
 integers ai
 (1≤ai≤106
) — the elements of the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 104
.

Output
For each test case, output a single line:

"YES" if it is possible to make all elements in the array equal by applying the operation a certain (possibly zero) number of times;
"NO" otherwise.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer).

Example
InputCopy
7
5
100 2 50 10 1
3
1 1 1
4
8 2 4 2
4
30 50 27 20
2
75 40
2
4 4
3
2 3 1
OutputCopy
YES
YES
NO
YES
NO
YES
NO
Note
The first test case is explained in the problem statement.
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
