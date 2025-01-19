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
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n), b(n), suma(n), maxb(n);
    cin >> a[0];
    suma[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        cin >> a[i];
        suma[i] = a[i] + suma[i - 1];
    }
    cin >> b[0];
    maxb[0] = b[0];
    for (ll i = 1; i < n; i++)
    {
        cin >> b[i];
        maxb[i] = max(maxb[i - 1], b[i]);
    }
    ans = INT_MIN;
    k--;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, suma[i] + (k - i) * maxb[i]);
        if (i == k)
            break;
    }
    cout << ans << endl;
}

/*
Monocarp is playing a computer game. In order to level up his character, he can complete quests. There are n
 quests in the game, numbered from 1
 to n
.

Monocarp can complete quests according to the following rules:

the 1
-st quest is always available for completion;
the i
-th quest is available for completion if all quests j<i
 have been completed at least once.
Note that Monocarp can complete the same quest multiple times.

For each completion, the character gets some amount of experience points:

for the first completion of the i
-th quest, he gets ai
 experience points;
for each subsequent completion of the i
-th quest, he gets bi
 experience points.
Monocarp is a very busy person, so he has free time to complete no more than k
 quests. Your task is to calculate the maximum possible total experience Monocarp can get if he can complete no more than k
 quests.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤2⋅105
; 1≤k≤2⋅105
) — the number of quests and the maximum number of quests Monocarp can complete, respectively.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤103
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤103
).

Additional constraint on the input: the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible total experience Monocarp can get if he can complete no more than k
 quests.

Example
InputCopy
4
4 7
4 3 1 2
1 1 1 1
3 2
1 2 5
3 1 8
5 5
3 2 4 1 4
2 3 1 4 7
6 4
1 4 5 4 5 10
1 5 1 2 5 1
OutputCopy
13
4
15
15
Note
In the first test case, one of the possible quest completion sequences is as follows: 1,1,2,3,2,4,4
; its total experience is equal to 4–+1+3–+1–+1+2–+1=13
 (the underlined numbers correspond to the instances when we complete a quest for the first time).

In the second test case, one of the possible quest completion sequences is as follows: 1,1
; its total experience is equal to 1–+3=4
.

In the third test case, one of the possible quest completion sequences is as follows: 1,2,2,2,3
; its total experience is equal to 3–+2–+3+3+4–=15
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
