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
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
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
    string s;
    cin >> s;
    bool flag = false;

    // Try to find a '0' in the second half of the string (positions n/2 to n-1)
    // If found, we can select two substrings:
    // 1. From position 1 to i+1 (inclusive)
    // 2. From position 1 to i (inclusive)
    // Both substrings have length at least n/2 and are distinct.
    for (int i = n / 2; i < n; i++)
    {
        if (s[i] == '0')
        {
            flag = true;
            // Output: [1, i+1] and [1, i] (1-based indices)
            cout << "1 " << i + 1 << " 1 " << i << nl;
            break;
        }
    }
    if (!flag)
    {
        // If no '0' in the second half, try to find a '0' in the first half (positions n/2 down to 0)
        // If found, we can select:
        // 1. From position i+1 to n (inclusive)
        // 2. From position i+2 to n (inclusive)
        // Both substrings have length at least n/2 and are distinct.
        for (int i = n / 2; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                // Output: [i+1, n] and [i+2, n] (1-based indices)
                cout << i + 1 << sp << n << sp << i + 2 << sp << n << nl;
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        // If all characters are '1', just output two overlapping substrings:
        // 1. From 1 to n-1
        // 2. From 2 to n
        // Both have length n-1 >= n/2 and are distinct.
        cout << "1 " << n - 1 << " 2 " << n << nl;
}

/*
Somewhere in a parallel Middle-earth, when Saruman caught Frodo, he only found n
 rings. And the i
-th ring was either gold or silver. For convenience Saruman wrote down a binary string s
 of n
 characters, where the i
-th character was 0 if the i
-th ring was gold, and 1 if it was silver.

Saruman has a magic function f
, which takes a binary string and returns a number obtained by converting the string into a binary number and then converting the binary number into a decimal number. For example, f(001010)=10,f(111)=7,f(11011101)=221
.

Saruman, however, thinks that the order of the rings plays some important role. He wants to find 2
 pairs of integers (l1,r1),(l2,r2)
, such that:

1≤l1≤n
, 1≤r1≤n
, r1−l1+1≥⌊n2⌋
1≤l2≤n
, 1≤r2≤n
, r2−l2+1≥⌊n2⌋
Pairs (l1,r1)
 and (l2,r2)
 are distinct. That is, at least one of l1≠l2
 and r1≠r2
 must hold.
Let t
 be the substring s[l1:r1]
 of s
, and w
 be the substring s[l2:r2]
 of s
. Then there exists non-negative integer k
, such that f(t)=f(w)⋅k
.
Here substring s[l:r]
 denotes slsl+1…sr−1sr
, and ⌊x⌋
 denotes rounding the number down to the nearest integer.

Help Saruman solve this problem! It is guaranteed that under the constraints of the problem at least one solution exists.

Input
Each test contains multiple test cases.

The first line contains one positive integer t
 (1≤t≤103
), denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer n
 (2≤n≤2⋅104
) — length of the string.

The second line of each test case contains a non-empty binary string of length n
.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For every test case print four integers l1
, r1
, l2
, r2
, which denote the beginning of the first substring, the end of the first substring, the beginning of the second substring, and the end of the second substring, respectively.

If there are multiple solutions, print any.

Example
InputCopy
7
6
101111
9
111000111
8
10000000
5
11011
6
001111
3
101
30
100000000000000100000000000000
OutputCopy
3 6 1 3
1 9 4 9
5 8 1 4
1 5 3 5
1 6 2 4
1 2 2 3
1 15 16 30
Note
In the first testcase f(t)=f(1111)=15
, f(w)=f(101)=5
.

In the second testcase f(t)=f(111000111)=455
, f(w)=f(000111)=7
.

In the third testcase f(t)=f(0000)=0
, f(w)=f(1000)=8
.

In the fourth testcase f(t)=f(11011)=27
, f(w)=f(011)=3
.

In the fifth testcase f(t)=f(001111)=15
, f(w)=f(011)=3
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
