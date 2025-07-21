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
vector<vector<int>> dp;
vector<int> a;
int n, h, l, r;

int getMaxGoodWakeups(int sleep, int currentHour)
{
    // Base case: if all sleep events are processed, no more wakeups possible
    if (sleep > n)
        return 0;

    // Return memoized result if already computed for this state
    if (dp[sleep][currentHour] != -1)
        return dp[sleep][currentHour];

    int maxGoodWakeups = 0;

    // Option 1: Sleep after (a[sleep] - 1) hours
    int Option1 = (currentHour + a[sleep] - 1) % h;
    int goodWakeupsOption1 = getMaxGoodWakeups(sleep + 1, Option1);

    if (Option1 >= l && Option1 <= r)
    {
        goodWakeupsOption1++;
    }

    // Option 2: Sleep after a[sleep] hours
    int Option2 = (currentHour + a[sleep]) % h;
    int goodWakeupsOption2 = getMaxGoodWakeups(sleep + 1, Option2);

    if (Option2 >= l && Option2 <= r)
    {
        goodWakeupsOption2++;
    }

    maxGoodWakeups = max(goodWakeupsOption1, goodWakeupsOption2);

    return dp[sleep][currentHour] = maxGoodWakeups;
}

void solve()
{
    cin >> n >> h >> l >> r;
    a.assign(n + 1, 0); // 1-based indexing for sleep durations
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Initialize DP table with -1 (uncomputed)
    // dp[day][currentHour]: day in [1, n+1], currentHour in [0, h-1]
    dp.assign(n + 2, vector<int>(h + 1, -1));

    // Start DP from day 1, hour 0 (Vova wakes up at hour 0)
    cout << getMaxGoodWakeups(1, 0) << nl;
}

/*
Vova had a pretty weird sleeping schedule. There are h
 hours in a day. Vova will sleep exactly n
 times. The i
-th time he will sleep exactly after ai
 hours from the time he woke up. You can assume that Vova woke up exactly at the beginning of this story (the initial time is 0
). Each time Vova sleeps exactly one day (in other words, h
 hours).

Vova thinks that the i
-th sleeping time is good if he starts to sleep between hours l
 and r
 inclusive.

Vova can control himself and before the i
-th time can choose between two options: go to sleep after ai
 hours or after ai−1
 hours.

Your task is to say the maximum number of good sleeping times Vova can obtain if he acts optimally.

Input
The first line of the input contains four integers n,h,l
 and r
 (1≤n≤2000,3≤h≤2000,0≤l≤r<h
) — the number of times Vova goes to sleep, the number of hours in a day and the segment of the good sleeping time.

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai<h
), where ai
 is the number of hours after which Vova goes to sleep the i
-th time.

Output
Print one integer — the maximum number of good sleeping times Vova can obtain if he acts optimally.

Example
InputCopy
7 24 21 23
16 17 14 20 20 11 22
OutputCopy
3
Note
The maximum number of good times in the example is 3
.

The story starts from t=0
. Then Vova goes to sleep after a1−1
 hours, now the time is 15
. This time is not good. Then Vova goes to sleep after a2−1
 hours, now the time is 15+16=7
. This time is also not good. Then Vova goes to sleep after a3
 hours, now the time is 7+14=21
. This time is good. Then Vova goes to sleep after a4−1
 hours, now the time is 21+19=16
. This time is not good. Then Vova goes to sleep after a5
 hours, now the time is 16+20=12
. This time is not good. Then Vova goes to sleep after a6
 hours, now the time is 12+11=23
. This time is good. Then Vova goes to sleep after a7
 hours, now the time is 23+22=21
. This time is also good.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
