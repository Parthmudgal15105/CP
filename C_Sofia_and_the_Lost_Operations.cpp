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

// Fix: Change return type to void, and fix the logic to ensure only one answer per test case is printed.
// Add comments to explain the logic.

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    int m;
    cin >> m;
    vector<int> d(m);
    map<int, int> freq; // Count available operations for each value in d
    for (int i = 0; i < m; ++i)
    {
        cin >> d[i];
        freq[d[i]]++;
    }

    map<int, int> need; // Count how many times we need to assign each value
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            need[b[i]]++;
        }
    }

    // Check if we have enough operations for each needed value
    for (auto &pr : need)
    {
        if (freq[pr.first] < pr.second)
        {
            cno;
            return;
        }
    }

    // Check if the last operation can be assigned somewhere
    // It must be possible to assign d.back() to some position (either a[i] != b[i] and b[i] == d.back(), or a[i] == b[i] == d.back())
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == d.back())
        {
            // If a[i] != b[i], we definitely need to assign here
            // If a[i] == b[i], we can assign here as a redundant operation
            found = true;
            break;
        }
    }
    if (!found)
    {
        cno;
        return;
    }

    cyes;
}

/*
Sofia had an array of n
 integers a1,a2,…,an
. One day she got bored with it, so she decided to sequentially apply m
 modification operations to it.

Each modification operation is described by a pair of numbers ⟨cj,dj⟩
 and means that the element of the array with index cj
 should be assigned the value dj
, i.e., perform the assignment acj=dj
. After applying all modification operations sequentially, Sofia discarded the resulting array.

Recently, you found an array of n
 integers b1,b2,…,bn
. You are interested in whether this array is Sofia's array. You know the values of the original array, as well as the values d1,d2,…,dm
. The values c1,c2,…,cm
 turned out to be lost.

Is there a sequence c1,c2,…,cm
 such that the sequential application of modification operations ⟨c1,d1,⟩,⟨c2,d2,⟩,…,⟨cm,dm⟩
 to the array a1,a2,…,an
 transforms it into the array b1,b2,…,bn
?

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
) — the size of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the elements of the original array.

The third line of each test case contains n
 integers b1,b2,…,bn
 (1≤bi≤109
) — the elements of the found array.

The fourth line contains an integer m
 (1≤m≤2⋅105
) — the number of modification operations.

The fifth line contains m
 integers d1,d2,…,dm
 (1≤dj≤109
) — the preserved value for each modification operation.

It is guaranteed that the sum of the values of n
 for all test cases does not exceed 2⋅105
, similarly the sum of the values of m
 for all test cases does not exceed 2⋅105
.

Output
Output t
 lines, each of which is the answer to the corresponding test case. As an answer, output "YES" if there exists a suitable sequence c1,c2,…,cm
, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
7
3
1 2 1
1 3 2
4
1 3 1 2
4
1 2 3 5
2 1 3 5
2
2 3
5
7 6 1 10 10
3 6 1 11 11
3
4 3 11
4
3 1 7 8
2 2 7 10
5
10 3 2 2 1
5
5 7 1 7 9
4 10 1 2 9
8
1 1 9 8 7 2 10 4
4
1000000000 203 203 203
203 1000000000 203 1000000000
2
203 1000000000
1
1
1
5
1 3 4 5 1
OutputCopy
YES
NO
NO
NO
YES
NO
YES
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
