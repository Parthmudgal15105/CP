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

// can(mid, n, a, b2):
//   Determines whether it is possible to pair each appetizer a[i] with a main dish
//   (using some circular shift of sorted b) so that every |a[i] − b_j| ≥ mid.
//   We extend b into b2 of length 2n so that shifting is just choosing a start index k.
//   For each k in [0..n−1], we check all i in [0..n−1], and if all differences ≥ mid,
//   we succeed.
bool can(int mid, int n, const vi &a, const vi &b2)
{
    for (int k = 0; k < n; k++)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (abs(a[i] - b2[k + i]) < mid)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

// solve():
//   We binary‐search the maximum minimum charm value ans.
//   low/high bounds on possible charm; mid tested via can(mid, …).
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    // build extended b2 of size 2n for circular shifts
    vi b2(2 * n);
    for (int i = 0; i < n; i++)
    {
        b2[i] = b[i];
        b2[i + n] = b[i];
    }

    int low = 0, high = 1000000001, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (can(mid, n, a, b2))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << nl;
}

/*
The Czech cuisine features n
 appetizers and n
 main dishes. The i
-th appetizer has spiciness ai
, and the i
-th main dish has spiciness bi
.

A typical Czech meal consists of exactly one appetizer and one main dish. You want to pair up the n
 appetizers and n
 main dishes into n
 meals with each appetizer and each main dish being included in exactly one meal.

Your meals shall surprise the diners, so you want the spiciness levels of the two parts of the same meal to be as different as possible. The charm of a meal is the difference (in absolute value) between the spiciness of the appetizer and the spiciness of the main dish. So, a meal consisting of an appetizer with spiciness x
 and a main dish with spiciness y
 has charm equal to |x−y|
.

You want to maximize the minimum charm of the resulting n
 meals. What is the largest possible value of the minimum charm that you can achieve?

Input
Each test contains multiple test cases. The first line contains an integer t
 (1≤t≤1000
) — the number of test cases. The descriptions of the t
 test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤5000
) —the number of appetizers and main dishes.

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai≤109
) — the spicinesses of the n
 appetizers.

The third line of each test case contains n
 integers b1,b2,…,bn
 (0≤bi≤109
) — the spicinesses of the n
 main dishes.

It is guaranteed that the sum of n2
 over all test cases does not exceed 25⋅106
.

Output
For each test case, print the largest possible value of the minimum charm you can achieve.

Example
InputCopy
4
3
0 0 0
1000000000 1000000000 1000000000
5
1 2 3 4 5
1 2 3 4 5
6
0 0 0 100 100 100
100 100 100 0 0 0
7
14 25 62 74 86 95 12
51 62 71 72 92 20 84
OutputCopy
1000000000
2
100
30
Note
In the first test case, no matter how you pair up the appetizers with the main dishes, each meal will have an appetizer with spiciness 0
 and a main dish with spiciness 1000000000
, so the charm of each meal will be 1000000000
.

In the second test case, one optimal way to pair up appetizers and main dishes is: (1,5)
, (2,4)
, (3,1)
, (4,2)
, (5,3)
. The corresponding meals have charms: 4
, 2
, 2
, 2
, 2
. The resulting minimum charm is 2
.

In the third test case, one way to maximize the minimum charm is to pair up the three appetizers with spiciness 0
 with the three main dishes with spiciness 100
, and the three appetizers with spiciness 100
 with the three main dishes with spiciness 0
. Doing so, the charm of each meal will be exactly 100
.
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
