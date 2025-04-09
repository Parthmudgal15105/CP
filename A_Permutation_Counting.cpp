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
ll check(ll n, ll k, vll v, ll x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] < x)
        {
            ll diff = x - v[i];
            if (k < diff)
            {
                return -1;
            }
            else
            {
                k -= diff;
            }
        }
        v[i] -= x;
    }
    ll c = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
            c++;
    }
    if (c > n)
        c = n;
    return k + c;
}
/*
Explanation and Approach:
1. The program processes multiple test cases. For each test case:
   - It reads the number of card types (n) and available coins (k).
   - It reads an array representing the initial count of cards for each type.
2. The solution uses binary search on a candidate base count (x) for cards.
   - For a given x, the function check() simulates "buying" extra cards
     to at least reach that count for every type.
   - If sufficient coins are available, check() returns the remaining coins,
     which are then used to compute the score.
3. The score is calculated by combining the base score (based on x) and the extra coins.
4. The binary search continues until the maximum possible valid score is determined.
*/
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Set search boundaries: 'l' as the lower bound and 'h' as an upper estimate.
    ll h = 1e13;
    ll l = 1;
    ll ans = 0;
    // Perform binary search to determine the maximum achievable base count (x)
    while (l <= h)
    {
        ll mid = (l + (h - l) / 2);
        // The check() function returns remaining coins if it's possible to reach 'mid' for all card types, otherwise -1.
        ll res = check(n, k, v, mid);
        if (res != -1)
        {
            // Update ans: Calculate score using current base count and remaining coins.
            ans = max(ans, 1 + res + ((mid - 1) * n));
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    cout << ans << "\n";
}
/*
You have some cards. An integer between 1
 and n
 is written on each card: specifically, for each i
 from 1
 to n
, you have ai
 cards which have the number i
 written on them.

There is also a shop which contains unlimited cards of each type. You have k
 coins, so you can buy k
 new cards in total, and the cards you buy can contain any integer between 1
 and n
.

After buying the new cards, you rearrange all your cards in a line. The score of a rearrangement is the number of (contiguous) subarrays of length n
 which are a permutation of [1,2,…,n]
. What's the maximum score you can get?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100)
. The description of the test cases follows.

The first line of each test case contains two integers n
, k
 (1≤n≤2⋅105
, 0≤k≤1012
) — the number of distinct types of cards and the number of coins.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤1012
) — the number of cards of type i
 you have at the beginning.

It is guaranteed that the sum of n
 over all test cases does not exceed 5⋅105
.

Output
For each test case, output a single line containing an integer: the maximum score you can get.

Example
InputCopy
8
1 10
1
2 4
8 4
3 4
6 1 8
3 9
7 6 2
5 3
6 6 7 4 6
9 7
7 6 1 7 6 2 4 3 3
10 10
1 3 1 2 1 9 3 5 7 5
9 8
5 8 7 5 1 3 2 9 8
OutputCopy
11
15
15
22
28
32
28
36
Note
In the first test case, the final (and only) array we can get is [1,1,1,1,1,1,1,1,1,1,1]
 (including 11
 single 1
s), which contains 11
 subarrays consisting of a permutation of [1]
.

In the second test case, we can buy 0
 cards of type 1
 and 4
 cards of type 2
, and then we rearrange the cards as following: [1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2]
. There are 8
 subarrays equal to [1,2]
 and 7
 subarrays equal to [2,1]
, which make a total of 15
 subarrays which are a permutation of [1,2]
. It can also be proved that this is the maximum score we can get.

In the third test case, one of the possible optimal rearrangements is [3,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,3]
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
