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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vi best(n);
    best[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        best[i] = max(best[i - 1], a[i]);
    }

    vll suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + a[i];
    }

    vector<ll> ans(n);

    ans[0] = best[n - 1];
    for (int k = 2; k <= n; k++)
    {
        ll cand1 = -LLONG_MAX;
        if (n - k - 1 >= 0)
        {
            ll temp = best[n - k - 1];
            if (n - k + 1 < n)
            {
                temp += suff[n - k + 1];
            }
            cand1 = temp;
        }
        ll cand2 = suff[n - k];
        ans[k - 1] = max(cand1, cand2);
    }
    for (auto x : ans)
        cout << x << sp;
    cout << nl;
}

/*
You are given an array a
 consisting of n
 integers.

For every integer k
 from 1
 to n
, you have to do the following:

choose an arbitrary element of a
 and move it to the right end of the array (you can choose the last element, then the array won't change);
print the sum of k
 last elements of a
;
move the element you've chosen on the first step to its original position (restore the original array a
).
For every k
, you choose the element which you move so that the value you print is the maximum possible.

Calculate the value you print for every k
.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer n
 (1≤n≤2⋅105
);
the second line contains n
 integers a1,a2,…,an
 (1≤ai≤109
).
Additional constraint on the input: the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print n
 integers. The i
-th of these integers should be equal to the maximum value you can print if k=i
.

Example
InputCopy
4
7
13 5 10 14 8 15 13
6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1
42
2
7 5
OutputCopy
15 28 42 50 63 73 78
1000000000 2000000000 3000000000 4000000000 5000000000 6000000000
42
7 12
Note
Let's consider the first test case from the statement:

when k=1
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 15
;
when k=2
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 13+15=28
;
when k=3
, you can move the 4
-th element to the end, the array becomes [13,5,10,8,15,13,14]
, and the value you print is 15+13+14=42
;
when k=4
, you can move the 5
-th element to the end, the array becomes [13,5,10,14,15,13,8]
, and the value you print is 14+15+13+8=50
;
when k=5
, you can move the 1
-st element to the end, the array becomes [5,10,14,8,15,13,13]
, and the value you print is 14+8+15+13+13=63
;
when k=6
, you can move the 1
-st element to the end, the array becomes [5,10,14,8,15,13,13]
, and the value you print is 10+14+8+15+13+13=73
;
when k=7
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 13+5+10+14+8+13+15=78
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
