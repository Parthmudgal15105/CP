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
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
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

/*----------------------------------------------------------------------------*/
void solve()
{
    // Read number of districts and their gang affiliations
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Edge case: If all districts belong to same gang, it's impossible to connect
    // because any direct connection would cause a revolt
    bool allSame = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            allSame = false;
            break;
        }
    }
    if (allSame)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    // Find first district that belongs to a different gang than district 0
    // This will be our secondary connection point
    int diffIndex = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            diffIndex = i;
            break;
        }
    }

    // Solution strategy:
    // 1. Connect district 1 to all districts with different gang than a[0]
    // This ensures no same-gang connections
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            cout << 1 << " " << i + 1 << "\n";
        }
    }

    // 2. Connect the found different-gang district to all remaining districts
    // that share the same gang as a[0]
    // This completes the tree without any same-gang connections
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0] && i != 0)
        {
            cout << diffIndex + 1 << " " << i + 1 << "\n";
        }
    }
}
/*
There are n
 districts in the town, the i
-th district belongs to the ai
-th bandit gang. Initially, no districts are connected to each other.

You are the mayor of the city and want to build n−1
 two-way roads to connect all districts (two districts can be connected directly or through other connected districts).

If two districts belonging to the same gang are connected directly with a road, this gang will revolt.

You don't want this so your task is to build n−1
 two-way roads in such a way that all districts are reachable from each other (possibly, using intermediate districts) and each pair of directly connected districts belong to different gangs, or determine that it is impossible to build n−1
 roads to satisfy all the conditions.

You have to answer t
 independent test cases.

Input
The first line of the input contains one integer t
 (1≤t≤500
) — the number of test cases. Then t
 test cases follow.

The first line of the test case contains one integer n
 (2≤n≤5000
) — the number of districts. The second line of the test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
), where ai
 is the gang the i
-th district belongs to.

It is guaranteed that the sum of n
 does not exceed 5000
 (∑n≤5000
).

Output
For each test case, print:

NO on the only line if it is impossible to connect all districts satisfying the conditions from the problem statement.
YES on the first line and n−1
 roads on the next n−1
 lines. Each road should be presented as a pair of integers xi
 and yi
 (1≤xi,yi≤n;xi≠yi
), where xi
 and yi
 are two districts the i
-th road connects.
For each road i
, the condition a[xi]≠a[yi]
 should be satisfied. Also, all districts should be reachable from each other (possibly, using intermediate districts).

Example
InputCopy
4
5
1 2 2 1 3
3
1 1 1
4
1 1000 101 1000
4
1 2 3 4
OutputCopy
YES
1 3
3 5
5 4
1 2
NO
YES
1 2
2 3
3 4
YES
1 2
1 3
1 4*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
