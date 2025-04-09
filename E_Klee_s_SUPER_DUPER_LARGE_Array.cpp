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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
long long getSum(long long l, long long r)
{
    return (r * (r + 1) / 2) - ((l - 1) * l / 2);
}
void solve()
{
    long long n, k;
    cin >> n >> k;

    long long left = k, right = k + n - 1, mid, sum1, sum2;
    long long answer = LLONG_MAX;

    while (left <= right)
    {
        mid = (left + right) / 2;
        sum1 = getSum(k, mid);
        sum2 = getSum(mid + 1, k + n - 1);
        answer = min(answer, abs(sum1 - sum2));
        if (sum1 > sum2)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << answer << "\n";
}

/*
Klee has an array a
 of length n
 containing integers [k,k+1,...,k+n−1]
 in that order. Klee wants to choose an index i
 (1≤i≤n
) such that x=|a1+a2+⋯+ai−ai+1−⋯−an|
 is minimized. Note that for an arbitrary integer z
, |z|
 represents the absolute value of z
.

Output the minimum possible value of x
.

Input
The first line contains t
 (1≤t≤104
) — the number of test cases.

Each test case contains two integers n
 and k
 (2≤n,k≤109
) — the length of the array and the starting element of the array.

Output
For each test case, output the minimum value of x
 on a new line.

Example
InputCopy
4
2 2
7 2
5 3
1000000000 1000000000
OutputCopy
1
5
1
347369930
Note
In the first sample, a=[2,3]
. When i=1
 is chosen, x=|2−3|=1
. It can be shown this is the minimum possible value of x
.

In the third sample, a=[3,4,5,6,7]
. When i=3
 is chosen, x=|3+4+5−6−7|=1
. It can be shown this is the minimum possible value of x
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
