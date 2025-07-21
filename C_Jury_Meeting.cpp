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
int mod = 998244353;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

vl fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}

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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Sort the array to easily find the largest and second largest number of tasks
    sort(a.begin() + 1, a.end());

    // If the largest and second largest are equal, all permutations are valid (no one can speak twice in a row)
    if (a[n] == a[n - 1])
    {
        cout << fact[n] << nl;
        return;
    }

    // If the largest is more than one greater than the second largest, it's impossible to avoid consecutive turns
    if (a[n] > a[n - 1] + 1)
    {
        cout << 0 << nl;
        return;
    }

    // Count how many jury members have the second largest number of tasks
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[n - 1])
        {
            count++;
        }
    }

    // Start with all possible permutations (n!)
    ll ans = fact[n];

    // Now, subtract the "bad" permutations where the person with the most tasks
    // ends up speaking twice in a row at the end of a round.
    //
    // For each possible position i (1-based) of the person with the most tasks:
    // - We need to choose count positions before i for the people with the second most tasks.
    // - Arrange those count people: fact[count]
    // - Arrange the rest (excluding the max and count): fact[n - count - 1]
    // - Multiply by the number of ways to choose the positions: binom(i-1, count)
    //
    // This counts the number of "bad" permutations for each i, which we subtract from the total.
    for (int i = 1; i <= n; i++)
    {
        if (i - 1 < count)
        {
            continue; // Not enough positions before i to place all count people
        }

        // Calculate the number of "bad" permutations for this i
        ll decrease = (binom(i - 1, count) * fact[count] % mod * fact[n - count - 1] % mod);
        ans = (ans - decrease) % mod;
        if (ans < 0)
        {
            ans += mod;
        }
    }

    cout << ans << nl;
}
/*
n
 people gathered to hold a jury meeting of the upcoming competition, the i
-th member of the jury came up with ai
 tasks, which they want to share with each other.

First, the jury decides on the order which they will follow while describing the tasks. Let that be a permutation p
 of numbers from 1
 to n
 (an array of size n
 where each integer from 1
 to n
 occurs exactly once).

Then the discussion goes as follows:

If a jury member p1
 has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
If a jury member p2
 has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
...
If a jury member pn
 has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
If there are still members with tasks left, then the process repeats from the start. Otherwise, the discussion ends.
A permutation p
 is nice if none of the jury members tell two or more of their own tasks in a row.

Count the number of nice permutations. The answer may be really large, so print it modulo 998244353
.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of the test case contains a single integer n
 (2≤n≤2⋅105
) — number of jury members.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the number of problems that the i
-th member of the jury came up with.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print one integer — the number of nice permutations, taken modulo 998244353
.

Example
InputCopy
4
2
1 2
3
5 5 5
4
1 3 3 7
6
3 4 2 1 3 3
OutputCopy
1
6
0
540
Note
Explanation of the first test case from the example:

There are two possible permutations, p=[1,2]
 and p=[2,1]
. For p=[1,2]
, the process is the following:

the first jury member tells a task;
the second jury member tells a task;
the first jury member doesn't have any tasks left to tell, so they are skipped;
the second jury member tells a task;
So, the second jury member has told two tasks in a row (in succession), so the permutation is not nice.

For p=[2,1]
, the process is the following:

the second jury member tells a task;
the first jury member tells a task;
the second jury member tells a task;
So, this permutation is nice.



 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 2e5; i++)
        fact[i] = (i * fact[i - 1]) % mod;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
