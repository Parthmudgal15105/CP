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

    // The key observation:
    // After every swap, the parity (even/odd index) of the positions of swapped elements changes.
    // To have all directions right at the end, each element must be swapped an even number of times.
    // So, for each value, the multiset of values at even indices and odd indices must match in the sorted array and the original array.

    // Make a copy of the original array and sort it to get the target arrangement
    vi b = a;
    sort(b.begin(), b.end());

    // Count frequency of each value at even and odd indices for both arrays
    // freq_a[x] will store a vector of parities (0 for even, 1 for odd) where value x appears in the original array
    // freq_b[x] will store a vector of parities where value x appears in the sorted array
    map<int, vector<int>> freq_a, freq_b;
    for (int i = 0; i < n; ++i)
    {
        freq_a[a[i]].push_back(i % 2); // record parity for original array
        freq_b[b[i]].push_back(i % 2); // record parity for sorted array
    }

    // Now, for each value, compare the sorted list of parities in original and sorted arrays
    // If for any value, the parities don't match, it's impossible to achieve the sorted array with all directions right
    bool ok = true;
    for (auto &pr : freq_a)
    {
        int val = pr.first;
        vector<int> &va = pr.second;   // parities in original array
        vector<int> &vb = freq_b[val]; // parities in sorted array
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        if (va != vb)
        {
            // If the parity distributions don't match, answer is NO
            ok = false;
            break;
        }
    }

    // Output result for this test case
    if (ok)
        cyes;
    else
        cno;
}

/*
AquaMoon has n
 friends. They stand in a row from left to right, and the i
-th friend from the left wears a T-shirt with a number ai
 written on it. Each friend has a direction (left or right). In the beginning, the direction of each friend is right.

AquaMoon can make some operations on friends. On each operation, AquaMoon can choose two adjacent friends and swap their positions. After each operation, the direction of both chosen friends will also be flipped: left to right and vice versa.

AquaMoon hopes that after some operations, the numbers written on the T-shirt of n
 friends in the row, read from left to right, become non-decreasing. Also she wants, that all friends will have a direction of right at the end. Please find if it is possible.

Input
The input consists of multiple test cases. The first line contains a single integer t
 (1≤t≤50
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤105
) — the number of Aquamoon's friends.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤105
) — the numbers, written on the T-shirts.

It is guaranteed that the sum of n
 for all test cases does not exceed 105
.

Output
For each test case, if there exists a possible sequence of operations, print "YES" (without quotes); otherwise, print "NO" (without quotes).

You can print each letter in any case (upper or lower).

Example
InputCopy
3
4
4 3 2 5
4
3 3 2 2
5
1 2 3 5 4
OutputCopy
YES
YES
NO
Note
The possible list of operations in the first test case:

Swap a1
 and a2
. The resulting sequence is 3,4,2,5
. The directions are: left, left, right, right.
Swap a2
 and a3
. The resulting sequence is 3,2,4,5
. The directions are: left, left, right, right.
Swap a1
 and a2
. The resulting sequence is 2,3,4,5
. The directions are: right, right, right, right.
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
