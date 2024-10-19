#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Length of the array
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int result = a[0];
        // Perform AND over all elements of the array
        for (int i = 1; i < n; i++) {
            result &= a[i];
        }
        
        // Output the result of ANDing all elements
        cout << result << endl;
    }
}

int main() {
    solve();
    return 0;
}
