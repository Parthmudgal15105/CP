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
    // n = number of shops, x = daily budget
    int shops, budget;
    cin >> shops >> budget;

    // Store prices in a vector using long long to handle large numbers
    vector<ll> price(shops);
    for (int i = 0; i < shops; i++)
    {
        cin >> price[i];
    }

    // Sort prices to optimize buying from cheapest shops first
    sort(price.begin(), price.end());

    ll ans = 0;        // Total packs we can buy across all days
    ll prefix_sum = 0; // Running sum of prices for current set of shops

    // For each shop, calculate how many days we can buy including this shop
    for (int i = 0; i < shops; i++)
    {
        prefix_sum += price[i];

        // If current sum exceeds budget, we can't buy from more shops
        if (prefix_sum > budget)
            break;

        // Calculate days we can buy from current set of shops:
        // - (budget - prefix_sum) is remaining money for current day
        // - Divide by (i + 1) because prices increase by 1 each day
        // - Add 1 because we include current day
        ll days = (budget - prefix_sum) / (i + 1) + 1;

        // Add to answer:
        // days * (i + 1) = total packs bought from these shops
        // (i + 1) represents we buy from all shops up to current index
        ans += days;
    }

    cout << ans << endl;
}

/*
Turbulent times are coming, so you decided to buy sugar in advance. There are n
 shops around that sell sugar: the i
-th shop sells one pack of sugar for ai
 coins, but only one pack to one customer each day. So in order to buy several packs, you need to visit several shops.

Another problem is that prices are increasing each day: during the first day the cost is ai
, during the second day cost is ai+1
, during the third day — ai+2
 and so on for each shop i
.

On the contrary, your everyday budget is only x
 coins. In other words, each day you go and buy as many packs as possible with total cost not exceeding x
. Note that if you don't spend some amount of coins during a day, you can't use these coins during the next days.

Eventually, the cost for each pack will exceed x
, and you won't be able to buy even a single pack. So, how many packs will you be able to buy till that moment in total?

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases. Next t
 cases follow.

The first line of each test case contains two integers n
 and x
 (1≤n≤2⋅105
; 1≤x≤109
) — the number of shops and your everyday budget.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the initial cost of one pack in each shop.

It's guaranteed that the total sum of n
 doesn't exceed 2⋅105
.

Output
For each test case, print one integer — the total number of packs you will be able to buy until prices exceed your everyday budget.

Example
InputCopy
4
3 7
2 1 2
5 9
10 20 30 40 50
1 1
1
2 1000
1 1
OutputCopy
11
0
1
1500
Note
In the first test case,

Day 1: prices are [2,1,2]
. You can buy all 3
 packs, since 2+1+2≤7
.
Day 2: prices are [3,2,3]
. You can't buy all 3
 packs, since 3+2+3>7
, so you buy only 2
 packs.
Day 3: prices are [4,3,4]
. You can buy 2
 packs with prices 4
 and 3
.
Day 4: prices are [5,4,5]
. You can't buy 2
 packs anymore, so you buy only 1
 pack.
Day 5: prices are [6,5,6]
. You can buy 1
 pack.
Day 6: prices are [7,6,7]
. You can buy 1
 pack.
Day 7: prices are [8,7,8]
. You still can buy 1
 pack of cost 7
.
Day 8: prices are [9,8,9]
. Prices are too high, so you can't buy anything.
In total, you bought 3+2+2+1+1+1+1=11
 packs.
In the second test case, prices are too high even at the first day, so you can't buy anything.

In the third test case, you can buy only one pack at day one.

In the fourth test case, you can buy 2
 packs first 500
 days. At day 501
 prices are [501,501]
, so you can buy only 1
 pack the next 500
 days. At day 1001
 prices are [1001,1001]
 so can't buy anymore. In total, you bought 500⋅2+500⋅1=1500
 packs.



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
