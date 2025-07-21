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
    // 1) Read input size and array
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 2) Build frequency of values in [0..n]
    //    We only care up to n since MEX ∈ [0..n+1]
    vector<int> freq(n + 1, 0);
    for (int x : a)
    {
        if (x <= n)
        {
            freq[x]++;
        }
    }

    // 3) Prepare a difference-array 'diff' of size n+2
    //    diff[k] will mark how many MEX values start being possible at removal count k,
    //    and diff[k+1] will mark where they stop.
    vector<int> diff(n + 2, 0);

    // 4) For each candidate MEX = x:
    //    - Must remove all occurrences of x ⇒ minimum removals = freq[x]
    //    - Can remove at most all other elements except one copy of each 0..x-1:
    //         max removals = n - x
    //    If freq[x]==0, further x+1,x+2… cannot be MEX in any removal ⇒ break.
    bool valid = true;
    for (int x = 0; x <= n; x++)
    {
        if (!valid)
            break;

        int l = freq[x]; // minimum removals to exclude x entirely
        int r = n - x;   // maximum removals while keeping one of each < x

        if (l <= r)
        {
            // mark interval [l..r] in diff
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        if (freq[x] == 0)
            valid = false;
    }

    // 5) Prefix-sum 'diff' into 'ans' to get number of possible MEX for each k
    vector<int> ans(n + 1, 0);
    int cur = 0;
    for (int k = 0; k <= n; k++)
    {
        cur += diff[k]; // number of new MEX entering at k minus those exiting
        ans[k] = cur;   // total possible MEX values when removing k elements
    }

    // 6) Output result for k = 0..n
    for (int k = 0; k <= n; k++)
    {
        cout << ans[k] << sp;
    }
    cout << nl;
}

/*
Define the MEX
 (minimum excluded value) of an array to be the smallest nonnegative integer not present in the array. For example,

MEX([2,2,1])=0
 because 0
 is not in the array.
MEX([3,1,0,1])=2
 because 0
 and 1
 are in the array but 2
 is not.
MEX([0,3,1,2])=4
 because 0
, 1
, 2
, and 3
 are in the array but 4
 is not.
You are given an array a
 of size n
 of nonnegative integers.

For all k
 (0≤k≤n
), count the number of possible values of MEX(a)
 after removing exactly k
 values from a
.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the size of the array a
.

The second line of each test case contains n
 integers, a1,a2,…,an
 (0≤ai≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single line containing n+1
 integers — the number of possible values of MEX(a)
 after removing exactly k
 values, for k=0,1,…,n
.

Example
InputCopy
5
5
1 0 0 1 2
6
3 2 0 4 5 1
6
1 2 0 1 3 2
4
0 3 4 1
5
0 0 0 0 0
OutputCopy
1 2 4 3 2 1
1 6 5 4 3 2 1
1 3 5 4 3 2 1
1 3 3 2 1
1 1 1 1 1 1
Note
In the first sample, consider k=1
. If you remove a 0
, then you get the following array:

1	0	1	2
So we get MEX(a)=3
. Alternatively, if you remove the 2
, then you get the following array:
1	0	0	1
So we get MEX(a)=2
. It can be shown that these are the only possible values of MEX(a)
 after removing exactly one value. So the output for k=1
 is 2
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
