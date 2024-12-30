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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> freq(m, 0); // Count of each remainder

    // Count remainders
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i] % m]++;
    }

    int ans = 0;

    // Handle remainder 0
    if (freq[0] > 0)
        ans++;

    // Handle remainder m/2 (only if m is even)
    if (m % 2 == 0 && freq[m / 2] > 0)
        ans++;

    // Handle other pairs of remainders
    for (int i = 1; i <= m / 2; i++)
    {
        if (i != m - i)
        { // Avoid double-counting remainder m/2
            int f1 = freq[i];
            int f2 = freq[m - i];

            if (f1 > 0 || f2 > 0)
            {
                ans += 1; // At least one group is needed
                if (abs(f1 - f2) > 1)
                {
                    ans += abs(f1 - f2) - 1; // Add additional groups for the excess
                }
            }
        }
    }

    cout << ans << nl;
}

/*
You are given an array a1,a2,…,an
 consisting of n
 positive integers and a positive integer m
.

You should divide elements of this array into some arrays. You can order the elements in the new arrays as you want.

Let's call an array m
-divisible if for each two adjacent numbers in the array (two numbers on the positions i
 and i+1
 are called adjacent for each i
) their sum is divisible by m
. An array of one element is m
-divisible.

Find the smallest number of m
-divisible arrays that a1,a2,…,an
 is possible to divide into.

Input
The first line contains a single integer t
 (1≤t≤1000)
  — the number of test cases.

The first line of each test case contains two integers n
, m
 (1≤n≤105,1≤m≤105)
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109)
.

It is guaranteed that the sum of n
 and the sum of m
 over all test cases do not exceed 105
.

Output
For each test case print the answer to the problem.

Example
InputCopy
4
6 4
2 2 8 6 9 4
10 8
1 1 1 5 2 4 4 8 6 7
1 1
666
2 2
2 4
OutputCopy
3
6
1
1
Note
In the first test case we can divide the elements as follows:

[4,8]
. It is a 4
-divisible array because 4+8
 is divisible by 4
.
[2,6,2]
. It is a 4
-divisible array because 2+6
 and 6+2
 are divisible by 4
.
[9]
. It is a 4
-divisible array because it consists of one element.
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
