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
    int n;
    cin >> n; // read the size of the array
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // read each element
        a[i]--;      // shift to 0-based for indexing
    }

    int ans = 0;      // number of cool segments found
    int tot = 0;      // total distinct elements in the current suffix
    vector<int> c(n); // frequency count for each value in suffix

    // First pass: count distinct elements over the entire array
    for (int i = 0; i < n; i++)
    {
        // if c[a[i]] == 0, it's a new distinct => add 1; then increment frequency
        tot += !c[a[i]]++;
    }

    int cur = tot;          // distinct elements still needed to close current segment
    vector<int> vis(n, -1); // marker to ensure each distinct is counted once per segment

    // Greedily iterate from end to start to form segments
    for (int i = n - 1; i >= 0; i--)
    {
        // if this value hasn't been seen in the current segment (ans)
        if (vis[a[i]] != ans)
        {
            vis[a[i]] = ans; // mark it as seen for segment number 'ans'
            cur--;           // one less distinct to cover in this segment
        }
        // remove this occurrence from suffix: if frequency goes from 1->0, tot--
        tot -= !--c[a[i]];

        // if we've covered all distinct for this segment, close it
        if (cur == 0)
        {
            ans++;     // increment segment count
            cur = tot; // reset 'cur' to cover distinct in the remaining prefix
        }
    }

    cout << ans << nl; // output the maximum number of cool segments
}

/*
Yousef has an array a
 of size n
. He wants to partition the array into one or more contiguous segments such that each element ai
 belongs to exactly one segment.

A partition is called cool if, for every segment bj
, all elements in bj
 also appear in bj+1
 (if it exists). That is, every element in a segment must also be present in the segment following it.

For example, if a=[1,2,2,3,1,5]
, a cool partition Yousef can make is b1=[1,2]
, b2=[2,3,1,5]
. This is a cool partition because every element in b1
 (which are 1
 and 2
) also appears in b2
. In contrast, b1=[1,2,2]
, b2=[3,1,5]
 is not a cool partition, since 2
 appears in b1
 but not in b2
.

Note that after partitioning the array, you do not change the order of the segments. Also, note that if an element appears several times in some segment bj
, it only needs to appear at least once in bj+1
.

Your task is to help Yousef by finding the maximum number of segments that make a cool partition.

Input
The first line of the input contains integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
) — the size of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print one integer — the maximum number of segments that make a cool partition.

Example
InputCopy
8
6
1 2 2 3 1 5
8
1 2 1 3 2 1 3 2
5
5 4 3 2 1
10
5 8 7 5 8 5 7 8 10 9
3
1 2 2
9
3 3 1 4 3 2 4 1 2
6
4 5 4 5 6 4
8
1 2 1 2 1 2 1 2
OutputCopy
2
3
1
3
1
3
3
4
Note
The first test case is explained in the statement. We can partition it into b1=[1,2]
, b2=[2,3,1,5]
. It can be shown there is no other partition with more segments.

In the second test case, we can partition the array into b1=[1,2]
, b2=[1,3,2]
, b3=[1,3,2]
. The maximum number of segments is 3
.

In the third test case, the only partition we can make is b1=[5,4,3,2,1]
. Any other partition will not satisfy the condition. Therefore, the answer is 1
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
