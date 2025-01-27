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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    cout << max(evenCount, oddCount) << nl;
}

/*
29   26  30  25
There are
N
N frogs, numbered from
1
1 to
N
N. There are also
2
N
2N buckets arranged in a straight line, numbered from
1
1 to
2
N
2N.

Let
A
i
A
i
​
  denote the index of the bucket containing frog
i
i. You are given the initial values of
A
i
A
i
​
 .

Every second, the following happens:

If all frogs are in the same bucket already, nothing happens.
Otherwise, each frog will jump one step towards whichever is the smallest frog that's not in the same bucket as it.
Formally, consider frog
i
i, and let
j
j be the smallest index such that
A
i
≠
A
j
A
i
​
 =A
j
​
 .
If
A
j
<
A
i
A
j
​
 <A
i
​
 , frog
i
i will jump one bucket to the left and
A
i
A
i
​
  will decrease by
1
1.
Otherwise,
A
j
>
A
i
A
j
​
 >A
i
​
 , and frog
i
i will jump one bucket to the right, so
A
i
A
i
​
  will increase by
1
1.
Note that all movements are performed simultaneously. See the examples below for further clarification.

Your task is to determine the largest number of frogs in a single bucket at any point of time during this process.

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer
N
N — the number of frogs.
The second line contains
N
N spaced integers
A
1
,
A
2
,
…
,
A
N
,
A
1
​
 ,A
2
​
 ,…,A
N
​
 ,.
Output Format
For each test case, output on a new line the answer: the largest number of frogs in a single bucket at any point of time.

Constraints
1
≤
T
≤
1
0
5
1≤T≤10
5

1
≤
N
≤
2
⋅
1
0
5
1≤N≤2⋅10
5

1
≤
A
i
≤
2
N
1≤A
i
​
 ≤2N
The sum of
N
N over all test cases won't exceed
2
⋅
1
0
5
2⋅10
5
 .
Sample 1:
Input
Output
3
3
2 1 3
2
2 1
16
2 29 6 13 26 9 30 1 25 22 5 14 10 17 18 21
2
1
8
Explanation:
Test case
1
1: The process is as follows:

Initially,
A
=
[
2
,
1
,
3
]
A=[2,1,3].
In the first second,
Frog
1
1 will jump towards frog
2
2 which is to its left.
A
1
A
1
​
  will decrease by
1
1.
Frog
2
2 will jump towards frog
1
1 which is to its right.
A
2
A
2
​
  will increase by
1
1.
Frog
3
3 will jump towards frog
1
1 which is to its left.
A
3
A
3
​
  will decrease by
1
1.
Now, the positions are
A
=
[
1
,
2
,
2
]
A=[1,2,2].
In the next second, frogs
2
2 and
3
3 will jump towards
1
1, while frog
1
1 will jump towards
2
2.
The positions will be
[
2
,
1
,
1
]
[2,1,1].
In the third second, again frogs
2
2 and
3
3 will jump towards
1
1, while frog
1
1 will jump towards
2
2.
The positions will be
[
1
,
2
,
2
]
[1,2,2].
This will continue infinitely: the frogs will alternate between buckets
1
1 and
2
2.

The maximum number of frogs in a bucket at any time is
2
2, which is frogs
2
2 and
3
3.

**Test case
2
2: Frogs
1
1 and
2
2 will never be in the same bucket, so the answer is
1
1.
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
