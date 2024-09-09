#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool Isfound = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == k) {
                cout << "YES" << endl;
                Isfound = true; // Update the correct variable
                break; // Exit the loop once the element is found
            }
        }
        if (!Isfound) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
