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
    ll x, y, k;
    cin >> x >> y >> k;

    /* Example: Let's say x=2, y=1, k=5
    To make k torches we need:
    1. k sticks for torches (5 sticks)
    2. k coals (5 coals)
    3. For each coal, we need y sticks (1 stick per coal * 5 coals = 5 sticks)

    Total sticks needed = k + (k * y) = k * (y + 1)
    In example: 5 + (5 * 1) = 5 * (1 + 1) = 10 sticks total needed

    Since we start with 1 stick, we need to get: k*(y+1) - 1 additional sticks
    In example: 10 - 1 = 9 additional sticks needed */
    ll needSticks = k * (y + 1) - 1;

    /* When we trade 1 stick, we get x sticks, so net gain is (x-1) sticks per trade
    To find trades needed: divide total needed sticks by net gain per trade
    We add (x-2) to numerator to round up the division

    In example: 9 sticks needed, each trade gives net 1 stick (2-1)
    trades = (9 + 0) / 1 = 9 trades for sticks */
    ll tradesForSticks = (needSticks + (x - 2)) / (x - 1);

    /* Total trades = trades for sticks + trades for coal
    We need exactly k trades for coal (one trade per coal)

    In example: 9 + 5 = 14 total trades */
    ll totalTrades = tradesForSticks + k;

    cout << totalTrades << nl;
}

/*
You are playing a very popular game called Cubecraft. Initially, you have one stick and want to craft k
 torches. One torch can be crafted using one stick and one coal.

Hopefully, you've met a very handsome wandering trader who has two trade offers:

exchange 1
 stick for x
 sticks (you lose 1
 stick and gain x
 sticks).
exchange y
 sticks for 1
 coal (you lose y
 sticks and gain 1
 coal).
During one trade, you can use only one of these two trade offers. You can use each trade offer any number of times you want to, in any order.

Your task is to find the minimum number of trades you need to craft at least k
 torches. The answer always exists under the given constraints.

You have to answer t
 independent test cases.

Input
The first line of the input contains one integer t
 (1≤t≤2⋅104
) — the number of test cases. Then t
 test cases follow.

The only line of the test case contains three integers x
, y
 and k
 (2≤x≤109
; 1≤y,k≤109
) — the number of sticks you can buy with one stick, the number of sticks required to buy one coal and the number of torches you need, respectively.

Output
For each test case, print the answer: the minimum number of trades you need to craft at least k
 torches. The answer always exists under the given constraints.

Example
InputCopy
5
2 1 5
42 13 24
12 11 12
1000000000 1000000000 1000000000
2 1000000000 1000000000
OutputCopy
14
33
25
2000000003
1000000001999999999
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
