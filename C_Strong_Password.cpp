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
#define N 300003
/*----------------------------------------------------------------------------*/
void solve()
{

    string s;
    cin >> s;
    int n = s.size();

    int m;
    cin >> m;

    string l1, r1;
    cin >> l1 >> r1;

    // 'cur' keeps track of our current position in the database string.
    int cur = -1;

    // For each digit position in the candidate password.
    for (int i = 0; i < m; i++)
    {
        // Move one step forward to consider the next position.
        cur++;
        // 'f' tracks which digits have been encountered in the current scanning.
        bool f[10] = {0};

        // 'cn' counts unique allowed digits found so far.
        int cn = 0;
        int l = (int)l1[i] - '0'; // lower bound allowed digit at position i.
        int r = (int)r1[i] - '0'; // upper bound allowed digit at position i.
        // Explanation:
        // For current digit i, allowed candidates are digits in [l, r].

        // Scan the database string until all allowed candidates have been seen
        // or until we run out of characters.
        while (cur < n)
        {
            int x = (int)s[cur] - '0';
            if (!f[x])
            {
                f[x] = 1;
                // If the encountered digit is within allowed bounds, count it.
                if (x <= r && x >= l)
                    cn++;
            }
            // When we have seen all digits in the range [l, r],
            // it means for this position every allowed digit appears in s.
            if (cn == r - l + 1)
                break;
            cur++;
        }
        // Explanation:
        // If the while loop breaks because all allowed digits were found,
        // then any candidate digit choice for this position appears as a subsequence.
        // If s is exhausted before seeing all, then there is at least one allowed digit
        // that does not appear, meaning a valid password can be chosen.
    }

    // Final decision: if we reached or passed the end of s,
    // then for at least one position not all allowed digits were present.
    // So, a password candidate exists that does not appear as a subsequence.
    if (cur >= n)
        cout << "YES\n";
    else
        cout << "NO\n";
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
