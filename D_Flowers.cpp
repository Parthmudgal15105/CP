#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// Global variables
int k;                       // Minimum group size for white flowers
lli dp[100001], fre[100001]; // dp[i]: number of ways for i flowers, fre[i]: prefix sum for fast queries

// Recursive function to compute number of ways to arrange n flowers
int getAns(int n)
{
    // Base case: 1 way to arrange 0 flowers (empty sequence)
    if (n == 0)
        return 1;

    // If already computed, return memoized value
    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    // Add a red flower at the end (always allowed)
    ans += getAns(n - 1);
    ans %= mod;

    // Add a group of k white flowers at the end (only if n >= k)
    if (n >= k)
    {
        ans += getAns(n - k);
        ans %= mod;
    }

    // Memoize and return
    return dp[n] = ans;
}

// Precompute dp and prefix sums for all possible flower counts
void init()
{
    // Initialize dp array to -1 (uncomputed)
    for (int i = 1; i <= 100000; i++)
        dp[i] = -1;

    // Build prefix sum array: fre[i] = sum of ways for 1..i flowers
    for (int i = 1; i <= 100000; i++)
        fre[i] = (fre[i - 1] + getAns(i)) % mod;
}

/*
We saw the little game Marmot made for Mole's lunch. Now it's Marmot's dinner time and, as we all know, Marmot eats flowers. At every dinner he eats some red and white flowers. Therefore a dinner can be represented as a sequence of several flowers, some of them white and some of them red.

But, for a dinner to be tasty, there is a rule: Marmot wants to eat white flowers only in groups of size k.

Now Marmot wonders in how many ways he can eat between a and b flowers. As the number of ways could be very large, print it modulo 1000000007 (109 + 7).

Input
Input contains several test cases.

The first line contains two integers t and k (1 ≤ t, k ≤ 105), where t represents the number of test cases.

The next t lines contain two integers ai and bi (1 ≤ ai ≤ bi ≤ 105), describing the i-th test.

Output
Print t lines to the standard output. The i-th line should contain the number of ways in which Marmot can eat between ai and bi flowers at dinner modulo 1000000007 (109 + 7).
*/

int main()
{
    int t, a, b;
    cin >> t >> k; // Read number of test cases and group size k

    init(); // Precompute all answers

    while (t--)
    {
        cin >> a >> b; // Read query range [a, b]

        // The answer is the sum of ways for all lengths from a to b
        // This is fre[b] - fre[a-1], adjusted for modulo
        lli result = fre[b] - fre[a - 1];
        if (result < 0)
            result += mod;
        cout << result << endl;
    }
}