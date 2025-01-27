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

/*----------------------------------------------------------------------------*/
void solve()
{
    // 1. Read input string s (the current digits).
    // 2. For each position i:
    //    - Find a "best" digit in the next few positions accounting for -1 per left swap.
    //    - Swap that digit all the way to position i.
    //    - Update s[i] to the corrected digit value.
    // 3. Print the final string.

    // We read the input string of digits
    string s;
    cin >> s;

    // Loop over each position in the string
    for (int i = 0; i < s.size(); i++)
    {
        // best holds the maximum adjusted digit value,
        // pos stores the position of that "best" candidate
        int best = s[i] - '0', pos = i;

        // Check the next few digits to see if moving them here is beneficial
        for (int j = i; j < min(i + 10, (int)s.size()); j++)
        {
            // s[j] - '0' - (j - i) represents the digit after decreasing it
            // (j - i) times (each move to the left reduces the digit by 1)
            if (s[j] - '0' - (j - i) > best)
            {
                best = s[j] - '0' - (j - i);
                pos = j;
            }
        }

        // Move the chosen digit to position i by repeatedly swapping left
        while (pos > i)
        {
            swap(s[pos], s[pos - 1]);
            pos--;
        }

        // Replace the digit at position i with the updated 'best' digit
        s[i] = char(best + '0');
    }

    // Print the final lexicographically maximum string
    cout << s << nl;
}

/*
You are given a string s
, consisting of digits from 0
 to 9
. In one operation, you can pick any digit in this string, except for 0
 or the leftmost digit, decrease it by 1
, and then swap it with the digit left to the picked.

For example, in one operation from the string 1023
, you can get 1103
 or 1022
.

Find the lexicographically maximum string you can obtain after any number of operations.

Input
The first line of the input consists of an integer t
 (1≤t≤104
)  — the number of test cases.

Each test case consists of a single line consisting of a digital string s
 (1≤|s|≤2⋅105
), where |s|
 denotes the length of s
. The string does not contain leading zeroes.

It is guaranteed that the sum of |s|
 of all test cases doesn't exceed 2⋅105
.

Output
For each test case, print the answer on a separate line.

Example
InputCopy
6
19
1709
11555
51476
9876543210
5891917899
OutputCopy
81
6710
33311
55431
9876543210
7875567711
Note
In the first example, the following sequence of operations is suitable: 19→81
.

In the second example, the following sequence of operations is suitable: 1709→1780→6180→6710
.

In the fourth example, the following sequence of operations is suitable: 51476→53176→53616→53651→55351→55431
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
