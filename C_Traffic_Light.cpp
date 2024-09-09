#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n; // Length of the string

    char c;
    cin >> c; // Character to search from

    string s;
    cin >> s; // The string itself

    string s2 = s + s; // Double the string to handle cyclicity

    int lastG = -1; // Last seen position of 'g' from the right
    int maxDistance = 0; // Maximum distance found between 'c' and the nearest 'g'

    // Traverse from right to left to find the nearest 'g' position
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (s2[i] == 'g') {
            lastG = i;
        } else if (s2[i] == c && lastG != -1) { // If we find 'c' and we have seen a 'g' before
            maxDistance = max(maxDistance, lastG - i); // Calculate distance to the nearest 'g'
        }
    }

    cout << maxDistance << endl; // Output the maximum distance
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; // Number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}

