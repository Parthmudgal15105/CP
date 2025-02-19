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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
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
void solve()
{
    // Read input: n hurdles, m power-ups, l destination
    int n, m, l;
    cin >> n >> m >> l;
    ll ans = 0; // Count of power-ups used
    ll x = 1;   // Current jump power

    // Store hurdles and power-ups
    vector<pair<int, int>> v(n);  // Hurdles: {start, end}
    vector<pair<int, int>> v1(m); // Power-ups: {position, value}

    // Read hurdle intervals using traditional for loop
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    // Read power-up positions and values using traditional for loop
    for (int i = 0; i < m; i++)
    {
        cin >> v1[i].first >> v1[i].second;
    }

    // Max heap to store available power-up values
    priority_queue<ll> pq;

    // Current power-up index being processed
    int i = 0;

    // Process each hurdle
    for (int j = 0; j < n; j++)
    {
        // Length needed to jump over current hurdle
        int len = v[j].second - v[j].first + 2;

        // Add all power-ups available before current hurdle
        while (i < m && v1[i].first < v[j].first)
        {
            pq.push(v1[i].second);
            i++;
        }

        // Use power-ups while we need more jump power
        while (x < len && !pq.empty())
        {
            ll power = pq.top();
            pq.pop();
            ans++;      // Count power-up used
            x += power; // Increase jump power
        }

        // If we can't jump over hurdle even after using all available power-ups
        if (x < len)
        {
            ans = -1;
            break;
        }
    }

    cout << ans << "\n";
}
/*
Mualani loves surfing on her sharky surfboard!

Mualani's surf path can be modeled by a number line. She starts at position 1
, and the path ends at position L
. When she is at position x
 with a jump power of k
, she can jump to any integer position in the interval [x,x+k]
. Initially, her jump power is 1
.

However, her surf path isn't completely smooth. There are n
 hurdles on her path. Each hurdle is represented by an interval [l,r]
, meaning she cannot jump to any position in the interval [l,r]
.

There are also m
 power-ups at certain positions on the path. Power-up i
 is located at position xi
 and has a value of vi
. When Mualani is at position xi
, she has the option to collect the power-up to increase her jump power by vi
. There may be multiple power-ups at the same position. When she is at a position with some power-ups, she may choose to take or ignore each individual power-up. No power-up is in the interval of any hurdle.

What is the minimum number of power-ups she must collect to reach position L
 to finish the path? If it is not possible to finish the surf path, output −1
.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains three integers n
, m
, and L
 (1≤n,m≤2⋅105,3≤L≤109
) — the number of hurdles, the number of power-ups, and the position of the end.

The following n
 lines contain two integers li
 and ri
 (2≤li≤ri≤L−1
) — the bounds of the interval for the i
'th hurdle. It is guaranteed that ri+1<li+1
 for all 1≤i<n
 (i.e. all hurdles are non-overlapping, sorted by increasing positions, and the end point of a previous hurdle is not consecutive with the start point of the next hurdle).

The following m
 lines contain two integers xi
 and vi
 (1≤xi,vi≤L
) — the position and the value for the i
'th power-up. There may be multiple power-ups with the same x
. It is guaranteed that xi≤xi+1
 for all 1≤i<m
 (i.e. the power-ups are sorted by non-decreasing position) and no power-up is in the interval of any hurdle.

It is guaranteed the sum of n
 and the sum of m
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum number of power-ups she must collect to reach position L
. If it is not possible, output −1
.

Example
InputCopy
4
2 5 50
7 14
30 40
2 2
3 1
3 5
18 2
22 32
4 3 50
4 6
15 18
20 26
34 38
1 2
8 2
10 2
1 4 17
10 14
1 6
1 2
1 2
16 9
1 2 10
5 9
2 3
2 2
OutputCopy
4
-1
1
2
Note
In the first test case, she can collect power-ups 1
, 2
, 3
, and 5
 to clear all hurdles.

In the second test case, she cannot jump over the first hurdle.

In the fourth test case, by collecting both power-ups, she can jump over the hurdle.*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
