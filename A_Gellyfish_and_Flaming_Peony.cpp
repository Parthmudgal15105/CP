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
    return (a / __gcd(a, b)) * b;
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
// Returns the list of distinct prime factors of n
vector<int> findPrimeFactors(int n)
{
    // To store the prime factor
    vector<int> primeFactors(9, 0);

    int j = 0;

    // Check for factor 2
    if (n % 2 == 0)
    {
        primeFactors[j++] = 2;
        while (n % 2 == 0)
            n >>= 1;
    }

    // Check for odd factors
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            primeFactors[j++] = i;
            while (n % i == 0)
                n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
        primeFactors[j++] = n;

    vector<int> PrimeFactors(j);

    for (int i = 0; i < j; i++)
    {
        PrimeFactors[i] = primeFactors[i];
    }

    return PrimeFactors;
}

// Dynamic programming to find the shortest subsequence that covers all prime factors
void findShortestSubsequence(vector<int> &dp, vector<int> a, int index, vector<int> primeFactors)
{
    int n = a.size();

    for (int j = index; j < n; j++)
    {
        int bitmask = 0;

        // For each prime factor, set the corresponding bit if a[j] is divisible by it
        for (int p = 0; p < primeFactors.size(); p++)
        {
            if (a[j] % primeFactors[p] == 0)
            {
                bitmask ^= (1 << p);
            }
        }
        // Update dp for all possible bitmasks
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == n + 1)
            {
                continue;
            }
            dp[bitmask & i] = min(dp[bitmask & i], dp[i] + 1);
        }
    }
}

// Finds the minimum length of a subsequence whose GCD is 1
int printMinimumLength(vector<int> a)
{
    int Min = a.size() + 1;

    // Try each element as the start of the subsequence
    for (int i = 0; i < a.size() - 1; i++)
    {
        vector<int> primeFactors = findPrimeFactors(a[i]);
        int n = primeFactors.size();
        vector<int> dp(1 << n, a.size() + 1);
        int setBits = (1 << n) - 1;
        dp[setBits] = 1;
        findShortestSubsequence(dp, a, i + 1, primeFactors);
        Min = min(dp[0], Min);
    }

    return Min;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Find the GCD of the entire array
    ll g = 0;
    for (int i = 0; i < n; i++)
    {
        g = gcd(g, a[i]);
    }

    // Divide all elements by the GCD to reduce the problem
    for (int i = 0; i < n; i++)
    {
        a[i] /= g;
    }

    // Find the minimum length of a subsequence whose GCD is 1
    auto an = printMinimumLength(a);

    // If all elements are 1, no operations are needed
    if (count(a.begin(), a.end(), 1) == n)
    {
        cout << 0 << nl;
        return;
    }

    // Count how many elements are greater than 1
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 1)
        {
            cnt++;
        }
    }

    // Output the minimum number of operations based on the subsequence found
    if (an != 1)
        cout << cnt + an - 2 << nl;
    else
        cout << cnt << nl;
}
/*
Gellyfish hates math problems, but she has to finish her math homework:

Gellyfish is given an array of n
 positive integers a1,a2,…,an
.

She needs to do the following two-step operation until all elements of a
 are equal:

Select two indexes i
, j
 satisfying 1≤i,j≤n
 and i≠j
.
Replace ai
 with gcd(ai,aj)
.
Now, Gellyfish asks you for the minimum number of operations to achieve her goal.

It can be proven that Gellyfish can always achieve her goal.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤5000
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤5000
) — the length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤5000
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, output a single integer — the minimum number of operations to achieve her goal.

Example
InputCopy
3
3
12 20 30
6
1 9 1 9 8 1
3
6 14 15
OutputCopy
4
3
3
Note
In the first test case, the following is a way that minimizes the number of operations:

Choose i=3
 and j=2
 and replace a3
 with gcd(a3,a2)=gcd(30,20)=10
, then a
 becomes [12,20,10]
.
Choose i=1
 and j=3
 and replace a1
 with gcd(a1,a3)=gcd(12,10)=2
, then a
 becomes [2,20,10]
.
Choose i=2
 and j=1
 and replace a2
 with gcd(a2,a1)=gcd(20,2)=2
, then a
 becomes [2,2,10]
.
Choose i=3
 and j=1
 and replace a3
 with gcd(a3,a1)=gcd(10,2)=2
, then a
 becomes [2,2,2]
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
