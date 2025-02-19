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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    // Read the permutation, 1-indexed for convenience.
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    vector<bool> visited(n + 1, false);

    // Iterate over each position to detect cycles.
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int cnt = 0, cur = i;
            // Traverse the current cycle.
            while (!visited[cur])
            {
                visited[cur] = true; // Mark current index as visited.
                cur = a[cur];        // Move to the next element in the cycle.
                cnt++;               // Count the number of elements in current cycle.
            }
            // For cycles with length >= 3, (cycle_length - 1) / 2 swaps are needed.
            // Explanation: A cycle of length L can be simplified by at most floor((L-1)/2) swaps.
            if (cnt >= 3)
            {
                ans += (cnt - 1) / 2;
            }
        }
    }
    cout << ans << '\n';
}

/*
Sakurako's exams are over, and she did excellently. As a reward, she received a permutation p
. Kosuke was not entirely satisfied because he failed one exam and did not receive a gift. He decided to sneak into her room (thanks to the code for her lock) and spoil the permutation so that it becomes simple.

A permutation p
 is considered simple if for every i
 (1≤i≤n)
 one of the following conditions holds:

pi=i
ppi=i
For example, the permutations [1,2,3,4]
, [5,2,4,3,1]
, and [2,1]
 are simple, while [2,3,1]
 and [5,2,1,4,3]
 are not.

In one operation, Kosuke can choose indices i,j
 (1≤i,j≤n)
 and swap the elements pi
 and pj
.

Sakurako is about to return home. Your task is to calculate the minimum number of operations that Kosuke needs to perform to make the permutation simple.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case is described by two lines.

The first line contains one integer n
 (1≤n≤106
) — the length of the permutation p
.
The second line contains n
 integers pi
 (1≤pi≤n
) — the elements of the permutation p
.
It is guaranteed that the sum of n
 across all test cases does not exceed 106
.

It is guaranteed that p
 is a permutation.

Output
For each test case, output the minimum number of operations that Kosuke needs to perform to make the permutation simple.

Example
InputCopy
6
5
1 2 3 4 5
5
5 4 3 2 1
5
2 3 4 5 1
4
2 3 4 1
3
1 3 2
7
2 3 1 5 6 7 4
OutputCopy
0
0
2
1
0
2
Note
In the first and second examples, the permutations are already simple.

In the fourth example, it is sufficient to swap p2
 and p4
. Thus, the permutation will become [2,1,4,3]
 in 1
 operation.
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
