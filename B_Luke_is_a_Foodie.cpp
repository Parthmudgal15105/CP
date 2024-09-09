#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int MAXN = 300005;
int numbers[MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> numbers[i];
        }

        int num_min = numbers[1];
        int num_max = numbers[1];
        int res = 0;

        for (int i = 2; i <= n; i++) {
            num_max = max(num_max, numbers[i]);
            num_min = min(num_min, numbers[i]);

            if (num_max - num_min > 2 * x) {
                res++;
                num_min = num_max = numbers[i]; // Reset to the current number
            }
        }

       cout << res <<endl;
    }

    return 0;
}
