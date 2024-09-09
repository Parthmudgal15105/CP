#include <bits/stdc++.h>
 
using namespace std;
 
const long long inf = 1e12;
const int N = 1e3 + 5;
const int MOD = 1e8;
 
void solve() {
  int n;
  cin >> n;
  int pos = 0, neg = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0)
      neg++;
    else
      pos++;
  }
  if (pos >= neg) {
    cout << (neg % 2) << "\n";
  } else {
    // -1 -1 -1 -1 -1 -1 -1 1 1
    // -1 -1 -1 -1 -1 -1 1 1 1
    int total = (neg - pos + 1) / 2;
    neg -= total;
    if (neg % 2)
      total++;
    cout << total << "\n";
  }
  return;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
