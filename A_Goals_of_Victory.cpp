#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Number of elements in the array
        vector<int> arr(n);
        for (int i = 0; i < n-1; i++) {
            cin >> arr[i];  // Read each element into the array
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];  // Sum all elements
        }
        cout << -sum << endl;  // Output the negative of the sum
    }
    return 0;
}




