#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;
    int a[n];
    f(i, 0, n) cin >> a[i];

    ll ans = 2;
    while (true)
    {
        set<int> st;
        f(j, 0, n)
        {
            st.insert(a[j] % ans);
        }
        if (st.size() == 2)
        {
            cout << ans << endl;
            return;
        }
        ans *= 2;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
