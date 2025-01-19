#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll count = 0, idx, require = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            require += b[i] - a[i];
            idx = i;
            count++;
        }

        if (count > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (count == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            if (i != idx && a[i] - b[i] < require)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}