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
#define all(x) x.begin(), x.end()
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
/*
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"
/*----------------------------------------------------------------------------*/
// In DFS: check each neighbor, and use recursion to detect cycles.
bool dfs(int node, int parent, vector<set<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        // If the neighbor is not visited, recursively call DFS.
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis) == true)
            {
                // A cycle is detected from this neighbor.
                return true;
            }
        }
        // If the neighbor was already visited and is not the parent, a cycle exists.
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;

    int open = 0, closed = 0;
    vector<set<int>> adj(n + 1);
    vector<int> v(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        adj[i].insert(v[i]);
        adj[v[i]].insert(i);
    }

    int mx = 0, mn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // Perform DFS from an unvisited node.
            if (dfs(i, -1, adj, vis))
            {
                // If a cycle is found, increment both max and min counts.
                mx++;
                mn++;
            }
            else
            {
                // Without a cycle, only the max count is incremented.
                mx++;
            }
        }
    }
    if (mx != mn) // This line adjusts the minimum count of round dances. In our DFS, for each connected component we count 1 round dance (mx) and, only if a cycle is detected, we also count it toward the minimum (mn). However, if at least one component doesn't form a cycle (a tree-like component), then all those can be merged into a single dance together except one. The extra mn++ ensures that when not every component is cyclic (mx ≠ mn), we form one additional minimum dance to cover that case.
        mn++;
    cout << mn << " " << mx << endl;
}

/*
n
 people came to the festival and decided to dance a few round dances. There are at least 2
 people in the round dance and each person has exactly two neighbors. If there are 2
 people in the round dance then they have the same neighbor on each side.

You decided to find out exactly how many dances there were. But each participant of the holiday remembered exactly one neighbor. Your task is to determine what the minimum and maximum number of round dances could be.

For example, if there were 6
 people at the holiday, and the numbers of the neighbors they remembered are equal [2,1,4,3,6,5]
, then the minimum number of round dances is1
:

1−2−3−4−5−6−1
and the maximum is 3
:
1−2−1
3−4−3
5−6−5
Input
The first line contains a positive number t
 (1≤t≤104
) — the number of test cases. The following is a description of the test cases.

The first line of the description of each test case contains a positive number n
 (2≤n≤2⋅105
) — the number of people at the holiday.

The second line of the description of each test case contains n
 integers ai
 (1≤ai≤n,ai≠i
) — the number of the neighbor that the i
th person remembered.

It is guaranteed that the test cases are correct and corresponds to at least one division of people into round dances.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output two integers — the minimum and maximum number of round dances that could be.

Example
InputCopy
10
6
2 1 4 3 6 5
6
2 3 1 5 6 4
9
2 3 2 5 6 5 8 9 8
2
2 1
4
4 3 2 1
5
2 3 4 5 1
6
5 3 4 1 1 2
5
3 5 4 1 2
6
6 3 2 5 4 3
6
5 1 4 3 4 2
OutputCopy
1 3
2 2
1 3
1 1
1 2
1 1
1 1
2 2
1 2
1 1
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
