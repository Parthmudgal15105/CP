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
int finder(int ans, vector<int> &a, int n)
{

    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            ans++;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // The logic should be corrected to match the problem description
    // We need to find the maximum number of arrays possible after removals

    // Dynamic programming approach: dp[i] = max number of arrays ending at index i
    vector<int> dp(n, 0);
    dp[0] = 1; // First element always starts a new array

    for (int i = 1; i < n; i++)
    {
        // If this element starts a new array (gap > 1)
        if (a[i] > a[i - 1] + 1)
        {
            dp[i] = dp[i - 1] + 1;
        }
        // Otherwise, it continues the current array
        else
        {
            dp[i] = dp[i - 1];
        }

        // Try removing this element to see if it creates more arrays
        for (int j = 0; j < i - 1; j++)
        {
            if (a[i] > a[j] + 1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n - 1] << nl;
}

/*
Given an array a
 and n
 integers. It is sorted in non-decreasing order, that is, ai≤ai+1
 for all 1≤i<n
.

You can remove any number of elements from the array (including the option of not removing any at all) without changing the order of the remaining elements. After the removals, the following will occur:

a1
 is written to a new array;
if a1+1<a2
, then a2
 is written to a new array; otherwise, a2
 is written to the same array as a1
;
if a2+1<a3
, then a3
 is written to a new array; otherwise, a3
 is written to the same array as a2
;
⋯
For example, if a=[1,2,4,6]
, then:

a1=1
 is written to the new array, resulting in arrays: [1]
;
a1+1=2
, so a2=2
 is added to the existing array, resulting in arrays: [1,2]
;
a2+1=3
, so a3=4
 is written to a new array, resulting in arrays: [1,2]
 and [4]
;
a3+1=5
, so a4=6
 is written to a new array, resulting in arrays: [1,2]
, [4]
, and [6]
.
Your task is to remove elements in such a way that the described algorithm creates as many arrays as possible. If you remove all elements from the array, no new arrays will be created.

Input
The first line of input contains one integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤106
, ai≤ai+1
) — the elements of the array.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the maximum number of arrays that can be obtained by removing any (possibly zero) number of elements.

Example
InputCopy
6
6
1 2 3 4 5 6
3
1 2 3
4
1 2 2 4
1
2
3
1 4 8
2
1 1
OutputCopy
3
2
2
1
3
1
Note
In the first example, you can remove a3
 and a5
, then a=[1,2,4,6]
, the process of forming arrays for it is shown in the statement.

In the second example, you need to remove a2
, after which a=[1,3]
, and the arrays [1]
 and [3]
 will be written.

In the third example, no removals are needed; for a=[1,2,2,4]
, the arrays [1,2,2]
 and [4]
 will be written.
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
