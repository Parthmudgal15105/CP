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

// Function to solve the problem for a single test case
void solve()
{
    int n; // Number of elements in the array
    cin >> n;
    vi a(n); // Input array

    // Reading the array elements
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int last = -1;     // Tracks the last index where a[i] != a[0]
    int ans = INT_MAX; // Stores the minimum gap between such indices

    // Iterate through the array to find gaps between differing elements
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[0]) // Check if the current element differs from the first element
        {
            ans = min(ans, i - last); // Update the minimum gap
            last = i;                 // Update the last differing index
        }
    }

    // Consider the gap from the last differing index to the end of the array
    ans = min(ans, n - last);

    // If the minimum gap is greater than or equal to the array size, output -1
    if (ans >= n)
    {
        cout << -1 << nl;
    }
    else
    {
        cout << ans - 1 << nl; // Output the minimum number of elements to remove
    }
}

/*
Let's call an array a
 beautiful if you can make all its elements the same by using the following operation an arbitrary number of times (possibly, zero):

choose an index i
 (2≤i≤|a|−1
) such that ai−1=ai+1
, and replace ai
 with ai−1
.
You are given a beautiful array a1,a2,…,an
. What is the minimum number of elements you have to remove from it in order for it to stop being beautiful? Swapping elements is prohibited. If it is impossible to do so, then output -1.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤3⋅105
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
).

Additional constraints on the input:

in every test case, the given array a
 is beautiful;
the sum of n
 over all test cases does not exceed 3⋅105
.
Output
For each test case, output a single integer — the minimum number of elements you have to remove from the array a
 in order for it to stop being beautiful. If it is impossible, then output -1.

Example
InputCopy
4
3
2 2 2
5
1 2 1 2 1
1
1
7
3 3 3 5 3 3 3
OutputCopy
-1
1
-1
3
Note
In the first testcase, it is impossible to modify the array in such a way that it stops being beautiful. An array consisting of identical numbers will remain beautiful no matter how many numbers we remove from it.

In the second testcase, you can remove the number at the index 5
, for example.

The resulting array will be [1,2,1,2]
. Let's check if it is beautiful. Two operations are available:

Choose i=2
: the array becomes [1,1,1,2]
. No more operations can be applied to it, and the numbers are not all the same.
Choose i=3
 instead: the array becomes [1,2,2,2]
. No more operations can be applied to it either, and the numbers are still not all the same.
Thus, the array [1,2,1,2]
 is not beautiful.

In the fourth testcase, you can remove the first three elements, for example. The resulting array [5,3,3,3]
 is not beautiful.
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
