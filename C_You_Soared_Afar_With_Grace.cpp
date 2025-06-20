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

    // Read both permutations a and b, and build helper arrays:
    // a: first permutation (0-indexed)
    // b: second permutation (0-indexed)
    // p: for each value in a, p[value] = corresponding value in b at the same position
    // ia: for each value in a, ia[value] = index of value in a
    vector<int> a(n), b(n), p(n), ia(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        ia[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
        p[a[i]] = b[i];
    }

    // Count the number of "bad" cycles.
    // For a valid solution, there must be at most one cycle that is not a 2-cycle.
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // If p[i] == i, it's a fixed point (no swap needed).
        // If p[p[i]] != i, it's not a 2-cycle (bad).
        if (p[i] == i || p[p[i]] != i)
        {
            cnt++;
        }
    }

    // If more than one bad cycle, it's impossible.
    if (cnt > 1)
    {
        cout << -1 << "\n";
        return;
    }

    // q: target permutation to reach by swaps
    vector<int> q(n);
    // l and r are pointers for assigning positions from left and right
    for (int i = 0, l = 0, r = n - 1; i < n; i++)
    {
        if (p[i] == i)
        {
            // Fixed point: assign to the middle
            q[ia[i]] = n / 2;
        }
        else if (p[i] > i)
        {
            // For each 2-cycle (i, p[i]), assign one to left, one to right
            q[ia[i]] = l++;
            q[ia[p[i]]] = r--;
        }
    }

    // Now, sort q into the identity permutation using swaps
    // Each swap is recorded in ans
    vector<array<int, 2>> ans;
    for (int i = 0; i < n; i++)
    {
        // While q[i] is not at its correct position, swap it with the value at its target position
        while (q[i] != i)
        {
            ans.push_back({i, q[i]});
            swap(q[i], q[q[i]]);
        }
    }
    // Output the number of swaps and the swap operations (1-based indices)
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
    {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

/*
You are given a permutation a
 and b
 of length n
∗
. You can perform the following operation at most n
 times:

Choose two indices i
 and j
 (1≤i,j≤n
, i≠j
), swap ai
 with aj
, swap bi
 with bj
.
Determine whether a
 and b
 can be reverses of each other after operations. In other words, for each i=1,2,…,n
, ai=bn+1−i
.

If it is possible, output any valid sequence of operations. Otherwise, output −1
.

∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) — the length of the permutations.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤n
).

It is guaranteed that a
 and b
 are permutations of length n
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if it is impossible, output −1
 in the only line. Otherwise, output a single integer m
 (0≤m≤n
) — the number of operations in the first line. In the following m
 lines, output two integers — the indices i
 and j
 (1≤i,j≤n
, i≠j
) in each operation in order. If there are multiple solutions, print any of them.

Example
InputCopy
5
2
1 2
1 2
2
1 2
2 1
4
1 3 2 4
2 4 1 3
5
2 5 1 3 4
3 5 4 2 1
5
3 1 2 4 5
1 2 3 4 5
OutputCopy
-1
0
1
1 2
2
1 2
1 3
-1
Note
In the second test case, b
 is already the reverse of a
.

In the third test case, after performing the following operation, b
 will become the reverse of a
:

Swap a1,a2
 and swap b1,b2
. Now a=[3,1,2,4]
 and b=[4,2,1,3]
.
In the fourth test case, after performing the following operations in order, b
 will become the reverse of a
:

Swap a1,a2
 and swap b1,b2
. Now a=[5,2,1,3,4]
 and b=[5,3,4,2,1]
.
Swap a1,a3
 and swap b1,b3
. Now a=[1,2,5,3,4]
 and b=[4,3,5,2,1]
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
