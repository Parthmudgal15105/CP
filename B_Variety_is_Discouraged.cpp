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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
    // Read input size and the array elements.
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Frequency array for each element in a.
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    // Mark positions allowed if the element appears exactly once.
    vector<bool> allowed(n, false);
    for (int i = 0; i < n; i++)
    {
        if (freq[a[i]] == 1)
            allowed[i] = true;
    }
    // Use two pointers to find the maximum contiguous segment of allowed indices.
    int best = 0, bestL = -1, bestR = -1;
    for (int i = 0; i < n;)
    {
        if (!allowed[i])
        {
            i++;
            continue;
        }
        int j = i;
        // Extend segment while allowed positions continue.
        while (j < n && allowed[j])
            j++;
        int len = j - i;
        // Update best segment if current segment length is greater.
        if (len > best)
        {
            best = len;
            bestL = i;
            bestR = j - 1;
        }
        i = j;
    }
    // Output the result in 1-indexed format if a valid segment found; otherwise, output 0.
    if (best > 0)
        cout << bestL + 1 << sp << bestR + 1 << nl;
    else
        cout << 0 << nl;
}
/*
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
