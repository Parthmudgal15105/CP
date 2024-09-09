#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    int consecutive = 0;
    int maxconsecutive = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Find the length of the longest subsequence where elements <= q
    for (int i = 0; i < n; i++) {
        if (a[i] <= q) {
            consecutive++;
            maxconsecutive = max(consecutive, maxconsecutive);
        } else {
            consecutive = 0;
        }
    }

    if (maxconsecutive >= k) {
        int factorial = 1;

        // Calculate the number of k-length segments
        int fact = maxconsecutive / k;
        for (int i = 1; i <= fact; i++) {
            factorial *= i;
        }

        // Print the factorial after the loop
        cout << factorial << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}

