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
    string s;
    cin >> s;
    int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');

    for (int a = 0; a <= 99; a++)
    {
        for (int b = 0; b <= 99; b++)
        {
            if ((a + b) * (a + b) == year)
            {
                cout << a << sp << b << nl;
                return;
            }
        }
    }

    cout << -1 << nl;
}

/*
One can notice the following remarkable mathematical fact: the number 2025
 can be represented as (20+25)2
.

You are given a year represented by a string s
, consisting of exactly 4
 characters. Thus, leading zeros are allowed in the year representation. For example, "0001", "0185", "1375" are valid year representations. You need to express it in the form (a+b)2
, where a
 and b
 are non-negative integers, or determine that it is impossible.

For example, if s
 = "0001", you can choose a=0
, b=1
, and write the year as (0+1)2=1
.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases.

The following lines describe the test cases.

The only line of each test case contains a string s
, consisting of exactly 4
 characters. Each character is a digit from 0
 to 9
.

Output
On a separate line for each test case, output:

Two numbers a
 and b
 (a,b≥0
) such that (a+b)2=s
, if they exist. If there are multiple suitable pairs, you may output any of them.
The number −1
 otherwise.
Example
InputCopy
5
0001
1001
1000
4900
2025
OutputCopy
0 1
-1
-1
34 36
20 25
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
