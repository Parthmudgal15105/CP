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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    bool allMissing = true;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            allMissing = false;
            break;
        }
    }
    if (allMissing)
    {
        int maxA = *max_element(all(a));
        int minA = *min_element(all(a));
        int low = maxA;
        int high = minA + k;
        int ways = (high >= low) ? (high - low + 1) : 0;
        cout << ways << nl;
        return;
    }
    int cons = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            cons = a[i] + b[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            if (cons != a[i] + b[i])
            {
                cout << 0 << nl;
                return;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            if (cons - a[i] >= 0 && cons - a[i] <= k)
            {
                continue;
            }
            else
            {
                cout << ans << nl;
                return;
            }
        }
    }
    cout << 1 << nl;
}

/*
Two integer arrays a
 and b
 of size n
 are complementary if there exists an integer x
 such that ai+bi=x
 over all 1≤i≤n
. For example, the arrays a=[2,1,4]
 and b=[3,4,1]
 are complementary, since ai+bi=5
 over all 1≤i≤3
. However, the arrays a=[1,3]
 and b=[2,1]
 are not complementary.

Cow the Nerd thinks everybody is interested in math, so he gave Cherry Bomb two complementary integer arrays a
 and b
. It is known that a
 and b
 both contain n
 non-negative integers at most k
.

Unfortunately, Cherry Bomb has lost some elements in b
. Lost elements in b
 are denoted with −1
. Help Cherry Bomb count the number of possible arrays b
 such that:

a
 and b
 are complementary.
All lost elements are replaced with non-negative integers no more than k
.
Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤2⋅105
, 0≤k≤109
) — the size of the arrays and the maximum possible value of their elements.

The second line contains n
 integers a1,a2,...,an
 (0≤ai≤k
).

The third line contains n
 integers b1,b2,...,bn
 (−1≤bi≤k
). If bi=−1
, then this element is missing.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
Output exactly one integer, the number of ways Cherry Bomb can fill in the missing elements from b
 such that a
 and b
 are complementary.

Example
InputCopy
7
3 10
1 3 2
-1 -1 1
5 1
0 1 0 0 1
-1 0 1 0 -1
5 1
0 1 0 0 1
-1 1 -1 1 -1
5 10
1 3 2 5 4
-1 -1 -1 -1 -1
5 4
1 3 2 1 3
1 -1 -1 1 -1
5 4
1 3 2 1 3
2 -1 -1 2 0
5 5
5 0 5 4 3
5 -1 -1 -1 -1
OutputCopy
1
0
0
7
0
1
0
Note
In the first example, the only way to fill in the missing elements in b
 such that a
 and b
 are complementary is if b=[2,0,1]
.

In the second example, there is no way to fill in the missing elements of b
 such that a
 and b
 are complementary.

In the fourth example, some b
 arrays that are complementary to a
 are: [4,2,3,0,1],[7,5,6,3,4],
 and [9,7,8,5,6]
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
