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
/*
Explanation of the solution:

1. **Observation**:
   For each operation, the interval changed by a and b is complementary.
   The only way to solve the problem is if all positions are either a[i] == b[i] for all i, or a[i] != b[i] for all i.

2. **isEqual**:
   - If a[0] == b[0], then all a[i] == b[i] must hold for all i.
   - If a[0] != b[0], then all a[i] != b[i] must hold for all i.
   - If not, print "NO" and return.

3. **Making all zero**:
   - For each position where a[i] == '1', flip it (operation on (i+1, i+1)), and toggle isEqual.
   - After all flips, if isEqual is false, perform three extra operations to fix the parity:
     (1,1), (2,n), (1,n).

4. **Output**:
   - Print "YES" and the list of operations.

This approach guarantees at most n+5 operations and is efficient for the given constraints.
*/

void solve()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<pair<ll, ll>> ans;
    ll isEqual = (a[0] == b[0]);
    bool possible = true;

    for (ll i = 0; i < n; i++)
    {
        if ((a[i] == b[i]) != isEqual)
        {
            cno;
            return;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            ans.push_back({i + 1, i + 1});
            isEqual ^= 1;
        }
    }

    if (!isEqual)
    {
        ans.push_back({1, 1});
        ans.push_back({2, n});
        ans.push_back({1, n});
    }

    cyes;
    cout << ans.size() << nl;
    for (auto x : ans)
    {
        cout << x.first << sp << x.second << nl;
    }
}

/*
You have two binary strings a
 and b
 of length n
. You would like to make all the elements of both strings equal to 0
. Unfortunately, you can modify the contents of these strings using only the following operation:

You choose two indices l
 and r
 (1≤l≤r≤n
);
For every i
 that respects l≤i≤r
, change ai
 to the opposite. That is, ai:=1−ai
;
For every i
 that respects either 1≤i<l
 or r<i≤n
, change bi
 to the opposite. That is, bi:=1−bi
.
Your task is to determine if this is possible, and if it is, to find such an appropriate chain of operations. The number of operations should not exceed n+5
. It can be proven that if such chain of operations exists, one exists with at most n+5
 operations.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤105
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) — the length of the strings.

The second line of each test case contains a binary string a
, consisting only of characters 0 and 1, of length n
.

The third line of each test case contains a binary string b
, consisting only of characters 0 and 1, of length n
.

It is guaranteed that sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each testcase, print first "YES" if it's possible to make all the elements of both strings equal to 0
. Otherwise, print "NO". If the answer is "YES", on the next line print a single integer k
 (0≤k≤n+5
) — the number of operations. Then k
 lines follows, each contains two integers l
 and r
 (1≤l≤r≤n
) — the description of the operation.

If there are several correct answers, print any of them.

Example
InputCopy
5
3
010
101
2
11
10
4
1000
0011
2
10
10
3
111
111
OutputCopy
YES
1
2 2
NO
NO
YES
2
1 2
2 2
YES
2
1 1
2 3
Note
In the first test case, we can perform one operation with l=2
 and r=2
. So a2:=1−1=0
 and string a
 became equal to 000. b1:=1−1=0
, b3:=1−1=0
 and string b
 became equal to 000.

In the second and in the third test cases, it can be proven that it's impossible to make all elements of both strings equal to 0
.

In the fourth test case, we can perform an operation with l=1
 and r=2
, then string a
 became equal to 01, and string b
 doesn't change. Then we perform an operation with l=2
 and r=2
, then a2:=1−1=0
 and b1=1−1=0
. So both of string a
 and b
 became equal to 00.

In the fifth test case, we can perform an operation with l=1
 and r=1
. Then string a
 became equal to 011 and string b
 became equal to 100. Then we can perform an operation with l=2
 and r=3
, so both of string a
 and b
 became equal to 000.
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
