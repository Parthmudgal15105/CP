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
    for(int i=0; i<n; i++)
        cin>>arr[i];
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
    // Read input: n = number of dragons, x and y are the special dragons
    int n, x, y;
    cin >> n >> x >> y;
    // Convert x and y from 1-indexed to 0-indexed for array usage
    x--, y--;

    vector<int> a(n); // Array to store the assigned numbers for dragons

    if (n % 2 == 0)
    {
        // For even n, assign alternating values: 0, 1, 0, 1, ...
        for (int i = 0; i < n; i++)
        {
            a[i] = i % 2;
        }
        // If dragons x and y (friends) have the same number, break the tie by changing one of them
        if (a[x] == a[y])
        {
            a[x] = 2; // New value to ensure mex condition holds on the cycle
        }
    }
    else
    {
        // For odd n, fix the value for dragon x to 2 first
        a[x] = 2;
        // For positions after x, use alternating pattern (0 and 1)
        for (int i = x + 1; i < n; i++)
        {
            a[i] = i % 2;
        }
        // For positions before x, adjust pattern with (n + i) % 2 to maintain cyclic order
        for (int i = 0; i < x; i++)
        {
            a[i] = (n + i) % 2;
        }
    }
    // Output the array where each entry represents dragon's assigned number
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

/*
Evirir the dragon has many friends. They have 3 friends! That is one more than the average dragon.

You are given integers n
, x
, and y
. There are n
 dragons sitting in a circle. The dragons are numbered 1,2,…,n
. For each i
 (1≤i≤n
), dragon i
 is friends with dragon i−1
 and i+1
, where dragon 0
 is defined to be dragon n
 and dragon n+1
 is defined to be dragon 1
. Additionally, dragons x
 and y
 are friends with each other (if they are already friends, this changes nothing). Note that all friendships are mutual.

Output n
 non-negative integers a1,a2,…,an
 such that for each dragon i
 (1≤i≤n
), the following holds:

Let f1,f2,…,fk
 be the friends of dragon i
. Then ai=mex(af1,af2,…,afk)
.∗
∗
The minimum excluded (MEX) of a collection of integers c1,c2,…,cm
 is defined as the smallest non-negative integer t
 which does not occur in the collection c
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first and only line of each test case contains three integers n
, x
, y
 (3≤n≤2⋅105
, 1≤x<y≤n
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output n
 space-separated non-negative integers a1,a2,…,an
 (0≤ai≤109
) on a line that satisfy the condition in the statement. If there are multiple solutions, print any of them. It can be proven that under the problem constraints, a solution with 0≤ai≤109
 always exists.

Example
InputCopy
7
5 1 3
4 2 4
6 3 5
7 3 6
3 2 3
5 1 5
6 2 5
OutputCopy
0 2 1 0 1
1 2 1 0
1 2 0 1 2 0
0 1 2 0 1 0 1
2 0 1
1 0 2 1 0
0 1 2 0 2 1
Note
For the first test case:

i=1
: Dragon 1
's friends are dragons 2,3,5
. mex(a2,a3,a5)=mex(2,1,1)=0=a1
, so the condition for dragon 1
 is satisfied.
i=2
: Dragon 2
's friends are dragons 1,3
. mex(a1,a3)=mex(0,1)=2=a2
.
i=3
: Dragon 3
's friends are dragons 1,2,4
. mex(a1,a2,a4)=mex(0,2,0)=1=a3
.
i=4
: Dragon 4
's friends are dragons 3,5
. mex(a3,a5)=mex(1,1)=0=a4
.
i=5
: Dragon 5
's friends are dragons 1,4
. mex(a1,a4)=mex(0,0)=1=a5
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
