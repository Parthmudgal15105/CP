#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> c(n + 1); // taking 1 based indexing

    // pos map will store the indices of every color
    // second test case:  1 2 3 3 3 2 1
    // 1-{1, 7} 2-{2, 6} 3-{3, 3, 3}

    map<ll, vector<ll>> pos;

    for (ll i = 1; i <= k; i++)
    {
        pos[i].push_back(0);
    }

    for (ll i = 1; i <= n; i++)
    {
        cin >> c[i];
        pos[c[i]].push_back(i);
    }

    for (ll i = 1; i <= k; i++)
    {
        pos[i].push_back(n + 1);
    }

    ll ans = n;
    for (ll i = 1; i <= k; i++)
    {
        vector<ll> dif;
        // dif vector will store the difference(length) between 2 indexes

        for (ll j = 0; j + 1 < pos[i].size(); j++)
        {
            dif.push_back(pos[i][j + 1] - pos[i][j]);
        }

        // sort dif vector to find the max length and 2nd max length
        sort(dif.rbegin(), dif.rend());
        if (dif.size())
        {
            ll cur;

            // if dif size==1, means that color is not present
            if (dif.size() == 1)
            {
                cur = dif.back();
            }

            // take the max length/2 and 2nd max length and take the greater among them
            else
            {
                cur = max((dif[0] + 1) / 2, dif[1]);
            }

            ans = min(ans, cur);
        }
    }

    // ans is the distance between 2 consecutive indexes but what we need to print is no. of planks to skip
    // for eg 1---1 distance between both 1's is 4 but we need to skip 3 planks, so we need to print ans-1
    cout << ans - 1 << endl;
    return;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}