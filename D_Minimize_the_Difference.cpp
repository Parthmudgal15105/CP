#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<long long>& arr) {
    long long sum = 0;
    for (long long num : arr) {
        sum += num;
    }
    
    long long n = arr.size();
    long long average = sum / n;
    
    // If the sum is perfectly divisible by n, all elements can be made equal
    if (sum % n == 0) {
        return 0;
    }
    
    // Otherwise, the minimum difference will be 1
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << solve(arr) << "\n";
    }
    
    return 0;
}