#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Count the frequency of each element using a map
        map<int, int> mp;
        for (auto a : arr) mp[a]++;

        if (mp.size() == 1) {
            cout << "-1" << endl;  // If there's only one unique element, print -1
        } else {
            // Find the element with the smallest value and its frequency
            auto it = mp.begin();
            int ele = it->first;
            int freq = it->second;

            cout << freq << " " << n - freq << endl;

            // Print the first group (all occurrences of the smallest element)
            for (int i = 0; i < freq; i++) {
                cout << ele << " ";
            }
            cout << endl;

            // Remove the smallest element from the map
            mp.erase(it);

            // Print the second group (all remaining elements)
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                for (int i = 0; i < it->second; i++) {
                    cout << it->first << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}

 