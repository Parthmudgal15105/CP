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
    int len;
    cin >> len;
    string s1, s2;
    cin >> s1 >> s2;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            if (s1[i] == '1')
                count1++;
            if (s2[i] == '1')
                count2++;
        }
        else
        {
            if (s1[i] == '1')
                count2++;
            if (s2[i] == '1')
                count1++;
        }
    }
    int limit1 = len / 2;
    int limit2 = len - limit1;
    if (count1 <= limit1 && count2 <= limit2)
    {
        cyes;
    }
    else
    {
        cno;
    }
}
/*
As soon as Dasha Purova crossed the border of France, the villain Markaron kidnapped her and placed her in a prison under his large castle. Fortunately, the wonderful Lady Bug, upon hearing the news about Dasha, immediately ran to save her in Markaron's castle. However, to get there, she needs to crack a complex password.

The password consists of two bit strings a
 and b
, each of which has a length of n
. In one operation, Lady Bug can choose any index 2≤i≤n
 and perform one of the following actions:

swap(ai
, bi−1
) (swap the values of ai
 and bi−1
), or
swap(bi
, ai−1
) (swap the values of bi
 and ai−1
).
Lady Bug can perform any number of operations. The password is considered cracked if she can ensure that the first string consists only of zeros. Help her understand whether or not she will be able to save the unfortunate Dasha.

Input
Each test consists of several test cases. The first line of the input data contains one integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer n
 (2≤n≤2⋅105
) — the length of the bit strings of the password.

The next two lines contain the bit strings of length n
, a
 and b
, which represent the password. Each of the strings contains only the characters 0 and '1'.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if Lady Bug can crack the password after any number of operations; otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

Example
InputCopy
4
3
000
000
6
010001
010111
5
10000
01010
2
11
00
OutputCopy
YES
YES
NO
YES
Note
In the first test case, the string a
 immediately consists only of zeros.

In the second test case, a possible sequence of operations is:

swap(a2, b1)

010001

010111

swap(b5, a4)

000001

110111

swap(a4, b3)

000101

110101

swap(a5, b4)

000001

111101



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
