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

int penalty(const vi &arr)
{
    int p = 0;
    for (int i = 0; i + 1 < (int)arr.size(); i++)
    {
        if (arr[i] < arr[i + 1])
            p++;
    }
    return p;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int penalty = 0;
    int low = n + 1;
    int high = n + 1;

    for (int i = 0; i < n; i++)
    {
        if (low > high)
        {
            swap(low, high);
        }
        if (a[i] <= low)
        {
            low = a[i];
        }
        else if (a[i] > high)
        {
            penalty++;
            low = a[i];
        }
        else
        {
            high = a[i];
        }
    }
    cout << penalty << nl;
}

/*
You are given an array a
 of size n
. You will do the following process to calculate your penalty:

Split array a
 into two (possibly empty) subsequences†
 s
 and t
 such that every element of a
 is either in s
 or t‡
.
For an array b
 of size m
, define the penalty p(b)
 of an array b
 as the number of indices i
 between 1
 and m−1
 where bi<bi+1
.
The total penalty you will receive is p(s)+p(t)
.
If you perform the above process optimally, find the minimum possible penalty you will receive.

†
 A sequence x
 is a subsequence of a sequence y
 if x
 can be obtained from y
 by the deletion of several (possibly, zero or all) elements.

‡
 Some valid ways to split array a=[3,1,4,1,5]
 into (s,t)
 are ([3,4,1,5],[1])
, ([1,1],[3,4,5])
 and ([],[3,1,4,1,5])
 while some invalid ways to split a
 are ([3,4,5],[1])
, ([3,1,4,1],[1,5])
 and ([1,3,4],[5,1])
.

Input
Each test contains multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the size of the array a
.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the elements of the array a
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer representing the minimum possible penalty you will receive.

Example
InputCopy
5
5
1 2 3 4 5
8
8 2 3 1 1 7 4 3
5
3 3 3 3 3
1
1
2
2 1
OutputCopy
3
1
0
0
0
Note
In the first test case, a possible way to split a
 is s=[2,4,5]
 and t=[1,3]
. The penalty is p(s)+p(t)=2+1=3
.

In the second test case, a possible way to split a
 is s=[8,3,1]
 and t=[2,1,7,4,3]
. The penalty is p(s)+p(t)=0+1=1
.

In the third test case, a possible way to split a
 is s=[]
 and t=[3,3,3,3,3]
. The penalty is p(s)+p(t)=0+0=0
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
