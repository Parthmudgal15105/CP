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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
    string s;
    cin >> s;
    string t;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << 0 << nl;
        return;
    }
    int ans = 1;
    int zero = 0;
    for (int i = idx; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero++;
            ans += 2;
            while (i + 1 < n && s[i + 1] == '0')
            {
                i++;
            }
        }
    }
    cout << ans << nl;
}

/*
One day after waking up, your friend challenged you to a brogramming contest. In a brogramming contest, you are given a binary string∗
 s
 of length n
 and an initially empty binary string t
. During a brogramming contest, you can make either of the following moves any number of times:

remove some suffix†
 from s
 and place it at the end of t
, or
remove some suffix from t
 and place it at the end of s
.
To win the brogramming contest, you must make the minimum number of moves required to make s
 contain only the character 0
 and t
 contain only the character 1
. Find the minimum number of moves required.
∗
A binary string is a string consisting of characters 0
 and 1
.

†
A string a
 is a suffix of a string b
 if a
 can be obtained from deletion of several (possibly, zero or all) elements from the beginning of b
.

Input
The first line contains an integer t
 (1≤t≤100
) — the number of test cases.

The first line of each test case is an integer n
 (1≤n≤1000
) — the length of the string s
.

The second line of each test case contains the binary string s
.

The sum of n
 across all test cases does not exceed 1000
.

Output
For each testcase, output the minimum number of moves required.

Example
InputCopy
5
5
00110
4
1111
3
001
5
00000
3
101
OutputCopy
2
1
1
0
3
Note
An optimal solution to the first test case is as follows:

s=00110
, t=
 empty string.
s=00
, t=110
.
s=000
, t=11
.
It can be proven that there is no solution using less than 2
 moves.

In the second test case, you have to move the whole string from s
 to t
 in one move.

In the fourth test case, you don't have to do any moves.
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
