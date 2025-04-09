#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

typedef long long ll;

ll power(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Sorting allows us to count subsequences in increasing order.
    sort(a.begin(), a.end());

    // dp maps a number 'x' to the count of valid subsequences that end with x.
    map<int, ll> dp;
    ll total = 0;

    for (int num : a)
    {
        // Each element can start a new subsequence (single element case).
        ll sum_subsequences = 1;

        for (auto it = dp.begin(); it != dp.end(); ++it)
        {
            if (it->first <= num)
            {
                sum_subsequences = (sum_subsequences + it->second) % MOD;
            }
            else
            {
                break;
            }
        }
        // Update the count of subsequences ending with num.
        dp[num] = sum_subsequences;
        // Add to our total valid arrays count.
        total = (total + sum_subsequences) % MOD;
    }

    cout << total << "\n";
}
/*
You are given an array a
 of length n
, consisting of positive integers a1,a2,…,an
.

We call an array b
 of length m
 of positive integers valid, if there exists a subsequence ai1,ai2,…,aim
 (with 1≤i1<i2<⋯<im≤n
) of the array a
, such that:

aij≥bjfor all1≤j≤m

Count the number of distinct valid arrays b
 over all m
. Two arrays b
 and b′
 are considered distinct if they differ in length or differ in at least one position.

Since this number may be large, print it modulo 998244353
.

Input
The first line contains a single integer t
 (1≤t≤105)
 — the number of test cases.

Each test case consists of two lines:

The first line contains a single integer n
 (1≤n≤2×105)
 — the length of array a
.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤109)
.

It is guaranteed that the sum of n
 over all test cases does not exceed 3×105
.

Output
For each test case, print a single integer — the number of valid arrays b
, modulo 998244353
.

Example
InputCopy
3
3
2 1 3
4
1 1 1 1
5
2455 551 5619 232 42146
OutputCopy
15
4
969580239
Note
For the first test, the valid arrays b
 and corresponding subsequences of a
 are:

Length 1
:
[1
]: subsequences [2
], [1
] or [3
].
[2
]: subsequences [2
], [3
].
[3
]: subsequence [3
].

Length 2
:
[1
, 1
]: subsequences [2
, 1
], [2
, 3
], [1
, 3
].
[1
, 2
]: subsequences [2
, 3
], [1
, 3
].
[1
, 3
]: subsequences [2
, 3
], [1
, 3
].
[2
, 1
]: subsequences [2
, 1
], [2
, 3
].
[2
, 2
]: subsequence [2
, 3
].
[2
, 3
]: subsequence [2
, 3
].

Length 3
:
[1
, 1
, 1
]: subsequence [2
, 1
, 3
].
[1
, 1
, 2
]: subsequence [2
, 1
, 3
].
[1
, 1
, 3
]: subsequence [2
, 1
, 3
].
[2
, 1
, 1
]: subsequence [2
, 1
, 3
].
[2
, 1
, 2
]: subsequence [2
, 1
, 3
].
[2
, 1
, 3
]: subsequence [2
, 1
, 3
].

So, there are 15
 distinct valid arrays b
.*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
