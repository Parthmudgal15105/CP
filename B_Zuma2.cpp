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

int n;
vi a;
vector<vector<int>> dp;

int f(int i, int j)
{
    if (i > j)
        return 0; // empty segment
    if (i == j)
        return 1; // single element
    int &res = dp[i][j];
    if (res != -1)
        return res;
    // Default: remove a[i] in one move, then solve for [i+1, j]
    res = 1 + f(i + 1, j);
    // If first two elements are equal, can remove both together as a palindrome
    if (i + 1 <= j && a[i] == a[i + 1])
        res = min(res, 1 + f(i + 2, j));
    // Try to find any k > i+1 such that a[i] == a[k]
    for (int k = i + 2; k <= j; k++)
    {
        if (a[i] == a[k])
        {
            // Remove [i+1, k-1] and [k+1, j], then remove a[i] and a[k] together
            res = min(res, f(i + 1, k - 1) + f(k + 1, j));
        }
    }
    return res;
}

void solve()
{
    cin >> n;
    a = vi(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp = vector<vector<int>>(n + 2, vi(n + 2, -1));
    cout << f(1, n) << nl;
}

/*
Genos recently installed the game Zuma on his phone. In Zuma there exists a line of n gemstones, the i-th of which has color ci. The goal of the game is to destroy all the gemstones in the line as quickly as possible.

In one second, Genos is able to choose exactly one continuous substring of colored gemstones that is a palindrome and remove it from the line. After the substring is removed, the remaining gemstones shift to form a solid line again. What is the minimum number of seconds needed to destroy the entire line?

Let us remind, that the string (or substring) is called palindrome, if it reads same backwards or forward. In our case this means the color of the first gemstone is equal to the color of the last one, the color of the second gemstone is equal to the color of the next to last and so on.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 500) — the number of gemstones.

The second line contains n space-separated integers, the i-th of which is ci (1 ≤ ci ≤ n) — the color of the i-th gemstone in a line.

Output
Print a single integer — the minimum number of seconds needed to destroy the entire line.

Examples
InputCopy
3
1 2 1
OutputCopy
1
InputCopy
3
1 2 3
OutputCopy
3
InputCopy
7
1 4 4 2 3 2 1
OutputCopy
2
Note
In the first sample, Genos can destroy the entire line in one second.

In the second sample, Genos can only destroy one gemstone at a time, so destroying three gemstones takes three seconds.

In the third sample, to achieve the optimal time of two seconds, destroy palindrome 4 4 first and then destroy palindrome 1 2 3 2 1.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
