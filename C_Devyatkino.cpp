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
    int x;
    cin >> x;

    assert(x > 8); // n >= 10 as per problem constraints

    // Try all possible numbers of operations from 0 to 7
    // (since adding 9 up to 7 times covers all possible last digits)
    for (int i = 0; i < 8; ++i)
    {
        int n = x - i; // Subtract i*9 from x to simulate adding 9 i times
        auto s = to_string(n);

        // For each digit in the number
        for (char c : s)
        {
            if (c > '7')
                continue; // If digit is greater than 7, adding 9 won't make it 7 or less
            // If we can reach '7' from this digit by adding 9 i times
            if ('7' - c <= i) // i dont know why <= is here ...........................
            {
                // Found a way to get a '7' in i operations
                cout << i << nl;
                return;
            }
        }
    }

    // If not found in 0..7 operations, answer is 7 (worst case)
    cout << 7 << nl;
}

/*
You are given a positive integer n
. In one operation, you can add to n
 any positive integer whose decimal representation contains only the digit 9
, possibly repeated several times.

What is the minimum number of operations needed to make the number n
 contain at least one digit 7
 in its decimal representation?

For example, if n=80
, it is sufficient to perform one operation: you can add 99
 to n
, after the operation n=179
, which contains the digit 7
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line of each test case contains an integer n
 (10≤n≤109
).

Output
For each test case, output the minimum number of operations required for the number n
 to contain the digit 7
.

Example
InputCopy
16
51
60
61
777
12345689
1000000000
2002
3001
977
989898986
80
800001
96
70
15
90
OutputCopy
3
2
1
0
1
3
5
4
0
7
1
2
7
0
7
3
Note
In the first test case, three operations are sufficient: 51+9+9+9=78
, which contains the digit 7
. It can be shown that it is impossible to achieve the goal in one or two operations.

In the second test case, two operations are sufficient: 60+9+9=78
.

In the third test case, one operation is sufficient: 61+9=70
.

In the fourth test case, n
 already contains the digit 7
, so no operations are required.

In the fifth test case, you can add 99
 to n
 to obtain a number containing the digit 7
.
}
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
