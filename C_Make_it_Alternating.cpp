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
// MOD value for handling large numbers in result
static const int MOD = 998244353;
// Precomputed factorial values up to 400000 for calculating combinations
static vector<long long> fact(400001, 1);

// Precompute factorial values with modulo to avoid overflow
void precomputeFactorials()
{
    for (int i = 1; i < (int)fact.size(); i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve()
{
    string s;
    cin >> s;

    // State variables for dynamic programming:
    // len0: length of longest alternating sequence ending with 0
    // ways0: number of ways to achieve that length ending with 0
    // len1: length of longest alternating sequence ending with 1
    // ways1: number of ways to achieve that length ending with 1
    long long len0 = 0, ways0 = 1, len1 = 0, ways1 = 1;

    // Process each character to build alternating sequences
    for (char c : s)
    {
        if (c == '0')
        {
            // When we see a 0, we can only extend sequences that ended with 1
            long long newLen0 = len1 + 1, newWays0 = ways1;
            if (newLen0 > len0)
            {
                // Found a longer sequence ending with 0
                len0 = newLen0;
                ways0 = newWays0 % MOD;
            }
            else if (newLen0 == len0)
            {
                // Found another way to achieve the same length
                ways0 = (ways0 + newWays0) % MOD;
            }
        }
        else // c == '1'
        {
            // When we see a 1, we can only extend sequences that ended with 0
            long long newLen1 = len0 + 1, newWays1 = ways0;
            if (newLen1 > len1)
            {
                len1 = newLen1;
                ways1 = newWays1 % MOD;
            }
            else if (newLen1 == len1)
            {
                ways1 = (ways1 + newWays1) % MOD;
            }
        }
    }

    // Find the length of the longest alternating subsequence possible
    long long L = max(len0, len1);
    // Calculate minimum operations needed (characters to remove)
    long long ops = s.size() - L;

    // Calculate total ways based on which ending gives longer sequence
    long long w = 0;
    if (len0 > len1)
        w = ways0; // If ending with 0 gives longer sequence
    else if (len1 > len0)
        w = ways1; // If ending with 1 gives longer sequence
    else
        w = (ways0 + ways1) % MOD; // If both endings give same length

    // Final answer: multiply ways by number of ways to choose which characters to remove
    // fact[ops] gives us the number of different orders in which we can remove characters
    long long ans = (w * fact[ops]) % MOD;
    cout << ops << " " << ans << "\n";
}
/*
You are given a binary string s
. A binary string is a string consisting of characters 0 and/or 1.

You can perform the following operation on s
 any number of times (even zero):

choose an integer i
 such that 1≤i≤|s|
, then erase the character si
.
You have to make s
 alternating, i. e. after you perform the operations, every two adjacent characters in s
 should be different.

Your goal is to calculate two values:

the minimum number of operations required to make s
 alternating;
the number of different shortest sequences of operations that make s
 alternating. Two sequences of operations are different if in at least one operation, the chosen integer i
 is different in these two sequences.
Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of one line containing the string s
 (1≤|s|≤2⋅105
). The string s
 consists of characters 0 and/or 1 only.

Additional constraint on the input:

the total length of strings s
 over all test cases does not exceed 2⋅105
.
Output
For each test case, print two integers: the minimum number of operations you have to perform, and the number of different shortest sequences of operations. Since the second number might be large, print its remainder modulo 998244353
.

Example
InputCopy
3
10010
111
0101
OutputCopy
1 2
2 6
0 1
Note
In the first test case of the example, the shortest sequences of operations are:

[2]
 (delete the 2
-nd character);
[3]
 (delete the 3
-rd character).
In the second test case of the example, the shortest sequences of operations are:

[2,1]
 (delete the 2
-nd character, then delete the 1
-st character);
[2,2]
;
[1,1]
;
[1,2]
;
[3,1]
;
[3,2]
.
In the third test case of the example, the only shortest sequence of operations is []
 (empty sequence).
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    precomputeFactorials();
    while (t--)
        solve();
}
