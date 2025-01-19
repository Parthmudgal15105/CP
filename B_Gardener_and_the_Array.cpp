#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Variable declarations
    // t: number of test cases
    // f: flag for checking unique bits
    // n: size of array
    // p: temporary variable for bit position
    ll t, f, i, j, n, p;
    string ans;

    cin >> t;

    // Process each test case
    for (; t--;)
    {
        cin >> n;
        // mp: stores frequency of each bit position
        unordered_map<ll, ll> mp;
        // k[i]: number of set bits in i-th number
        ll k[n];
        // bits[i]: stores all set bit positions for i-th number
        vector<ll> bits[n];

        // Input phase
        for (i = 0; i < n; i++)
        {
            cin >> k[i];
            // Read k[i] bit positions for current number
            for (j = 0; j < k[i]; j++)
            {
                cin >> p;
                // Increment frequency of this bit position
                mp[p]++;
                // Store bit position for current number
                bits[i].push_back(p);
            }
        }

        ans = "NO";

        // Check each number if it can be removed
        for (i = 0; i < n; i++)
        {
            f = 0;
            // Check if current number has any unique bit
            for (j = 0; j < k[i]; j++)
            {
                // If bit appears only once, it can't be removed
                if (mp[bits[i][j]] == 1)
                {
                    f++;
                    break;
                }
            }
            // If unique bits found, we can remove this number
            if (f == 0)
            {
                ans = "YES";
                break;
            }
        }

        cout << ans << "\n";
    }
}