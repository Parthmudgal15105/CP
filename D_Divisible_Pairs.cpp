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
    ll n, x, y;
    cin >> n >> x >> y; // Read n, x, y
    vector<ll> v(n);    // Initialize vector v of size n
    for (ll i = 0; i < n; i++)
        cin >> v[i]; // Read array elements into v

    map<ll, map<ll, ll>> mp; // Map to store frequency of remainders
    ll ans = 0;              // Initialize answer to 0

    for (int i = 0; i < n; i++)
    {
        // Calculate the number of beautiful pairs
        ans += mp[(x - v[i] % x) % x][v[i] % y];
        // Update the frequency map
        mp[v[i] % x][v[i] % y]++;
    }
    cout << ans << "\n"; // Output the result
}

/*
Polycarp has two favorite integers x
 and y
 (they can be equal), and he has found an array a
 of length n
.

Polycarp considers a pair of indices ⟨i,j⟩
 (1≤i<j≤n
) beautiful if:

ai+aj
 is divisible by x
;
ai−aj
 is divisible by y
.
For example, if x=5
, y=2
, n=6
, a=
[1,2,7,4,9,6
], then the only beautiful pairs are:

⟨1,5⟩
: a1+a5=1+9=10
 (10
 is divisible by 5
) and a1−a5=1−9=−8
 (−8
 is divisible by 2
);
⟨4,6⟩
: a4+a6=4+6=10
 (10
 is divisible by 5
) and a4−a6=4−6=−2
 (−2
 is divisible by 2
).
Find the number of beautiful pairs in the array a
.
Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains three integers n
, x
, and y
 (2≤n≤2⋅105
, 1≤x,y≤109
) — the size of the array and Polycarp's favorite integers.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of beautiful pairs in the array a
.

Example
InputCopy
7
6 5 2
1 2 7 4 9 6
7 9 5
1 10 15 3 8 12 15
9 4 10
14 10 2 2 11 11 13 5 6
9 5 6
10 7 6 7 9 7 7 10 10
9 6 2
4 9 7 1 2 2 13 3 15
9 2 3
14 6 1 15 12 15 8 2 15
10 5 7
13 3 3 2 12 11 3 7 13 14
OutputCopy
2
0
1
3
5
7
0
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; // Read number of test cases
    while (t--)
        solve(); // Solve each test case
}
