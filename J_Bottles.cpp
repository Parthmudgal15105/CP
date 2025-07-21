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
vector<vector<vector<int>>> memo;

int dp_solve(int i, int j, int k, const vi &cap, const vi &rem, int n, int res)
{
    if (j == 0 && k <= 0)
        return 0; // picked enough bottles and capacity requirement met
    if (i == 0)
        return -1; // no bottles left
    if (memo[i][j][k] != -2)
        return memo[i][j][k];

    int ans = -1;
    // Option 1: skip current bottle
    ans = dp_solve(i - 1, j, k, cap, rem, n, res);

    // Option 2: pick current bottle if possible
    if (j > 0 && k - cap[i] >= 0)
    {
        int take = dp_solve(i - 1, j - 1, k - cap[i], cap, rem, n, res);
        if (take != -1)
            ans = max(ans, take + rem[i]);
    }
    return memo[i][j][k] = ans;
}
bool cmp(vi &f, vi &s)
{
    return f[1] > s[1]; // in decreasing order of their capacities
}
void solve()
{
    int n;
    cin >> n;

    vvi a(n + 1, vi(2));

    vi rem(n + 1), cap(n + 1);
    int S = 0, res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0];
        S += a[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1];
        res += a[i][1];
    }

    vvi dp(n + 1, vi(res + 1, -1)); // 2D DP table of size n + 1 by res + 1 (corresponding to j and k in the 3D DP state)

    // Part 1 Begins
    sort(a.begin() + 1, a.end(), cmp);

    for (int i = 1; i <= n; i++)
        rem[i] = a[i][0], cap[i] = a[i][1];

    int cnt = 0, runningSum = 0; // cnt is k
    for (int i = 1; i <= n; i++)
    {
        runningSum += a[i][1];
        if (runningSum >= S)
        {
            cnt = i; // k = i then break
            break;
        }
    }

    // Part 1 Ends

    // We found the min # of bottles using the greedy above
    // Now dp[i][j][k] is the max sum of remaining soda if we choose j bottles
    // from the first i bottles with sum of capacities >= k

    dp[0][0] = 0; // Base case : dp[i][0][0] = 0 for all i

    for (int i = 1; i <= n; i++)
    {

        for (int j = cnt; j >= 1; j--)
        {

            for (int k = res; k >= cap[i]; k--)
            { // this order matters because we are overwriting dp[i - 1][j][k] with dp[i][j][k]

                if (dp[j - 1][k - cap[i]] != -1)
                { // dp[i - 1][j - 1][k - cap[i]] is not invalid
                    // By invalid I mean j bottles can be taken with sum of capacities >= k
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - cap[i]] + rem[i]);
                }
            }
        }
    }
    int mx = 0;
    int k = cnt;

    for (int i = S; i <= res; i++) // i is the sum of capacities (i loops over all valid sum of capacities)
        mx = max(mx, dp[k][i]);    //-1 is invalid and is < 0 hence mx will never contain an invalid possibility

    cout << k << " " << S - mx;
}

void solveMem()
{
    int n;
    cin >> n;

    vvi a(n + 1, vi(2));
    vi rem(n + 1), cap(n + 1);
    int S = 0, res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0];
        S += a[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1];
        res += a[i][1];
    }

    sort(a.begin() + 1, a.end(), cmp);

    for (int i = 1; i <= n; i++)
        rem[i] = a[i][0], cap[i] = a[i][1];

    int cnt = 0, runningSum = 0;
    for (int i = 1; i <= n; i++)
    {
        runningSum += a[i][1];
        if (runningSum >= S)
        {
            cnt = i;
            break;
        }
    }
    memo.assign(n + 1, vector<vector<int>>(cnt + 1, vector<int>(res + 1, -2)));

    int mx = -1;
    for (int i = S; i <= res; i++)
    {
        int val = dp_solve(n, cnt, i, cap, rem, n, res);
        if (val != -1)
            mx = max(mx, val);
    }

    cout << cnt << sp << S - mx;
}

/*
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solveMem();
}
