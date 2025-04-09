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
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> idx;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            idx.push_back(i);
    }

    if (idx.empty())
    {
        cout << 1 << nl;
        cout << 1 << sp << n << nl;
    }
    else if (idx.size() == 1)
    {
        if (idx.front() == n)
        {
            cout << 2 << nl;
            cout << n - 1 << sp << n << nl;
            cout << 1 << sp << n - 1 << nl;
        }
        else if (idx.front() == 1)
        {
            cout << 2 << nl;
            cout << 1 << sp << 2 << nl;
            cout << 1 << sp << n - 1 << nl;
        }
        else
        {
            cout << 2 << nl;
            cout << 1 << sp << idx.front() << nl;
            cout << 1 << sp << n - idx.front() + 1 << nl;
        }
    }
    else if (idx.size() == n || (a[1] == 0 && a[n] == 0))
    {
        cout << 3 << nl;
        cout << 1 << sp << n / 2 << nl;
        cout << 2 << sp << n - (n / 2) + 1 << nl;
        cout << 1 << sp << 2 << nl;
    }
    else if (a[1] == 0)
    {
        cout << 2 << nl;
        cout << 1 << sp << idx.back() << nl;
        cout << 1 << sp << n - idx.back() + 1 << nl;
    }
    else if (a[n] == 0)
    {
        cout << 2 << nl;
        cout << idx.front() << sp << idx.back() << nl;
        cout << 1 << sp << n - (idx.back() - idx.front()) << nl;
    }
    else
    {
        cout << 2 << nl;
        cout << idx.front() << sp << idx.back() << nl;
        cout << 1 << sp << n - (idx.back() - idx.front()) << nl;
    }
}

/*
You are given an array a
 consisting of n≥4
 non-negative integers.

You need to perform the following operation on a
 until its length becomes 1
:

Select two indices l
 and r
 (1≤l<r≤|a|
), and replace the subarray [al,al+1,…,ar]
 with a single integer mex([al,al+1,…,ar])
, where mex(b)
 denotes the minimum excluded (MEX)∗
 of the integers in b
. In other words, let x=mex([al,al+1,…,ar])
, the array a
 will become [a1,a2,…,al−1,x,ar+1,ar+2,…,a|a|]
. Note that the length of a
 decreases by (r−l)
 after this operation.
Serval wants the final element in a
 to be 0
. Help him!

More formally, you have to find a sequence of operations, such that after performing these operations in order, the length of a
 becomes 1
, and the final element in a
 is 0
.

It can be shown that at least one valid operation sequence exists under the constraints of the problem, and the length of any valid operation sequence does not exceed n
.

Note that you do not need to minimize the number of operations.

∗
The minimum excluded (MEX) of a collection of integers b1,b2,…,bk
 is defined as the smallest non-negative integer x
 which does not occur in the collection b
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (4≤n≤5000
) — the length of the array a
.

The second line contains n
 integers a1,a2,…,an
 (0≤ai≤n
) — the elements of the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, output a single integer k
 (0≤k≤n
) in the first line of output — the length of the operation sequence.

Then, output k
 lines, the i
-th line containing two integers li
 and ri
 (1≤li<ri≤|a|
) — the two indices you choose in the i
-th operation, where |a|
 denotes the length of the array before this operation.

If there are multiple answers, you may print any of them.

Example
InputCopy
6
4
1 2 3 4
5
0 1 0 0 1
6
0 0 0 0 0 0
6
5 4 3 2 1 0
4
0 0 1 1
4
1 0 0 0
OutputCopy
1
1 4
4
1 2
1 2
1 2
1 2
4
5 6
3 4
1 2
1 3
3
4 5
4 5
1 4
2
1 2
1 3
2
2 4
1 2
Note
In the first test case, since mex([1,2,3,4])=0
, after the only operation, the array becomes [0]
.

In the second test case, the array a
 changes as follows:
[0,1––––,0,0,1]→[2,0––––,0,1]→[1,0––––,1]→[2,1––––]→[0].

In the third test case, the array a
 changes as follows:
[0,0,0,0,0,0––––]→[0,0,0,0––––,1]→[0,0––––,1,1]→[1,1,1––––––]→[0].
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