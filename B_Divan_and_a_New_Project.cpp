#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '

using ll = long long;
using pii = pair<int, int>;
using vii = vector<pii>;
using vll = vector<ll>;

void solve()
{
    int numProjects;
    cin >> numProjects;

    vii projectVisits(numProjects + 1);
    for (int i = 1; i <= numProjects; i++)
    {
        cin >> projectVisits[i].first;
        projectVisits[i].second = i;
    }

    sort(projectVisits.begin() + 1, projectVisits.end(), greater<pii>());

    ll totalTime = 0;
    ll currentCoord = 1;
    vll coordinates(numProjects + 1);
    for (int i = 1; i <= numProjects; i++)
    {
        totalTime += 2 * currentCoord * projectVisits[i].first;

        if (i % 2 == 1)
        {
            coordinates[projectVisits[i].second] = currentCoord;
        }
        else
        {
            coordinates[projectVisits[i].second] = -currentCoord;
            currentCoord++;
        }
    }

    cout << totalTime << nl;
    for (auto coord : coordinates)
    {
        cout << coord << sp;
    }
    cout << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solve();
    }

    return 0;
}
