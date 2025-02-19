#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Basic type definitions
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vstr vector<string>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

// Utility functions for odd/even check
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

// Prime checking
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// GCD and LCM functions
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

// Custom square root function using binary search
long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
        {
            res = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return res;
}

/*
  This code simulates lava flow from volcanoes (positions with 0 height) to buildings.
  For each position, we compute the minimum time required for lava to submerge it.
  We use two arrays:
    - prefix: the minimum time computed when lava flows from the left (starting at index 0).
    - suffix: the minimum time computed when lava flows from the right (starting at last index).

  For a building with height 'h' and lava rate 'p', the required time to submerge it is:
      ceil(h / p) = (h + p - 1) / p.
  At a volcano (height 0), the required time is 0.

  Lava can only propagate from a side if that side has already been reached by lava (i.e. time != INF).
  For each building, we take the maximum of:
    - the propagation time from that side,
    - and the time required to submerge the building.
  Finally, the answer for each position is the minimum time computed from the two directions.
*/

void solve()
{
    int n, p;
    cin >> n >> p;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    const int INF = 1e9; // A large number (sufficient for this problem)

    // Use 'prefix' and 'suffix' arrays instead of left/right.
    vi prefix(n, INF), suffix(n, INF);

    // Lambda to calculate the required time to submerge a building of a given height.
    auto requiredTime = [p](int height) -> int
    {
        return (height + p - 1) / p; // Ceiling division
    };

    // Initialize volcano positions (height 0) with time 0.
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            prefix[i] = suffix[i] = 0;
    }

    // Prefix propagation: from left to right.
    for (int i = 1; i < n; i++)
    {
        // Only propagate if the previous position is reached by lava.
        if (prefix[i - 1] != INF)
        {
            if (a[i] != 0) // Current position is a building.
                prefix[i] = min(prefix[i], max(prefix[i - 1], requiredTime(a[i])));
            else // Current position is a volcano.
                prefix[i] = 0;
        }
    }

    // Suffix propagation: from right to left.
    for (int i = n - 2; i >= 0; i--)
    {
        if (suffix[i + 1] != INF)
        {
            if (a[i] != 0) // Current position is a building.
                suffix[i] = min(suffix[i], max(suffix[i + 1], requiredTime(a[i])));
            else // Current position is a volcano.
                suffix[i] = 0;
        }
    }

    // For each position, take the minimum time from either the prefix or suffix propagation.
    for (int i = 0; i < n; i++)
    {
        int ans = min(prefix[i], suffix[i]);
        cout << ans << sp;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
