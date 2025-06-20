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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    // Check if the first operation's result is valid and divisible by (n+1)
    if (2 * a[0] - a[1] < 0 || (2 * a[0] - a[1]) % (n + 1) != 0)
    {
        cout << "NO\n";
        return;
    }

    // Calculate x2: number of times the second operation is applied
    ll x2 = (2 * a[0] - a[1]) / (n + 1);
    // Calculate x1: number of times the first operation is applied
    ll x1 = a[0] - n * x2;

    // If x1 is negative, it's impossible
    if (x1 < 0)
    {
        cout << "NO\n";
        return;
    }

    bool pos = true;

    // Check if for every index, the operations can reduce a[i] to zero
    for (ll i = 1; i <= n; i++)
    {
        // For each a[i-1], after x1 times op1 and x2 times op2, should become 0
        if (a[i - 1] - i * x1 - (n - i + 1) * x2 != 0)
            pos = false;
    }

    if (pos)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

/*
Yousef wants to explode an array a1,a2,…,an
. An array gets exploded when all of its elements become equal to zero.

In one operation, Yousef can do exactly one of the following:

For every index i
 in a
, decrease ai
 by i
.
For every index i
 in a
, decrease ai
 by n−i+1
.
Your task is to help Yousef determine if it is possible to explode the array using any number of operations.

Input
The first line of the input contains an integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains an integer n
 (2≤n≤2⋅105
) — the size of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print "YES" if Yousef can explode the array, otherwise output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
4
3 6 6 3
5
21 18 15 12 9
10
2 6 10 2 5 5 1 2 4 10
7
10 2 16 12 8 20 4
2
52 101
2
10 2
OutputCopy
NO
YES
NO
NO
YES
NO
Note
In the second test case, we can do the following:

Perform 1
 operation of the first type. The array becomes [20,16,12,8,4]
.
Perform 4
 operations of the second type. The array becomes [0,0,0,0,0]
.
In the first, third, fourth, and sixth test cases, it can be proven that it is impossible to make all elements equal to zero using any number of operations.
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
