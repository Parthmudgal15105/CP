#include <bits/stdc++.h>
using namespace std;

#define vll vector<long long>
#define nl '\n'
#define sp ' '

// Function to preprocess occurrences of differences
unordered_map<int, int> preprocess(vll &points) {
    unordered_map<int, int> freq_map;
    int n = points.size();

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = abs(points[j] - points[i]);
            freq_map[diff]++;
        }
    }
    return freq_map;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vll points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    } 
    
    vll queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    // Preprocess all pairs' differences and count their occurrences
    unordered_map<int, int> freq_map = preprocess(points);
    
    // Answer each query by looking up the precomputed results
    for (int i = 0; i < q; i++) {
        int query = queries[i];
        cout << freq_map[query] << (i == q-1 ? nl : sp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
