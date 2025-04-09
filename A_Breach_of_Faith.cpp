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
    ll n;
    cin >> n;
    vector<ll> a(2 * n);
    for (ll i = 0; i < n * 2; i++)
    {
        cin >> a[i];
    }
    // Sort the input array to arrange the numbers in increasing order.
    sort(a.begin(), a.end());

    ll s = 0;
    vector<ll> g;
    // Pair elements from the lower and upper halves (ignoring the first smallest number, a[0]),
    // to later manipulate the alternating sum.
    for (ll i = 1; i < n; i++)
    {
        // a[i] from the lower segment, and a[i + n - 1] from the upper segment.
        g.push_back(a[i]);
        g.push_back(a[i + n - 1]);

        // Accumulate the difference between the paired numbers.
        // This difference sum 's' helps us calculate the necessary adjustment.
        s += a[i + n - 1] - a[i];
    }
    // After pairing, we add a correction element:
    // s + a[n*2 - 1] (largest element) + a[0] (smallest element).
    // This element is chosen to balance the alternating sum condition imposed by the problem.
    g.push_back(s + a[n * 2 - 1] + a[0]);

    // Lastly, add the smallest element at the end.
    g.push_back(a[0]);

    // Output the largest element first, followed by the newly created sequence.
    cout << a[n * 2 - 1];
    for (ll i = 0; i < n * 2; i++)
    {
        cout << sp << g[i];
    }
    cout << nl;
}

/*
You and your team have worked tirelessly until you have a sequence a1,a2,…,a2n+1
 of positive integers satisfying these properties.

1≤ai≤1018
 for all 1≤i≤2n+1
.
a1,a2,…,a2n+1
 are pairwise distinct.
a1=a2−a3+a4−a5+…+a2n−a2n+1
.
However, the people you worked with sabotaged you because they wanted to publish this sequence first. They deleted one number from this sequence and shuffled the rest, leaving you with a sequence b1,b2,…,b2n
. You have forgotten the sequence a
 and want to find a way to recover it.

If there are many possible sequences, you can output any of them. It can be proven under the constraints of the problem that at least one sequence a
 exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
).

The second line of each test case contains 2n
 distinct integers b1,b2,…,b2n
 (1≤bi≤109
), denoting the sequence b
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 2n+1
 distinct integers, denoting the sequence a
 (1≤ai≤1018
).

If there are multiple possible sequences, you can output any of them. The sequence a
 should satisfy the given conditions, and it should be possible to obtain b
 after deleting one element from a
 and shuffling the remaining elements.

Example
InputCopy
4
1
9 2
2
8 6 1 4
3
99 2 86 33 14 77
2
1 6 3 2
OutputCopy
7 9 2
1 8 4 6 9
86 99 2 77 69 14 33
4 6 1 2 3
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
