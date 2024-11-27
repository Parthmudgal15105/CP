#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Find elements that have all bits of k
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & k) == k)
        {
            ans.push_back(i + 1);
        }
    }

    // If we found any such elements, their AND will be k
    if (!ans.empty())
    {
        cout << "YES\n"
             << ans.size() << "\n";
        for (int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}