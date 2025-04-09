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
    // Read input: n = total days, d = duration of visit, k = number of jobs
    int n, d, k;
    cin >> n >> d >> k;

    // Store each job as a pair (starting day, ending day)
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i].first >> a[i].second;
    } // O(k)

    // Sort jobs by their starting day for efficient sliding window processing
    sort(a.begin(), a.end()); // klogk

    // Initialize variables:
    // mx: max number of overlapping jobs (for brother)
    // mn: min number of overlapping jobs (for mother)
    // b: best day for brother, m: best day for mother
    int mx = 0, mn = INT_MAX, b = -1, m = -1;
    int j = 0;
    // Priority queue to keep track of job end times; top is the earliest end time
    priority_queue<int, vector<int>, greater<int>> pq;

    // Iterate over every valid start day for a d duration window
    for (int i = 1; i <= n - d + 1; i++)
    {
        // Add jobs whose start day is within current window [i, i+d-1]
        while (j < k && a[j].first <= i + d - 1)
        {
            pq.push(a[j].second);
            j++;
        }
        // Remove jobs that have ended before the current window starts
        while (pq.size() && pq.top() < i)
        {
            pq.pop();
        }
        // The current number of overlapping jobs
        int c = pq.size();
        // Update for maximum overlap (for brother) if found better
        if (c > mx)
        {
            mx = c;
            b = i;
        }
        // Update for minimum overlap (for mother) if found better
        if (c < mn)
        {
            mn = c;
            m = i;
        }
    }

    // Output the best starting days for brother and mother respectively
    cout << b << ' ' << m << '\n';
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
