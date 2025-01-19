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
    // Read the input number
    int n;
    cin >> n;

    // Initialize variables to store three factors and a flag
    int a = -1, b = -1, c = -1, done = 0;

    // Iterate through possible factors up to square root of n
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // Found first factor i, now try to split i into two factors
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0 && i / j != i)
                {
                    // Found a way to split: n / i, j, i / j
                    a = n / i; // First factor
                    b = j;     // Second factor
                    c = i / j; // Third factor

                    // Check if all factors are distinct
                    if (a != b && a != c && b != c)
                    {
                        done = 1;
                        break;
                    }
                }
            }
            if (done)
                break;

            // If first attempt failed, try splitting n / i instead
            if (i != n / i)
            {
                for (int j = 2; j <= sqrt(n / i); j++)
                {
                    if ((n / i) % j == 0 && (n / i) / j != i)
                    {
                        // Try another split: i, j, (n / i) / j
                        a = i;           // First factor
                        b = j;           // Second factor
                        c = (n / i) / j; // Third factor

                        // Check if all factors are distinct
                        if (a != b && a != c && b != c)
                        {
                            done = 1;
                            break;
                        }
                    }
                }
                if (done)
                    break;
            }
        }
    }

    // Check if we found valid factors (all distinct and >= 2)
    if (done == 1 && a != -1 && b != -1 && c != -1 && a != b && a != c && b != c && a >= 2 && b >= 2 && c >= 2)
    {
        cout << "YES\n"
             << a << " " << b << " " << c << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

/*
You are given one integer number n
. Find three distinct integers a,b,c
 such that 2≤a,b,c
 and a⋅b⋅c=n
 or say that it is impossible to do it.

If there are several answers, you can print any.

You have to answer t
 independent test cases.

Input
The first line of the input contains one integer t
 (1≤t≤100
) — the number of test cases.

The next n
 lines describe test cases. The i
-th test case is given on a new line as one integer n
 (2≤n≤109
).

Output
For each test case, print the answer on it. Print "NO" if it is impossible to represent n
 as a⋅b⋅c
 for some distinct integers a,b,c
 such that 2≤a,b,c
.

Otherwise, print "YES" and any possible such representation.

Example
InputCopy
5
64
32
97
2
12345
OutputCopy
YES
2 4 8
NO
NO
NO
YES
3 5 823
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
