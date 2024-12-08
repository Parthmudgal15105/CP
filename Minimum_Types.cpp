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
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> items(n);

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].second;
    }

    if (x == 0)
    {
        cout << 0 << endl;
        return;
    }

    sort(items.rbegin(), items.rend());

    int cost = x;
    int ans = 0;

    for (int i = 0; i < n && cost > 0; i++)
    {
        int coins_needed = min(items[i].second, (cost + items[i].first - 1) / items[i].first);

        if (coins_needed > 0)
        {
            cost -= coins_needed * items[i].first;
            ans++;
        }
    }

    if (cost <= 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

/*
Minimum Types
There are
N
N different types of coins.
The
i
i-th type of coin is worth
A
i
A
i
​
  dollars, and you have
B
i
B
i
​
  coins of this type with you.

There is an item with cost
X
X that you'd like to buy. What's the minimum number of distinct types of coins you need to use to buy it?
If it's not possible to buy the item no matter what, print
−
1
−1.

Note:

The objective is to minimize the number of distinct types of coins used, which is not the same thing as minimizing the number of coins used.
It is allowed to pay more than
X
X to buy the item: you need not pay exactly
X
X.
Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains two space-separated integers
N
N and
X
X — the number of types of coins and the price of the item, respectively.
The second line contains
N
N space-separated integers
A
1
,
A
2
,
…
,
A
N
A
1
​
 ,A
2
​
 ,…,A
N
​
  — the values of the coins.
The third line contains
N
N space-separated integers
B
1
,
B
2
,
…
,
B
N
B
1
​
 ,B
2
​
 ,…,B
N
​
  — the number of each type of coin with you.
Output Format
For each test case, output on a new line a single integer: the minimum number of distinct types of coins needed to buy the item, or
−
1
−1 if it's impossible to buy the item.

Constraints
1
≤
T
≤
1
0
4
1≤T≤10
4

1
≤
N
≤
1
0
5
1≤N≤10
5

1
≤
X
≤
1
0
9
1≤X≤10
9

1
≤
A
i
≤
1000
1≤A
i
​
 ≤1000
1
≤
B
i
≤
1000
1≤B
i
​
 ≤1000
The sum of
N
N over all test cases won't exceed
1
0
5
10
5
 .
Sample 1:
Input
Output
3
3 10
1 2 3
1 2 3
3 10
1 2 3
1 2 1
5 100
5 10 15 20 25
1 1 2 3 4
2
-1
1
Explanation:
Test case
1
1: Choose all coins of type
3
3 and one coin of type
2
2, to obtain a value of
3
+
3
+
3
+
2
=
11
3+3+3+2=11 using only two types of coins. This allows us to buy the item, which costs
10
10.
It's impossible to buy the item using only one type of coin, so the answer is
2
2.

Test case
2
2: It's impossible to buy them item even if we use all the coins we have.
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
