#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;

    // taking input
    vector<ll> v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    // sorting the input vector so that we can easily find the distance between two infected houses
    sort(v.begin(), v.end());

    // priority queue to store the largest distance on top since we need to resolve the largest distance first
    // between two infected houses
    priority_queue<ll> pq;

    // storing the distance between two infected houses
    for (ll i = 0; i < m - 1; i++)
    {
        pq.push(v[i + 1] - v[i] - 1);
    }
    pq.push((n - v[m - 1]) + (v[0] - 1));

    // starting with day=0 since we can protect one house before virus starts
    // sum is number of uninfected houses
    ll day = 0, sum = 0;
    while (!pq.empty())
    {

        // pq.top()-2*day is number of uninfected houses

        // pq.top=largest segment (distance between two infected houses)
        // 2*day because this is a circular type arrangement so in 1 day 2 houses can get infected
        // for eg : 1 2 (3) 4 5 (6) 7 (8) 9 10     1st test case
        // in one day, both 4 and 5 will get infected

        if (pq.top() - (2 * day) == 1)
        { // if number of uninfected house=1 then we can simply protect that house
            sum++;
        }
        else if (pq.top() - (2 * day) < 1)
        { // if number of uninfected house<1 means that all the houses are infected
          // and hence we can simply stop iterating the print the result
            cout << n - sum << endl;
            return;
        }
        else
        {
            sum = sum + pq.top() - (2 * day) - 1; // if more than 1 uninfected houses are there, then we will be able to
                                                  // protect all the houses except one
        }
        day = day + 2; // increasing the day by 2 because we are spending 2 days to protect the houses
                       // for eg : 1 2 (3) 4 5 (6) 7 (8) 9 10     1st test case
                       // the prioritue would look like : 1 2 4
                       // we will spend 2 days to protect 3 houses out of 4
                       // hence ans in 1st test case=10-3=7
        pq.pop();
    }
    // ans=n-sum
    cout << n - sum << endl;
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