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

void solve()
{
    int l[3], b[3];
    cin >> l[0] >> b[0] >> l[1] >> b[1] >> l[2] >> b[2];

    vector<int> idx = {0, 1, 2};
    do
    {
        int l1 = l[idx[0]], b1 = b[idx[0]];
        int l2 = l[idx[1]], b2 = b[idx[1]];
        int l3 = l[idx[2]], b3 = b[idx[2]];

        // 1. All in a row horizontally (same height, sum of widths == height)
        if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1)
        {
            cyes;
            return;
        }
        // 2. All in a column vertically (same width, sum of heights == width)
        if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1)
        {
            cyes;
            return;
        }
        // 3. L-shape: two side by side, third fills below
        // Place l1 x b1 and l2 x b2 side by side, l3 x b3 below
        int side = max(l1 + l2, l3);
        if (b1 == b2 && l1 + l2 == side && b1 + b3 == side && l3 == side && b3 == side - b1)
        {
            cyes;
            return;
        }
        // Another L-shape variant: two stacked, third fills right
        side = max(b1 + b2, b3);
        if (l1 == l2 && b1 + b2 == side && l1 + l3 == side && b3 == side && l3 == side - l1)
        {
            cyes;
            return;
        }
        // General L-shape: two on top, one below, all together form a square
        if (b1 == b2 && l1 + l2 == l3 && b1 + b3 == l3)
        {
            cyes;
            return;
        }
        // General L-shape: two on left, one on right, all together form a square
        if (l1 == l2 && b1 + b2 == b3 && l1 + l3 == b3)
        {
            cyes;
            return;
        }
    } while (next_permutation(idx.begin(), idx.end()));

    cno;
}

/*
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
