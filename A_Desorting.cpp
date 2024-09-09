#include <bits/stdc++.h>
using namespace std;

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
 
// Types
#define vi vector<int>
#define vvi vector<vector<int>>
 


// Function to find the minimum difference between consecutive elements in a sorted array
int minDiff(vector<int>& arr) {
    int n = arr.size();
    
    // Initialize the minimum difference as the maximum possible value
    int min_difference = INT_MAX;

    // Traverse the sorted array and compute the differences
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1];
        min_difference = min(min_difference, diff);
    }

    return min_difference;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(!is_sorted(arr.begin(),arr.end())){
        cout<<0<<endl;
    }
    else{
    // Get the minimum difference between consecutive elements
    int md = minDiff(arr);
   

     int ops = md/2+1;
     cout<<ops<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    // Process each test case
    while (t--) {
        solve();
    }
}
