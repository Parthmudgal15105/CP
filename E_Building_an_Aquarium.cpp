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
    // Read input: n = number of columns, x = maximum water units available
    ll n, x;
    cin >> n >> x;

    // Read array of coral heights
    vector<ll> a(n);
    for (ll &val : a)
        cin >> val;

    // Find maximum coral height and set binary search bounds
    ll mx = *max_element(a.begin(), a.end());
    // High bound: max height + possible water height per column + buffer
    ll high = mx + x / n + 10;
    // Low bound starts at minimum possible height (1)
    ll low = 1, ans = 1;

    // Binary search for maximum possible height
    while (low <= high)
    {
        // Try current height
        ll mid = (low + high) / 2;

        // Calculate total water needed for this height
        long long needed = 0;
        for (auto h : a)
        {
            // For each column shorter than mid, add water needed
            if (h < mid)
                needed += (mid - h);
            // Early break if we exceed available water
            if (needed > x)
                break;
        }

        // If we can fill with current height:
        // - Update answer
        // - Try a larger height (low = mid + 1)
        // Otherwise:
        // - Try a smaller height (high = mid - 1)
        if (needed <= x)
            ans = mid, low = mid + 1;
        else
            high = mid - 1;
    }

    // Print maximum possible height
    cout << ans << "\n";
}

/*
You love fish, that's why you have decided to build an aquarium. You have a piece of coral made of n
 columns, the i
-th of which is ai
 units tall. Afterwards, you will build a tank around the coral as follows:

Pick an integer h≥1
 — the height of the tank. Build walls of height h
 on either side of the tank.
Then, fill the tank up with water so that the height of each column is h
, unless the coral is taller than h
; then no water should be added to this column.
For example, with a=[3,1,2,4,6,2,5]
 and a height of h=4
, you will end up using a total of w=8
 units of water, as shown.

You can use at most x
 units of water to fill up the tank, but you want to build the biggest tank possible. What is the largest value of h
 you can select?
Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two positive integers n
 and x
 (1≤n≤2⋅105
; 1≤x≤109
) — the number of columns of the coral and the maximum amount of water you can use.

The second line of each test case contains n
 space-separated integers ai
 (1≤ai≤109
) — the heights of the coral.

The sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output a single positive integer h
 (h≥1
) — the maximum height the tank can have, so you need at most x
 units of water to fill up the tank.

We have a proof that under these constraints, such a value of h
 always exists.

Example
InputCopy
5
7 9
3 1 2 4 6 2 5
3 10
1 1 1
4 1
1 4 3 4
6 1984
2 6 5 9 1 8
1 1000000000
1
OutputCopy
4
4
2
335
1000000001
Note
The first test case is pictured in the statement. With h=4
 we need 8
 units of water, but if h
 is increased to 5
 we need 13
 units of water, which is more than x=9
. So h=4
 is optimal.

In the second test case, we can pick h=4
 and add 3
 units to each column, using a total of 9
 units of water. It can be shown that this is optimal.

In the third test case, we can pick h=2
 and use all of our water, so it is optimal.



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
