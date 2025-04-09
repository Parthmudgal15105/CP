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
    ll n, m, k;
    cin >> n >> m >> k;
    // Read total rows (n), columns (m), and participants (k)

    // Binary search bounds:
    // l: lower bound (minimum bench length); h: upper bound (cannot exceed min(m, k))
    ll l = 1, h = min(m, k), ans = h;

    // Compute target desks per row (ensuring each row can seat participants)
    // Uses ceiling division: equivalent to ceil(k / n)
    ll target = (k + n - 1) / n;

    // Binary search for the minimum bench length that can seat target desks per row
    while (l <= h)
    {
        ll mid = (l + h) / 2; // Candidate bench length
        // Calculate maximum desks in a row given bench length mid:
        // (m / (mid+1)) gives number of full benches, each contributing mid desks,
        // plus remaining desks: min(m % (mid+1), mid)
        ll desks = (m / (mid + 1)) * mid + min(m % (mid + 1), mid);

        // If current candidate allows seating at least target desks, try shorter bench length
        if (desks >= target)
        {
            ans = mid;
            h = mid - 1;
        }
        else // Otherwise, need a longer bench to seat enough desks
        {
            l = mid + 1;
        }
    }
    cout << ans << "\n"; // Output the minimum bench length required
}

/*
For the final of the first Olympiad by IT Campus "NEIMARK", a rectangular venue was prepared. You may assume that the venue is divided into n
 rows, each containing m
 spots for participants' desks. A total of k
 participants have registered for the final, and each participant will sit at an individual desk. Now, the organizing committee must choose the locations for the desks in the venue.

Each desk occupies one of the m
 spots in a row. Moreover, if several desks occupy consecutive spots in the same row, we call such a group of desks a bench, and the number of desks in the group is the bench's length. For example, seating 7
 participants on a 3×4
 venue (with n=3,m=4
) can be arranged as follows:


In the figure above, the first row has one bench of length 3
, the second row has one bench of length 2
, and the third row has two benches of length 1
.

The organizing committee wants to choose the locations so that the length of the longest bench is as small as possible. In particular, the same 7
 desks can be arranged in a more optimal way, so that the lengths of all benches do not exceed 2
:


Given the integers n
, m
, and k
, determine the minimum possible length of the longest bench.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

A single line of each test case contains three positive integers — n
, m
, k
 (1≤n,m,k≤109
, k≤n⋅m
).

Output
For each test case, output a single number — the minimum possible length of the longest bench.

Example
InputCopy
5
3 4 7
5 5 5
1 13 2
2 4 7
1 5 4
OutputCopy
2
1
1
4
2
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
