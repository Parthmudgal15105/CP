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
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/

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
// Updated solve function with detailed explanation comments
void solve()
{
    int a[200001];
    int n, k;
    cin >> n >> k; // Read number of rooms and chip toggle period (k minutes)

    // Read the installation times for each room's chip
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // Sort the installation times to access the smallest and largest easily.
    sort(a + 1, a + n + 1);

    // For each chip, modify its time to the next moment when the light is on,
    // such that it is nicely aligned with the chip having the latest installation time.
    // Each chip toggles in cycles of (k minutes ON, k minutes OFF) => cycle length = 2 * k.
    // The expression (a[n] + k - 1 - a[i]) calculates how much time needs to be added
    // so that a[i] is increased by an appropriate multiple of (k * 2) until it is at least near a[n].
    // Dividing by (k * 2) (using integer division) gives the number of full cycles needed.
    // Multiplying by (k * 2) converts that count back into minutes.
    for (int i = 1; i <= n; ++i)
        a[i] += (a[n] + k - 1 - a[i]) / (k * 2) * k * 2;

    // Once updated, sort again so that a[1] is the earliest and a[n] the latest adjusted time.
    sort(a + 1, a + n + 1);

    // Now, if the range (a[n] - a[1] + 1) exceeds k,
    // it means there is no moment when all lights are on simultaneously, so output -1.
    // Otherwise, output a[n] as the earliest such time.
    if (a[n] - a[1] + 1 > k)
        cout << -1 << endl;
    else
        cout << a[n] << endl;
}

/*
There is an apartment consisting of n
 rooms, each with its light initially turned off.

To control the lights in these rooms, the owner of the apartment decided to install chips in the rooms so that each room has exactly one chip, and the chips are installed at different times. Specifically, these times are represented by the array a1,a2,…,an
, where ai
 is the time (in minutes) at which a chip is installed in the i
-th room.

As soon as a chip is installed, it changes the room's light status every k
 minutes — it turns on the light for k
 minutes, then turns it off for the next k
 minutes, then turns it back on for the next k
 minutes, and so on. In other words, the light status is changed by the chip at minute ai
, ai+k
, ai+2k
, ai+3k
, …
 for the i
-th room.

What is the earliest moment when all rooms in the apartment have their lights turned on?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤k≤n≤2⋅105
) — the number of rooms in the apartment and the period of the chips.

The second line contains n
 distinct integers a1,a2,…,an
 (1≤ai≤109
) — the moments when the chips are installed.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the answer to the question (in minutes). If there is no such moment that the lights are turned on in all the rooms, print −1
 instead.

Example
InputCopy
9
4 4
2 3 4 5
4 3
2 3 4 5
4 3
3 4 8 9
3 3
6 2 1
1 1
1
7 5
14 34 6 25 46 7 17
6 5
40 80 99 60 90 50
6 5
64 40 50 68 70 10
2 1
1 1000000000
OutputCopy
5
-1
10
8
1
47
100
-1
-1
Note
In the first test case, all lights will be on by the minute 5
 without any of them being turned off by the chips. The answer is 5
.

In the second test case, due to k=3
, the 1
-st light will be on at minutes 2,3,4,8,9,10,14,…
; meanwhile, the 4
-th light will be on at minutes 5,6,7,11,12,13,17,…
. These two sequences don't have any number in common, so they will never be on at the same time.

In the third test case, it can be seen that the 1
-st and 2
-nd lights will be turned off at minutes 6
 and 7
, but the chips will turn them back on at minutes 9
 and 10
. The 3
-rd and 4
-th lights will also be on at minute 10
, so the answer is 10
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
