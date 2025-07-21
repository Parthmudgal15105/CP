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

    vi pref(n), sufMax(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = min(pref[i - 1], a[i]);
    }
    sufMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufMax[i] = max(sufMax[i + 1], a[i]);
    }

    string res(n, '0');
    for (int i = 0; i < n; i++)
        if (a[i] == pref[i] || a[i] == sufMax[i])
        {
            res[i] = '1';
        }

    cout << res << nl;
}

/*
You are given an array a
 of distinct integers.

In one operation, you may either:

choose a nonempty prefix∗
 of a
 and replace it with its minimum value, or
choose a nonempty suffix†
 of a
 and replace it with its maximum value.
Note that you may choose the entire array a
.

For each element ai
, determine if there exists some sequence of operations to transform a
 into [ai]
; that is, make the array a
 consist of only one element, which is ai
. Output your answer as a binary string of length n
, where the i
-th character is 1
 if there exists a sequence to transform a
 into [ai]
, and 0
 otherwise.

∗
A prefix of an array is a subarray consisting of the first k
 elements of the array, for some integer k
.

†
A suffix of an array is a subarray consisting of the last k
 elements of the array, for some integer k
.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains one integer n
 (2≤n≤2⋅105
) — the size of the array a
.

The second line of each test case contains n
 integers, a1,a2,…,an
 (1≤ai≤106
). It is guaranteed that all ai
 are distinct.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a binary string of length n
  — the i
-th character should be 1
 if there exists a sequence of operations as described above, and 0
 otherwise.

Example
InputCopy
3
6
1 3 5 4 7 2
4
13 10 12 20
7
1 2 3 4 5 6 7
OutputCopy
100011
1101
1000001
Note
In the first sample, you can first choose the prefix of size 3
. Then the array is transformed into

1	4	7	2
Next, you can choose the suffix of size 2
. Then the array is transformed into
1	4	7
Finally, you can choose the prefix of size 3
. Then the array is transformed into
1
So we see that it is possible to transform a
 into [1]
.
It can be shown that it is impossible to transform a
 into [3]
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
