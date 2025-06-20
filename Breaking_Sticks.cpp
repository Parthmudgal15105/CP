
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int count0 = 0, count1 = 0, pair = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            count0++;
        else if (a[i] == 1)
            count1++;

        if (count0 == count1)
            pair++;
    }

    cout << pair + 1 << nl;
}
/*
You are given a binary string
S
S of length
N
N, i.e.
S
i
=
0
S
i
​
 =0 or
1
1.

You can do the following operation as many times as you want (possibly zero):

Choose a prefix
S
[
1
,
X
]
S[1,X] (
1
≤
X
≤
N
1≤X≤N) such that there are equal number of
0
0s and
1
1s in this prefix, and then flip
†
†
  that prefix.
For example, in the string
001101
001101, we can choose the prefix of length
4
4 which has
2
2
0
0s and
2
2
1
1s, flipping it produces
110001
110001.

Count the number of possible strings you can obtain by doing these operations.

†
†
  To flip a string means to change all
0
0s to
1
1s and all
1
1s to
0
0s.

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains
N
N - the size of the string
The second line contains
S
S - a binary string.
Output Format
For each test case, output on a new line the count of strings obtainable.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
60
1≤N≤60
∣
S
∣
=
N
∣S∣=N
S
i
∈
{
0
,
1
}
S
i
​
 ∈{0,1}
Sample 1:
Input
Output
3
3
010
4
0010
6
001101
2
1
4
Explanation:
Test Case 1 : Flip the prefix of length
2
2 to obtain
100
100. The original string,
010
010 should also be counted. Hence the answer is
2
2.

Test Case 2 : No prefixes have equal
0
0s and
1
1s, so no operations are possible. The original string
0010
0010 is the only possible string.
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
