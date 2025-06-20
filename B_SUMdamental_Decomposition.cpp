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
    long long n, x;
    cin >> n >> x;

    if (n == 1)
    {
        // For n=1, answer is x itself if x>0, otherwise invalid
        if (x == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << x << "\n";
        }
    }
    else if (n == 2)
    {
        if (x == 0)
        {
            // For n=2, x=0, use [1,1]
            cout << 2 << "\n";
        }
        else
        {
            // For n=2, x>0, find minimal sum
            long long minSum = LLONG_MAX;
            for (long long a = 1; a <= 3; a++)
            {
                long long b = a ^ x;
                if (b > 0)
                {
                    minSum = min(minSum, a + b);
                }
            }
            cout << minSum << "\n";
        }
    }
    else
    {
        if (n % 2 == 1)
        { // n is odd
            if (x == 0)
            {
                // For odd n and x=0, use [1,1,...,1,2,3]
                cout << n + 3 << "\n";
            }
            else
            {
                // For odd n and x>0, use [1,1,...,1,x]
                cout << (n - 1) + x << "\n";
            }
        }
        else
        { // n is even
            if (x == 0)
            {
                // For even n and x=0, use all 1's
                cout << n << "\n";
            }
            else
            {
                // For even n and x>0, use [1,1,...,1,x^1]
                cout << (n - 1) + (x ^ 1) << "\n";
            }
        }
    }
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
