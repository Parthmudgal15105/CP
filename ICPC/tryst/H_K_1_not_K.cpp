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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    ans.reserve(2 * n);

    for (int i = 1; i <= k; i++)
        ans.push_back(i);
    for (int i = 1; i <= k; i++)
        ans.push_back(i);
    for (int i = k + 1; i <= n; i++)
    {
        ans.push_back(i);
        ans.push_back(i);
    }

    for (auto &x : ans)
        cout << x << " ";
    cout << "\n";
}

/*
You are given 2
 integers n
 and k
. You need to construct an array a
 of size 2n
 such that

Each integer from 1
 to n
 occurs exactly twice in the array.
Each k−
length subarray of a
 contains all distinct elements.
There exists a (k+1)−
length subarray of a
 that does not contain all distinct elements.
If there are multiple such arrays a
, you can output any of them. It can be proved that under the constraints of the problem, a solution always exists.
Input
The first line of the input contains t−
 the number of test-cases (1≤t≤105)
.

For each test-case,

The input consists of 2
 space-separated integers n
 and k−
 (1≤k≤n≤2⋅105)
.

It is guaranteed that the sum of n
 over all test-cases does not exceed 2⋅105
.

Output
For each test-case, output an array a
 of size 2n
 that satisfies the problem constraints.

Example
InputCopy
3
2 2
5 3
4 1
OutputCopy
1 2 1 2
1 2 3 4 1 5 4 2 3 5
1 1 2 2 3 3 4 4
Note
For the first test-case, no subarray of length 2
 contains a repeated element but [2,1,2]
 contains a repeated element 2
.

For the second test-case, no subarray of length 3
 contains a repeated element but [4,1,5,4]
 contains a repeated element 4
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
