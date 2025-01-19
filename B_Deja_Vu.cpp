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
    // Read input sizes for arrays
    ll n, q;
    cin >> n >> q;

    // Read the initial array of n numbers
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    // Read q modification queries
    ll brr[q];
    for (ll i = 0; i < q; i++)
        cin >> brr[i];

    // Use set to keep track of processed powers to avoid duplicate operations
    set<ll> hs;

    // Process each query
    for (ll i = 0; i < q; i++)
    {
        // Skip if we've already processed this power
        if (hs.count(brr[i]))
            continue;

        // Add new power to processed set
        hs.insert(brr[i]);

        // For each number in original array
        for (ll j = 0; j < n; j++)
        {
            // Check if number is divisible by 2^x where x is the query value
            // If divisible, add 2^(x-1) to the number
            // Example: if x=3, check if divisible by 2^3=8, if yes add 2^2=4
            if (arr[j] % (1 << brr[i]) == 0)
                arr[j] += (1 << (brr[i] - 1));
        }
    }

    // Print the modified array
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}

/*
You are given an array a
 of length n
, consisting of positive integers, and an array x
 of length q
, also consisting of positive integers.

There are q
 modification. On the i
-th modification (1≤i≤q
), for each j
 (1≤j≤n
), such that aj
 is divisible by 2xi
, you add 2xi−1
 to aj
. Note that xi
 (1≤xi≤30
) is a positive integer not exceeding 30.

After all modification queries, you need to output the final array.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
 and q
 (1≤n,q≤105
) —the length of the array a
 and the number of queries respectively.

The second line of each test case contains n
 integers a1,a2,a3,…,an
 — the elements of the array a
 (1≤ai≤109
).

The third line of each test case contains q
 integers x1,x2,x3,…,xq
 — the elements of the array x
 (1≤xi≤30
), which are the modification queries.

It is guaranteed that the sum of n
 and the sum of q
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the array after all of the modification queries.

Example
InputCopy
4
5 3
1 2 3 4 4
2 3 4
7 3
7 8 12 36 48 6 3
10 4 2
5 4
2 2 2 2 2
1 1 1 1
5 5
1 2 4 8 16
5 2 3 4 1
OutputCopy
1 2 3 6 6
7 10 14 38 58 6 3
3 3 3 3 3
1 3 7 11 19
Note
In the first test case, the first query will add 2
 to the integers in positions 4
 and 5
. After this addition, the array would be [1,2,3,6,6]
. Other operations will not modify the array.

In the second test case, the first modification query does not change the array. The second modification query will add 8
 to the integer in position 5
, so that the array would look like this: [7,8,12,36,56,6,3]
. The third modification query will add 2
 to the integers in positions 2,3
, 4
 and 5
. The array would then look like this: [7,10,14,38,58,6,3]
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
