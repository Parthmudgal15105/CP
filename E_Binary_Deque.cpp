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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Count total ones
    int sum = 0;
    for (int x : a)
    {
        if (x == 1)
            sum++;
    }

    // If we can't possibly get sum = s
    if (sum < s)
    {
        cout << -1 << endl;
        return;
    }

    // Two-pointer approach
    int currentSum = 0, start = 0, best = -1;
    for (int end = 0; end < n; end++)
    {
        currentSum += a[end];
        while (currentSum > s && start <= end)
        {
            currentSum -= a[start++];
        }
        if (currentSum == s)
        {
            best = max(best, end - start + 1);
        }
    }

    // Output result
    cout << (best == -1 ? -1 : n - best) << endl;
}
/*
Slavic has an array of length n
 consisting only of zeroes and ones. In one operation, he removes either the first or the last element of the array.

What is the minimum number of operations Slavic has to perform such that the total sum of the array is equal to s
 after performing all the operations? In case the sum s
 can't be obtained after any amount of operations, you should output -1.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and s
 (1≤n,s≤2⋅105
) — the length of the array and the needed sum of elements.

The second line of each test case contains n
 integers ai
 (0≤ai≤1
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum amount of operations required to have the total sum of the array equal to s
, or -1 if obtaining an array with sum s
 isn't possible.

Example
InputCopy
7
3 1
1 0 0
3 1
1 1 0
9 3
0 1 0 1 1 1 0 0 1
6 4
1 1 1 1 1 1
5 1
0 0 1 1 0
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
6 3
1 0 1 0 0 0
OutputCopy
0
1
3
2
2
7
-1
Note
In the first test case, the sum of the whole array is 1
 from the beginning, so we don't have to make any operations.

In the second test case, the sum of the array is 2
 and we want it to be equal to 1
, so we should remove the first element. The array turns into [1,0]
, which has a sum equal to 1
.

In the third test case, the sum of the array is 5
 and we need it to be 3
. We can obtain such a sum by removing the first two elements and the last element, doing a total of three operations. The array turns into [0,1,1,1,0,0]
, which has a sum equal to 3
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
