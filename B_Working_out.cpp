#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Types of declarations /////////////////////////////////
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Odd Even /////////////////////////////////////////////
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

///////////////////////////////////////////////////////// LCM GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
////////////////////////////////////////////////////////// SQR ROOT

long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1;
        else
            e = m - 1;
    }
    return res;
}
/*
check all edge cases
check for integer overflow
check for corner cases
check for constraints
check for time complexity
check for array bounds
check for negative values
*/
/*
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/

void solve()
{
    int n, m;
    cin >> n >> m;
    // g[i][j] = calories at cell (i,j)
    vector<vi> g(n + 2, vi(m + 2));

    // dp1[i][j]: max calories Iahub can burn going from (1,1) → (i,j)
    //   moves allowed: down or right
    vector<vi> dp1(n + 2, vi(m + 2));

    // dp2[i][j]: max calories Iahubina can burn going from (n,1) → (i,j)
    //   moves allowed: up or right
    vector<vi> dp2(n + 2, vi(m + 2));

    // dp3[i][j]: max calories Iahub can burn going from (n,m) → (i,j)
    //   moves allowed: up or left (reverse of Iahub’s finish to meeting point)
    vector<vi> dp3(n + 2, vi(m + 2));

    // dp4[i][j]: max calories Iahubina can burn going from (1,m) → (i,j)
    //   moves allowed: down or left (reverse of Iahubina’s finish to meeting point)
    vector<vi> dp4(n + 2, vi(m + 2));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    // Build dp1: best path from (1,1) to every (i,j)
    // Transition: from top (i-1,j) or left (i,j-1)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp1[i][j] = g[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    // Build dp2: best path from (n,1) to every (i,j)
    // Transition: from below (i+1,j) or left (i,j-1)
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp2[i][j] = g[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);

    // Build dp3: best path from (n,m) to every (i,j)
    // Transition: from below (i+1,j) or right (i,j+1)
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            dp3[i][j] = g[i][j] + max(dp3[i + 1][j], dp3[i][j + 1]);

    // Build dp4: best path from (1,m) to every (i,j)
    // Transition: from top (i-1,j) or right (i,j+1)
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            dp4[i][j] = g[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

    ll ans = 0;
    // Now choose a meeting cell (i,j), 2≤i≤n−1, 2≤j≤m−1
    // They both enter (i,j) but do NOT collect g[i][j], then exit.
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= m - 1; j++)
        {
            // Case 1:
            //  - Iahub arrives from top, leaves downward:
            //      dp1[i-1][j] + dp3[i+1][j]
            //  - Iahubina arrives from left, leaves to right:
            //      dp2[i][j-1] + dp4[i][j+1]
            ll case1 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];

            // Case 2:
            //  - Iahub arrives from left, leaves to right:
            //      dp1[i][j-1] + dp3[i][j+1]
            //  - Iahubina arrives from below, leaves upward:
            //      dp2[i+1][j] + dp4[i-1][j]
            ll case2 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];

            // Take the best of both crossing patterns
            ans = max(ans, max(case1, case2));
        }
    }

    cout << ans;
}

/*
Summer is coming! It's time for Iahub and Iahubina to work out, as they both want to look hot at the beach. The gym where they go is a matrix a with n lines and m columns. Let number a[i][j] represents the calories burned by performing workout at the cell of gym in the i-th line and the j-th column.

Iahub starts with workout located at line 1 and column 1. He needs to finish with workout a[n][m]. After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1]. Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m]. After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].

There is one additional condition for their training. They have to meet in exactly one cell of gym. At that cell, none of them will work out. They will talk about fast exponentiation (pretty odd small talk) and then both of them will move to the next workout.

If a workout was done by either Iahub or Iahubina, it counts as total gain. Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible. Note, that Iahub and Iahubina can perform workouts with different speed, so the number of cells that they use to reach meet cell may differs.

Input
The first line of the input contains two integers n and m (3 ≤ n, m ≤ 1000). Each of the next n lines contains m integers: j-th number from i-th line denotes element a[i][j] (0 ≤ a[i][j] ≤ 105).

Output
The output contains a single number — the maximum total gain possible.

Examples
InputCopy
3 3
100 100 100
100 1 100
100 100 100
OutputCopy
800
Note
Iahub will choose exercises a[1][1] → a[1][2] → a[2][2] → a[3][2] → a[3][3]. Iahubina will choose exercises a[3][1] → a[2][1] → a[2][2] → a[2][3] → a[1][3].
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
