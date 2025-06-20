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

/*
 Solves one test case by finding the minimum time T such that all m tasks
 can be completed by n workers in parallel. If a task is assigned to its
 proficient worker it takes 1h, otherwise 2h. We binary-search T.
*/
/*https://www.youtube.com/watch?v=gCNZskj5pYw&t=16s*/
void solve()
{
    ll n, m;
    cin >> n >> m;

    // Count how many tasks each worker is proficient in
    map<ll, ll> f;
    vector<ll> v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
        f[v[i]]++;
    }

    // Binary search over possible total completion times
    ll l = 1, r = 2 * m, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        ll extraTime = 0; // extra time left after all his work is done
        ll extraWork = 0; // work left after mid profecient tasks assigned

        // For each worker i from 1..n
        for (ll i = 1; i <= n; i++)
        {
            ll cnt = f[i]; // tasks worker i is proficient in
            if (mid > cnt)
            {
                // spare time slots: each extra hour can cover half a non-proficient task
                extraTime += (mid - cnt) / 2;
            }
            else
            {
                // tasks that cannot be done proficiently within mid and is req to be done by someone else
                extraWork += cnt - mid;
            }
        }

        // If spare capacity covers all excess tasks, mid is feasible
        if (extraTime >= extraWork)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << nl;
}

/*
There are n
 workers and m
 tasks. The workers are numbered from 1
 to n
. Each task i
 has a value ai
 — the index of worker who is proficient in this task.

Every task should have a worker assigned to it. If a worker is proficient in the task, they complete it in 1
 hour. Otherwise, it takes them 2
 hours.

The workers work in parallel, independently of each other. Each worker can only work on one task at once.

Assign the workers to all tasks in such a way that the tasks are completed as early as possible. The work starts at time 0
. What's the minimum time all tasks can be completed by?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of testcases.

The first line of each testcase contains two integers n
 and m
 (1≤n≤m≤2⋅105
) — the number of workers and the number of tasks.

The second line contains m
 integers a1,a2,…,am
 (1≤ai≤n
) — the index of the worker proficient in the i
-th task.

The sum of m
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print a single integer — the minimum time all tasks can be completed by.

Example
InputCopy
4
2 4
1 2 1 2
2 4
1 1 1 1
5 5
5 1 3 2 4
1 1
1
OutputCopy
2
3
1
1
Note
In the first testcase, the first worker works on tasks 1
 and 3
, and the second worker works on tasks 2
 and 4
. Since they both are proficient in the corresponding tasks, they take 1
 hour on each. Both of them complete 2
 tasks in 2
 hours. Thus, all tasks are completed by 2
 hours.

In the second testcase, it's optimal to assign the first worker to tasks 1,2
 and 3
 and the second worker to task 4
. The first worker spends 3
 hours, the second worker spends 2
 hours (since they are not proficient in the taken task).

In the third example, each worker can be assigned to the task they are proficient at. Thus, each of them complete their task in 1
 hour.
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
