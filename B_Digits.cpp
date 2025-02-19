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
#define pb push_back

// Odd Even /////////////////////////////////////////////
// Function to check if a number is odd
bool odd(ll num) { return ((num & 1) == 1); }

// Function to check if a number is even
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime

// Function to check if a number is prime
bool isPrime(int n)
{
    // Iterate from 2 to sqrt(n) to check for factors
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false; // Not prime if divisible by i
    }
    return true; // Prime if no divisors found
}

///////////////////////////////////////////////////////// LCM GCD

// Function to calculate the Greatest Common Divisor (GCD) using Euclidean algorithm
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Returns GCD of a and b
}

// Function to calculate the Least Common Multiple (LCM)
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b; // LCM formula based on GCD
}
////////////////////////////////////////////////////////// SQR ROOT

// Function to calculate square root using binary search
long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1; // Move to the right half
        else
            e = m - 1; // Move to the left half
    }
    return res; // Returns the integer square root of x
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
// Function to solve each test case
void solve()
{
    ll n, d;
    cin >> n >> d;
    vi ans;
    ans.pb(1);
    if (n >= 3 || d % 3 == 0)
        ans.pb(3);
    if (d == 5)
        ans.pb(5);
    if (n >= 3 || d == 7)
        ans.pb(7);
    if (n >= 6 || ((d == 3 || d == 6 || d == 9) && (n >= 3)) || d == 9)
        ans.pb(9);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";
}

/*
Artem wrote the digit d
 on the board exactly n!
 times in a row. So, he got the number dddddd…ddd
 (exactly n! digits).

Now he is curious about which odd digits from 1
 to 9
 divide the number written on the board.

Input
The first line contains a single integer t
 (1≤t≤100
) — the number of test cases. The next t
 test cases follow.

Each test case consists of a single line containing two integers n
 and d
 (2≤n≤10^9
, 1≤d≤9
).

Output
For each test case, output the odd digits in ascending order that divide the number written on the board.

Example
InputCopy
3
2 6
7 1
8 5
OutputCopy
1 3
1 3 7 9
1 3 5 7 9
Note
The factorial of a positive integer n
 (n!
) is the product of all integers from 1
 to n
. For example, the factorial of 5
 is 1⋅2⋅3⋅4⋅5=120
.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; // Read number of test cases
    while (t--)
        solve(); // Solve each test case
}
