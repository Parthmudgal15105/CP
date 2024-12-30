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
    ll n;
    char ch;
    string s;
    cin >> n >> ch >> s;
    bool ok = true;
    ll in = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
            in = i;
        if (s[i] != ch)
            ok = false;
    }
    if (ok)
        cout << "0\n";
    else if (in == -1)
    {
        cout << "2\n"
             << n - 1 << " " << n << "\n";
    }
    else if (in == n - 1)
    {
        cout << "1\n"
             << in + 1 << "\n";
    }
    else if (in >= n / 2)
    {

        cout << "1\n"
             << in + 1 << "\n";
    }
    else
    {
        cout << "2\n"
             << n - 1 << " " << n << "\n";
    }
}

/*
Theofanis has a string s1s2…sn
 and a character c
. He wants to make all characters of the string equal to c
 using the minimum number of operations.

In one operation he can choose a number x
 (1≤x≤n
) and for every position i
, where i
 is not divisible by x
, replace si
 with c
.

Find the minimum number of operations required to make all the characters equal to c
 and the x
-s that he should use in his operations.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains the integer n
 (3≤n≤3⋅105
) and a lowercase Latin letter c
 — the length of the string s
 and the character the resulting string should consist of.

The second line of each test case contains a string s
 of lowercase Latin letters — the initial string.

It is guaranteed that the sum of n
 over all test cases does not exceed 3⋅105
.

Output
For each test case, firstly print one integer m
 — the minimum number of operations required to make all the characters equal to c
.

Next, print m
 integers x1,x2,…,xm
 (1≤xj≤n
) — the x
-s that should be used in the order they are given.

It can be proved that under given constraints, an answer always exists. If there are multiple answers, print any.

Example
InputCopy
3
4 a
aaaa
4 a
baaa
4 b
bzyx
OutputCopy
0
1
2
2
2 3
Note
Let's describe what happens in the third test case:

x1=2
: we choose all positions that are not divisible by 2
 and replace them, i. e. bzyx →
 bzbx;
x2=3
: we choose all positions that are not divisible by 3
 and replace them, i. e. bzbx →
 bbbb.
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
