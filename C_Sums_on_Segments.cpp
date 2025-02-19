#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// Optimization directives
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Type definitions
#define pb push_back
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
#define pii pair < int, int >>

// Function to check if a number is odd
bool odd(ll num) { return ((num & 1) == 1); }

// Function to check if a number is even
bool even(ll num) { return ((num & 1) == 0); }

// Function to check if a number is prime
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to compute GCD of two numbers
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

// Function to compute LCM of two numbers
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

// Custom square root function using binary search
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
    Helper function to calculate the maximum subarray sum.
    Uses Kadane's algorithm.
*/
long long maxSubarraySum(vector<int> &arr)
{
    if (!arr.size())
    {
        return 0;
    }
    long long res = arr[0];
    long long maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        maxEnding = max(maxEnding + arr[i], (long long)arr[i]);
        res = max(res, maxEnding);
    }
    return max(res, 0LL);
}

// Function to solve each test case
void solve()
{
    ll n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll vv = 0;
    ll ii = -1;
    // Find the index of the element that is neither 1 nor -1
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != 1 && v[i] != -1)
        {
            vv = v[i];
            ii = i;
        }
    }
    set<ll> s, s1;
    s.insert(0);
    s1.insert(0);
    if (ii != -1)
    {
        ll sum = 0;
        // Calculate prefix sums after the special element
        for (ll i = ii + 1; i < n; i++)
        {
            sum += v[i];
            s.insert(sum);
        }
        sum = 0;
        // Calculate suffix sums before the special element
        for (ll i = ii - 1; i >= 0; i--)
        {
            sum += v[i];
            s1.insert(sum);
        }
        ll l = *(s.begin()) + *(s1.begin()), r = *(s.rbegin()) + *(s1.rbegin());
        ll a1 = l + v[ii];
        ll b1 = r + v[ii];
        vi v1, v2, v3, v4;
        // Prepare vectors for subarray calculations
        for (ll i = 0; i < ii; i++)
        {
            v1.pb(v[i]);
            v2.pb(-v[i]);
        }
        for (ll i = ii + 1; i < n; i++)
        {
            v3.pb(v[i]);
            v4.pb(-v[i]);
        }
        ll b2 = maxSubarraySum(v1);
        ll a2 = -maxSubarraySum(v2);
        ll b3 = maxSubarraySum(v3);
        ll a3 = -maxSubarraySum(v4);
        set<ll> ans;
        // Collect all possible sums
        for (ll i = a1; i <= b1; i++)
        {
            ans.insert(i);
        }
        for (ll i = a2; i <= b2; i++)
        {
            ans.insert(i);
        }
        for (ll i = a3; i <= b3; i++)
        {
            ans.insert(i);
        }
        ans.insert(0);
        // Output the results
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        ll a = maxSubarraySum(v);
        for (auto &it : v)
        {
            it = -it;
        }
        ll b = -maxSubarraySum(v);
        cout << a - b + 1 << endl;
        for (ll i = b; i <= a; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
    Problem Description:
    You are given an array a of n integers, where all elements except for at most one are equal to −1 or 1.
    The remaining element x satisfies −10^9 ≤ x ≤ 10^9.

    Find all possible sums of subarrays of a, including the empty subarray (sum is 0).
    Output these sums in ascending order, each sum printed only once.
*/

// Main function to handle multiple test cases
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
