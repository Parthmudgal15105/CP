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
ll val(const vector<ll> &h, ll i)
{
    // compute how many floors to add at i to exceed both neighbors
    ll m = max(h[i + 1], h[i - 1]);
    if (h[i] > m)
        return 0; // already cool
    else
        return m - h[i] + 1; // floors needed
}
void solve()
{
    ll n;
    cin >> n; // number of buildings
    vector<long long> h(n);
    for (ll i = 0; i < n; i++)
        cin >> h[i]; // read heights of all buildings

    // total additional floors needed
    ll sum = 0;
    if (n % 2 == 1)
    {
        // For odd n, the optimal strategy is deterministic:
        // Make every building at odd indices (1,3,5...) cool
        for (ll i = 1; i < n; i += 2)
        {
            ll need = max(h[i - 1], h[i + 1]);
            if (h[i] > need)
                continue; // already taller than both neighbors (already cool)
            else
                sum += need - h[i] + 1; // add just enough floors to exceed tallest neighbor
        }
        cout << sum << nl;
    }
    else
    {
        // For even n, we have two possible patterns to consider:
        // 1. Make buildings at positions 1,3,5... cool (pattern starting at index 1)
        // 2. Make buildings at positions 2,4,6... cool (pattern starting at index 2)
        // We need DP to find which pattern minimizes the total floors

        // dp[i] = minimum floors needed to maximize cool buildings up to position i
        vector<ll> dp(n, LLONG_MAX);
        dp[1] = val(h, 1); // Base case: cost to make building at index 1 cool
        dp[2] = val(h, 2); // Base case: cost to make building at index 2 cool

        for (ll i = 3; i < n - 1; i++)
        {
            if (i % 2 == 1)
            {
                // For odd indices: we're extending the pattern that started at index 1
                // We add the cost for making current position cool to previous cost
                dp[i] = dp[i - 2] + val(h, i);
            }
            else
            {
                // For even indices: we have two choices for the previous pattern
                // Either continue from i-2 (same parity) or switch pattern from i-3
                // We choose the option with minimum total cost
                dp[i] = min(dp[i - 2], dp[i - 3]) + val(h, i);
            }
        }

        // The final answer is the minimum between:
        // 1. Pattern ending at position n-2 (last even position)
        // 2. Pattern ending at position n-3 (last odd position)
        // Both patterns maximize the number of cool buildings for even n
        cout << min(dp[n - 2], dp[n - 3]) << nl;
    }
}

/*
Qpwoeirut has taken up architecture and ambitiously decided to remodel his city.

Qpwoeirut's city can be described as a row of n
 buildings, the i
-th (1≤i≤n
) of which is hi
 floors high. You can assume that the height of every floor in this problem is equal. Therefore, building i
 is taller than the building j
 if and only if the number of floors hi
 in building i
 is larger than the number of floors hj
 in building j
.

Building i
 is cool if it is taller than both building i−1
 and building i+1
 (and both of them exist). Note that neither the 1
-st nor the n
-th building can be cool.

To remodel the city, Qpwoeirut needs to maximize the number of cool buildings. To do this, Qpwoeirut can build additional floors on top of any of the buildings to make them taller. Note that he cannot remove already existing floors.

Since building new floors is expensive, Qpwoeirut wants to minimize the number of floors he builds. Find the minimum number of floors Qpwoeirut needs to build in order to maximize the number of cool buildings.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains the single integer n
 (3≤n≤105
) — the number of buildings in Qpwoeirut's city.

The second line of each test case contains n
 integers h1,h2,…,hn
 (1≤hi≤109
) — the number of floors in each of the buildings of the city.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the minimum number of additional floors Qpwoeirut needs to build in order to maximize the number of cool buildings.

Example
InputCopy
6
3
2 1 2
5
1 2 1 4 3
6
3 1 4 5 5 2
8
4 2 1 3 5 3 6 1
6
1 10 1 1 10 1
8
1 10 11 1 10 11 10 1
OutputCopy
2
0
3
3
0
4
Note
In the first test case, it is optimal for Qpwoeirut to make the second building cool by building 2
 additional floors on top of it, making it taller than both of its adjacent buildings. The final heights of buildings will be [2,3–,2]
.


In the second test case, the number of cool buildings is already maximized, so Qpwoeirut does not need to do anything.

In the third test case, it is optimal for Qpwoeirut to make the third and fifth buildings cool by building 2
 additional floors onto the third building and 1
 additional floor onto the fifth building. The final heights of buildings will be [3,1,6–,5,6–,2]
.


It can be shown that it is impossible to make more than 2
 of the buildings cool, or to make 2
 buildings cool using fewer than 3
 additional floors.

In the fourth test case, Qpwoeirut can either make the second building cool, or he can make the third building cool. Either way, he will be building 3
 additional floors and maximizing the number of cool buildings. The final heights of buildings will be [4,2,4–,3,5,3,6,1]
 or [4,5–,1,3,5,3,6,1]
.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; // number of test cases
    while (t--)
        solve(); // solve each independently
    return 0;
}
