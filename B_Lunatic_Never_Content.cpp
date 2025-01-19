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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int result = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            int diff = abs(a[i] - a[n - 1 - i]);
            result = gcd(result, diff);
        }
    }

    cout << result << endl;
}

/*
You have an array a
 of n
 non-negative integers. Let's define f(a,x)=[a1modx,a2modx,…,anmodx]
 for some positive integer x
. Find the biggest x
, such that f(a,x)
 is a palindrome.

Here, amodx
 is the remainder of the integer division of a
 by x
.

An array is a palindrome if it reads the same backward as forward. More formally, an array a
 of length n
 is a palindrome if for every i
 (1≤i≤n
) ai=an−i+1
.

Input
The first line contains a single integer t
 (1≤t≤105
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤105
).

The second line of each test case contains n
 integers ai
 (0≤ai≤109
).

It's guaranteed that the sum of all n
 does not exceed 105
.

Output
For each test case output the biggest x
, such that f(a,x)
 is a palindrome. If x
 can be infinitely large, output 0
 instead.

Example
InputCopy
4
2
1 2
8
3 0 1 2 0 3 2 1
1
0
3
100 1 1000000000
OutputCopy
1
2
0
999999900
Note
In the first example, f(a,x=1)=[0,0]
 which is a palindrome.

In the second example, f(a,x=2)=[1,0,1,0,0,1,0,1]
 which is a palindrome.

It can be proven that in the first two examples, no larger x
 satisfies the condition.

In the third example, f(a,x)=[0]
 for any x
, so we can choose it infinitely large, so the answer is 0
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
