#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<tuple<int, int, int>> constraints(k);
    for (int i = 0; i < k; i++)
    {
        int l, r, m;
        cin >> l >> r >> m;
        constraints[i] = {l, r, m};
    }

    // Initialize the array A with values in the range [1, N]
    vector<int> A(n);
    iota(A.begin(), A.end(), 1); // A = [1, 2, ..., N]

    // Check and modify array to satisfy constraints
    for (auto [l, r, m] : constraints)
    {
        // Convert to zero-based indexing for l and r
        l--;
        r--;
        // Check the minimum in the range [l, r]
        int current_min = *min_element(A.begin() + l, A.begin() + r + 1);
        if (current_min == m)
        {
            // Modify the minimum in the range to satisfy the condition
            bool modified = false;
            for (int i = l; i <= r; i++)
            {
                if (A[i] != m)
                {
                    A[i] = m + 1; // Increment to avoid the conflict
                    modified = true;
                    break;
                }
            }
            if (!modified)
            {
                // If we cannot satisfy the condition, print -1 and return
                cout << -1 << endl;
                return;
            }
        }
    }

    // Print the resulting array
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
