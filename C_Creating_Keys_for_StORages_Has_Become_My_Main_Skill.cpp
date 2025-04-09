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
    // Read input values: n = array length, x = required final bitwise OR value.
    ll n, x;
    cin >> n >> x;

    vector<int> a;
    int curr = 0; // Will hold the cumulative OR of the array elements.
    int mex = 0;  // Will track the MEX (minimum excluded value) used in array generation.

    // Try to fill the first n-1 positions with numbers that satisfy (i & x) == i.
    for (int i = 0; i < n - 1; i++)
    {
        // Check if the current number can be safely added without overshooting bits of x.
        if ((i & x) == i)
        {
            a.push_back(i); // Add number i to the array.
            curr |= i;      // Update the overall OR with i.
            mex++;          // Increase mex since i is used (assuming numbers start from 0 consecutively).
        }
        else
        {
            // Stop adding numbers if condition fails.
            break;
        }
    }

    // If there are still positions left, fill them with x to ensure the final OR is not exceeded.
    while (a.size() < n - 1)
    {
        a.push_back(x); // Append x as a safe filler.
        curr = x;       // Set current OR to x, ensuring we meet the target.
    }

    // For the last element, decide whether we can place 'mex' without violating x OR condition.
    if ((curr | mex) == x)
    {
        a.push_back(mex); // Append mex if including it retains the final OR as x.
    }
    else
    {
        a.push_back(x); // Otherwise, use x to satisfy the required OR.
    }

    // Output the constructed key array with each element separated by space.
    for (auto x : a)
    {
        cout << x << sp;
    }
    cout << nl;
}

/*
Akito still has nowhere to live, and the price for a small room is everywhere. For this reason, Akito decided to get a job at a bank as a key creator for storages.

In this magical world, everything is different. For example, the key for a storage with the code (n,x)
 is an array a
 of length n
 such that:

a1 | a2 | a3 | … | an=x
, where a | b
 is the bitwise "OR" of numbers a
 and b
.
MEX({a1,a2,a3,…,an})
∗
 is maximized among all such arrays.
Akito diligently performed his job for several hours, but suddenly he got a headache. Substitute for him for an hour; for the given n
 and x
, create any key for the storage with the code (n,x)
.

∗
MEX(S)
 is the minimum non-negative integer z
 such that z
 is not contained in the set S
 and all 0≤y<z
 are contained in S
.

Input
The first line contains the number t
 (1≤t≤104
) — the number of test cases.

In the only line of each test case, two numbers n
 and x
 (1≤n≤2⋅105,0≤x<230
) are given — the length of the array and the desired value of the bitwise "OR".

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output n
 integers ai
 (0≤ai<230
) — the elements of the key array that satisfy all the conditions.

If there are multiple suitable arrays, output any of them.

Example
InputCopy
9
1 69
7 7
5 7
7 3
8 7
3 52
9 11
6 15
2 3
OutputCopy
69
6 0 3 4 1 2 5
4 1 3 0 2
0 1 2 3 2 1 0
7 0 6 1 5 2 4 3
0 52 0
0 1 8 3 0 9 11 2 10
4 0 3 8 1 2
0 3


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
