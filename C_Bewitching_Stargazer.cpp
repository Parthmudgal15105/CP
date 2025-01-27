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
// Function to compute the lucky value and count of operations
pair<ll, ll> computeLuckyValue(ll n, ll k)
{
    if (n < k)
    {
        return {0, 0};
    }
    auto child = computeLuckyValue(n / 2, k);
    ll currentSum = child.first;
    ll multiplier = child.second;
    if (n & 1)
    {
        ll middle = (n + 1) / 2;
        ll totalSum = middle + currentSum * 2 + multiplier * middle;
        ll totalCount = 2 * multiplier + 1;
        return {totalSum, totalCount};
    }
    else
    {
        ll middle = n / 2;
        ll totalSum = currentSum * 2 + multiplier * middle;
        ll totalCount = multiplier * 2;
        return {totalSum, totalCount};
    }
}

// Function to handle each test case
void solve()
{
    ll n, k;
    cin >> n >> k;
    cout << computeLuckyValue(n, k).first << nl;
}

/*
Iris looked at the stars and a beautiful problem emerged in her mind. She is inviting you to solve it so that a meteor shower is believed to form.

There are n
 stars in the sky, arranged in a row. Iris has a telescope, which she uses to look at the stars.

Initially, Iris observes stars in the segment [1,n]
, and she has a lucky value of 0
. Iris wants to look for the star in the middle position for each segment [l,r]
 that she observes. So the following recursive procedure is used:

First, she will calculate m=⌊l+r2⌋
.
If the length of the segment (i.e. r−l+1
) is even, Iris will divide it into two equally long segments [l,m]
 and [m+1,r]
 for further observation.
Otherwise, Iris will aim the telescope at star m
, and her lucky value will increase by m
; subsequently, if l≠r
, Iris will continue to observe two segments [l,m−1]
 and [m+1,r]
.
Iris is a bit lazy. She defines her laziness by an integer k
: as the observation progresses, she will not continue to observe any segment [l,r]
 with a length strictly less than k
. In this case, please predict her final lucky value.

Input
Each test contains multiple test cases. The first line of input contains a single integer t
 (1≤t≤105
) — the number of test cases. The description of test cases follows.

The only line of each test case contains two integers n
 and k
 (1≤k≤n≤2⋅109
).

Output
For each test case, output a single integer — the final lucky value.

Example
InputCopy
6
7 2
11 3
55 13
5801 6
8919 64
8765432 1
OutputCopy
12
18
196
1975581
958900
38416403456028
Note
In the first test case, at the beginning, Iris observes [1,7]
. Since [1,7]
 has an odd length, she aims at star 4
 and therefore increases her lucky value by 4
. Then it is split into 2
 new segments: [1,3]
 and [5,7]
. The segment [1,3]
 again has an odd length, so Iris aims at star 2
 and increases her lucky value by 2
. Then it is split into 2
 new segments: [1,1]
 and [3,3]
, both having a length less than 2
, so no further observation is conducted. For range [5,7]
, the progress is similar and the lucky value eventually increases by 6
. Therefore, the final lucky value is 4+2+6=12
.

In the last test case, Iris finally observes all the stars and the final lucky value is 1+2+⋯+8765432=38416403456028
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
