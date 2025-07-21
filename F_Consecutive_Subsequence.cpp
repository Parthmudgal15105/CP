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
    int n, len = 0, start = 0;
    map<int, int> dp; // dp[x]: length of longest consecutive subsequence ending at value x
    vi ans;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read the array
    }

    // Find the length and starting value of the longest consecutive subsequence
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        dp[x] = max(dp[x], 1);             // At least one (itself) if not seen before
        dp[x] = max(dp[x], dp[x - 1] + 1); // If x-1 exists, extend its subsequence
        if (dp[x] > len)
        {
            len = dp[x];           // Update max length found so far
            start = x - dp[x] + 1; // Calculate starting value of this subsequence
        }
    }

    // Reconstruct the answer: find indices of the subsequence in the original array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == start)
        {
            ans.push_back(i + 1); // Store 1-based index
            start++;              // Move to next expected value in the consecutive sequence
        }
    }

    // Output the results
    cout << len << nl; // Print the length of the subsequence
    for (auto it : ans)
    {
        cout << it << sp; // Print the indices of the subsequence
    }
    cout << nl;
}

/*
You are given an integer array of length n
.

You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of consecutive integers. In other words the required sequence should be equal to [x,x+1,…,x+k−1]
 for some value x
 and length k
.

Subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. You can erase any elements, not necessarily going successively. The remaining elements preserve their order. For example, for the array [5,3,1,2,4]
 the following arrays are subsequences: [3]
, [5,3,1,2,4]
, [5,1,4]
, but the array [1,3]
 is not.

Input
The first line of the input containing integer number n
 (1≤n≤2⋅105
) — the length of the array. The second line of the input containing n
 integer numbers a1,a2,…,an
 (1≤ai≤109
) — the array itself.

Output
On the first line print k
 — the maximum length of the subsequence of the given array that forms an increasing sequence of consecutive integers.

On the second line print the sequence of the indices of the any maximum length subsequence of the given array that forms an increasing sequence of consecutive integers.

Examples
InputCopy
7
3 3 4 7 5 6 8
OutputCopy
4
2 3 5 6
InputCopy
6
1 3 5 2 4 6
OutputCopy
2
1 4
InputCopy
4
10 9 8 7
OutputCopy
1
1
InputCopy
9
6 7 8 3 4 5 9 10 11
OutputCopy
6
1 2 3 7 8 9
Note
All valid answers for the first example (as sequences of indices):

[1,3,5,6]
[2,3,5,6]
All valid answers for the second example:

[1,4]
[2,5]
[3,6]
All valid answers for the third example:

[1]
[2]
[3]
[4]
All valid answers for the fourth example:

[1,2,3,7,8,9]


 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
