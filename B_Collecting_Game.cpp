#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve()
{
    int n;
    cin >> n;
    // Store elements as pairs of (value, original_index)
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i; // Keep track of original positions
    }

    // Array to store answers for each position
    int ans[n];
    memset(ans, 0, sizeof(ans));

    // Sort by values to process from smallest to largest
    sort(all(a));

    // sum: running sum of collected elements
    // j: lookahead pointer
    // i: current element being processed
    int sum = 0, j, i = 0;
    while (i < n)
    {
        // Add current element to sum
        sum += a[i].first;

        // Look ahead to find how many next elements we can collect
        j = i + 1;
        while (j < n && sum >= a[j].first)
        {
            sum += a[j++].first;
        }

        // All elements from i to j-1 can collect the same number of elements
        // because they all have sufficient score to collect everything smaller
        for (int k = i; k < j; k++)
        {
            ans[a[k].second] = j; // j represents total elements that can be collected
        }

        // Move to next unchecked element
        i = j;
    }

    // Print results (subtract 1 because we don't count removing self)
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] - 1 << " \n"[i == n - 1];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}