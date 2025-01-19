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
    // Explanation: Read the size of the array
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Explanation: Count how many numbers have each bit (0-30) set
    vector<int> bitCounts(31, 0);
    for (int i = 0; i < n; i++)
    {
        for (int bit = 0; bit < 31; bit++)
        {
            if (a[i] & (1 << bit))
            {
                bitCounts[bit]++;
            }
        }
    }

    // Dry run example:
    // Suppose n=4 and a=[4, 4, 4, 4]:
    //  - Each 4 in binary is 100 (bit 2 set)
    //  - bitCounts[2] would become 4 (since all have bit 2 set)
    //  - For k=1: 4 % 1 == 0 (ok). For k=2: 4 % 2 == 0 (ok). For k=3: 4 % 3 != 0 (not ok). For k=4: 4 % 4 == 0 (ok).
    //  - So valid answers would be k=1,2,4

    // Explanation: For each possible k from 1 to n,
    // the condition for all elements to become zero is that
    // every bitCount must be divisible by k
    for (int k = 1; k <= n; k++)
    {
        bool possible = true;
        for (int bit = 0; bit < 31; bit++)
        {
            if (bitCounts[bit] % k != 0)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << k << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
