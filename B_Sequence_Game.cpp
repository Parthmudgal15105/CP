#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                ans.push_back(arr[i]);
            } else {
                ans.push_back(arr[i]);
                ans.push_back(arr[i]);
            }
        }

        cout << ans.size() << nl;
        for (auto x : ans) {
            cout << x << sp;
        }
        cout << nl; // To ensure new test cases start from a new line.
    }
}

int main() {
    solve();
    return 0;
}
