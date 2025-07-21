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
#define mod 1000000007

// Types of declarations /////////////////////////////////
#define all(x) x.begin(), x.end()
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

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
////////////////////////////////////////////////////////// BINOMIAL COEFF
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
    // Read number of casinos n and your starting coins k
    int n;
    ll coins;
    cin >> n >> coins;

    // a[i] = {li, ri, reali}
    // li = minimum coins needed to enter
    // ri = maximum coins allowed to enter
    // reali = coins you end up with after playing
    vvi a(n, vi(3));
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    // Sort casinos by li ascending, so we can add all currently enterable
    sort(all(a), [](auto &x, auto &y)
         { return x[0] < y[0]; });

    // Max‐heap (priority queue) stores pairs {reali, index}
    // so we always pick the casino that gives the most coins next
    priority_queue<pair<ll, int>> pq;

    ll cur = coins; // current coins
    int idx = 0;    // pointer into sorted array a[]

    while (true)
    {
        // 1) Add all casinos we can now enter (li ≤ cur) into pq
        while (idx < n && a[idx][0] <= cur)
        {
            pq.push({a[idx][2], idx});
            idx++;
        }

        // 2) Try to play one casino from the heap
        bool played = false;
        while (!pq.empty())
        {
            // Look at the casino with the highest reali
            auto top = pq.top();
            ll real = top.first;
            int j = top.second;
            pq.pop();

            // Skip if our coins exceed its ri (no longer enterable)
            if (cur > a[j][1])
                continue;

            // Skip if it doesn't improve our coins
            if (real <= cur)
                continue;

            // Play this casino: update coins and mark played
            cur = real;
            played = true;
            break;
        }

        // If no casino was playable to improve our coins, stop
        if (!played)
            break;
    }

    // cur now holds the maximum coins achievable
    cout << cur << nl;
}
/*
You are given n
 casinos, numbered from 1
 to n
. Each casino is described by three integers: li
, ri
, and reali
 (li≤reali≤ri
). You initially have k
 coins.

You can play at casino i
 only if the current number of coins x
 satisfies li≤x≤ri
. After playing, your number of coins becomes reali
.

You can visit the casinos in any order and are not required to visit all of them. Each casino can be visited no more than once.

Your task is to find the maximum final number of coins you can obtain.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤105
, 0≤k≤109
) — the number of casinos and the initial number of coins.

This is followed by n
 lines. In the i
-th line, there are three integers li
, ri
, reali
 (0≤li≤reali≤ri≤109
) — the parameters of the i
-th casino.

It is guaranteed that the sum of all n
 across all test cases does not exceed 105
.

Output
For each test case, output a single integer — the maximum number of coins you can obtain after optimally choosing the order of visiting the casinos.

Example
InputCopy
5
3 1
2 3 3
1 2 2
3 10 10
1 0
1 2 2
1 2
1 2 2
2 2
1 3 2
2 4 4
2 5
1 10 5
3 6 5
OutputCopy
10
0
2
4
5
Note
In the first test case, you can first play at the 2
-nd casino. After that, you will have 2
 coins. Then you can play at the 1
-st casino, and the number of coins will increase to 3
. Finally, after playing at the 3
-rd casino, you will have 10
 coins — this is the maximum possible amount.

In the second test case, you have no money, so you cannot earn more.

In the fourth test case, it is beneficial to play at the 2
-nd casino right away and earn 4
 coins.
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
