#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        cin >> a;

        vector<bool> covered(n + 1, false); // To track covered indices
        int ans = 0;

        for (int k = 1; k <= n; ++k)
        {
            for (int j = k; j <= n; j += k)
            {
                if (covered[j])
                    continue; // Skip already covered multiples
                if (a[j - 1] == '1')
                    break;         // Stop if it's part of T
                covered[j] = true; // Mark as covered
                ans += k;          // Add cost of operation
            }
        }

        cout << ans << endl;
    }
    return 0;
}
