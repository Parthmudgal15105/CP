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
    int n;
    cin >> n;
    // 1-based indexing array
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // We need to find pairs (i,j) where:
    // 1. ai < i
    // 2. aj < j
    // 3. i < aj
    // 4. i < j

    long long res = 0;
    vector<int> v; // This vector will store valid indices

    for (int i = 1; i <= n; i++)
    {
        // Skip if current element is greater than or equal to its index
        // because we need ai < i for the first condition
        if (a[i] >= i)
        {
            continue;
        }

        // For each valid i where ai < i, we need to find how many previous
        // indices can form a valid pair with current i

        // lower_bound finds position of first element >= a[i]
        // This gives us count of elements in v that are < a[i]
        // These elements represent valid positions that satisfy all conditions
        res += (long long)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());

        // Add current index to vector of valid indices
        // This index might form pairs with future elements
        v.push_back(i);
    }

    cout << res << '\n';
}

// Example walkthrough:
// For array [1,1,2,3,8,2,1,4]
// When i=2: a[2]=1, 1<2, v=[1], res=1 (pair with index 1)
// When i=3: a[3]=2, 2<3, v=[1,2], res=2 (pair with index 2)
// When i=8: a[8]=4, 4<8, v=[1,2,3], res=3 (pair with index 2)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
