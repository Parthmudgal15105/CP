#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Map to store the frequency of each element
    unordered_map<int, int> freq;

    // Counting the frequency of each element
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Variables to track the most frequent element and its frequency
    int most_frequent = a[0];
    int max_count = 0;

    // Finding the most frequent element
    for (auto &entry : freq) {
        if (entry.second > max_count) {
            max_count = entry.second;
            most_frequent = entry.first;
        }
    }

    int ans = n - max_count;

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--)
        solve();
}
