#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int n, d, l;
        cin >> n >> d >> l; // Read n, d, and l for each test case

        // Check if the tree is impossible
        if (l > n - 1 || d >= n)
        {
            cout << -1 << endl;
            continue;
        }

        // Check if we can form a valid tree
        if (l == 1)
        {
            // If there's only 1 leaf, we just need to connect the tree in a line
            // and the leaf will be the last node
            if (d == 1 && n == 2)
            {
                cout << "1 2" << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }

        vector<pair<int, int>> edges;

        // First, create the main path with d+1 nodes to achieve the diameter
        for (int i = 1; i <= d + 1; ++i)
        {
            if (i == d + 1)
            {
                break;
            }
            edges.push_back({i, i + 1});
        }

        // Attach the remaining leaves
        int remaining_nodes = n - (d + 1);
        for (int i = d + 2; i <= n; ++i)
        {
            edges.push_back({d + 1, i});
        }

        // Output the constructed edges
        if (edges.size() == n - 1)
        {
            for (auto &edge : edges)
            {
                cout << edge.first << " " << edge.second << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

/*You are at a shop with n items numbered 1, 2, . . . n. For each i, the price of the item number i equals Ci
.
There is an offer under which, if you buy any k items, you can get any other item for free, whose price
does not exceed the cheapest of the k items. Please note that, the offer can be used any (including 0)
number of times.
For each m = 1, 2, . . . n, find the minimum amount that you need to pay in order to buy m items.*/