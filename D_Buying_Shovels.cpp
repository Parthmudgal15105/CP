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

/*----------------------------------------------------------------------------*/
void solve()
{
    long long n, k;
    cin >> n >> k;
    long long ans = n;

    // find the best divisor up to k
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= k)
                ans = min(ans, n / i);
            if (n / i <= k)
                ans = min(ans, i);
        }
    }

    cout << ans << nl;
}

/*
Polycarp wants to buy exactly n
 shovels. The shop sells packages with shovels. The store has k
 types of packages: the package of the i
-th type consists of exactly i
 shovels (1≤i≤k
). The store has an infinite number of packages of each type.

Polycarp wants to choose one type of packages and then buy several (one or more) packages of this type. What is the smallest number of packages Polycarp will have to buy to get exactly n
 shovels?

For example, if n=8
 and k=7
, then Polycarp will buy 2
 packages of 4
 shovels.

Help Polycarp find the minimum number of packages that he needs to buy, given that he:

will buy exactly n
 shovels in total;
the sizes of all packages he will buy are all the same and the number of shovels in each package is an integer from 1
 to k
, inclusive.
Input
The first line contains an integer t
 (1≤t≤100
) — the number of test cases in the input. Then, t
 test cases follow, one per line.

Each test case consists of two positive integers n
 (1≤n≤109
) and k
 (1≤k≤109
) — the number of shovels and the number of types of packages.

Output
Print t
 answers to the test cases. Each answer is a positive integer — the minimum number of packages.
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
