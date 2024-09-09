#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
#define int long long
 
signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        vector <int> a(n);
        a[0] = k * b;
        s -= k * b;
        if (s < 0) cout << "-1\n";
        else {
            for (int i = 0; i < n; ++i) {
                int now = min(k - 1, s);
                a[i] += now;
                s -= now;
            }
            if (s > 0) cout << "-1\n";
            else {
                for (int i = 0; i < n; ++i) cout << a[i] << " ";
                cout << "\n";
            }
        }
    }
}