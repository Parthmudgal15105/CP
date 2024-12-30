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
    // Read input
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int one = 0;
    int zero = 0;
    vector<pair<int, int>> x;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            one++;
        }
        else
            zero++;
        if (one == zero)
        {
            x.push_back({j, i});
            j = i + 1;
        }
    }
    for (auto i : x)
    {
        int s = i.first;
        int e = i.second;
        if (a[s] == b[s])
            continue;
        else
        {
            for (int j = s; j <= e; j++)
            {
                if (a[j] == '0')
                    a[j] = '1';
                else
                    a[j] = '0';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

/*
There is a binary string a
 of length n
. In one operation, you can select any prefix of a
 with an equal number of 0
 and 1
 symbols. Then all symbols in the prefix are inverted: each 0
 becomes 1
 and each 1
 becomes 0
.

For example, suppose a=0111010000
.

In the first operation, we can select the prefix of length 8
 since it has four 0
's and four 1
's: [01110100]00→[10001011]00
.
In the second operation, we can select the prefix of length 2
 since it has one 0
 and one 1
: [10]00101100→[01]00101100
.
It is illegal to select the prefix of length 4
 for the third operation, because it has three 0
's and one 1
.
Can you transform the string a
 into the string b
 using some finite number of operations (possibly, none)?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤3⋅105
) — the length of the strings a
 and b
.

The following two lines contain strings a
 and b
 of length n
, consisting of symbols 0
 and 1
.

The sum of n
 across all test cases does not exceed 3⋅105
.

Output
For each test case, output "YES" if it is possible to transform a
 into b
, or "NO" if it is impossible. You can print each letter in any case (upper or lower).

Example
InputCopy
5
10
0111010000
0100101100
4
0000
0000
3
001
000
12
010101010101
100110011010
6
000111
110100
OutputCopy
YES
YES
NO
YES
NO
Note
The first test case is shown in the statement.

In the second test case, we transform a
 into b
 by using zero operations.

In the third test case, there is no legal operation, so it is impossible to transform a
 into b
.

In the fourth test case, here is one such transformation:

Select the length 2
 prefix to get 100101010101
.
Select the length 12
 prefix to get 011010101010
.
Select the length 8
 prefix to get 100101011010
.
Select the length 4
 prefix to get 011001011010
.
Select the length 6
 prefix to get 100110011010
.
In the fifth test case, the only legal operation is to transform a
 into 111000
. From there, the only legal operation is to return to the string we started with, so we cannot transform a
 into b
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
