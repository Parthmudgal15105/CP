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
    int n, j, k;
    cin >> n >> j >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int strength = a[j - 1];
    sort(all(a));
    if (k >= 2)
    {
        cyes;
        return;
    }
    else if (a[n - 1] == strength)
    {
        cyes;
        return;
    }
    else
    {
        cno;
    }
}

/*
You are given an array of integers a1,a2,…,an
. A tournament is held with n
 players. Player i
 has strength ai
.

While more than k
 players remain,

Two remaining players are chosen at random;
Then the chosen player with the lower strength is eliminated. If the chosen players have the same strength, one is eliminated at random.
Given integers j
 and k
 (1≤j,k≤n
), determine if there is any way for player j
 to be one of the last k
 remaining players.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains three integers n
, j
, and k
 (2≤n≤2⋅105
, 1≤j,k≤n
).

The second line of each test case contains n
 integers, a1,a2,…,an
 (1≤ai≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "YES" if player j
 can be one of the last k
 remaining players, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
3
5 2 3
3 2 4 4 1
5 4 1
5 3 4 5 2
6 1 1
1 2 3 4 5 6
OutputCopy
YES
YES
NO
Note
In the first sample, suppose that players 2
 and 5
 are chosen. Then player 2
 defeats player 5
. Now, the remaining player strengths are

3	2	4	4
Next, suppose that players 3
 and 4
 are chosen. Then player 3
 might defeat player 4
. Now, the remaining player strengths are
3	2	4
Player 2
 is one of the last three players remaining.
In the third sample, it can be shown that there is no way for player 1
 to be the last player remaining.
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
