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
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        int ops = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == i)
            {
            }
        }
    }
}

/*
A permutation of integers from 1
 to n
 is an array of size n
 where each integer from 1
 to n
 appears exactly once.

You are given a permutation p
 of integers from 1
 to n
. You have to process n
 queries. During the i
-th query, you replace pdi
 with 0
. Each element is replaced with 0
 exactly once. The changes made in the queries are saved, that is, after the i
-th query, all integers pd1,pd2,…,pdi
 are zeroes.

After each query, you have to find the minimum number of operations required to fix the array; in other words, to transform the current array into any permutation of integers from 1
 to n
 (possibly into the original permutation p
, possibly into some other permutation).

The operation you can perform to fix the array is the following one:

choose the integer i
 from 1
 to n
, replace the i
-th element of the array with i
.
Note that the answer for each query is calculated independently, meaning you do not actually apply any operations, just calculate the minimum number of operations.

Input
Each test consists of several test cases. The first line contains one integer t
 (1≤t≤104
) — the number of test cases. Then the test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤105
).

The second line of each test case contains n
 integers p1,p2,…,pn
 (1≤pi≤n
) — the original permutation. All pi
 are distinct.

The third line of each test case contains n
 integers d1,d2,…,dn
 (1≤di≤n
). All di
 are distinct.

Additional constraint on the input:

the sum of n
 across all test cases does not exceed 2⋅105
.
Output
For each test case, output a line containing n
 integers, where the i
-th integer should be equal to the minimum number of operations required to fix the array which was obtained after the i
-th query (i.e., the permutation p
 where all integers pd1,pd2,…,pdi
 are replaced by zeroes).

Example
InputCopy
3
3
1 2 3
3 2 1
5
4 5 3 1 2
4 5 1 3 2
7
4 3 1 2 7 5 6
1 2 3 4 5 6 7
OutputCopy
1 2 3
2 4 4 5 5
4 4 4 4 7 7 7
Note
In the first test case, after each query, every integer which was replaced by 0
 can be restored by one operation.

In the second test case, you can act as follows:

Query 1
: p=[4,5,3,0,2]
, it can be transformed into [1,5,3,4,2]
.
Query 2
: p=[4,5,3,0,0]
, it can be transformed into [1,2,3,4,5]
.
Query 3
: p=[0,5,3,0,0]
, it can be transformed into [1,2,3,4,5]
.
Query 4
: p=[0,5,0,0,0]
, it can be transformed into [1,2,3,4,5]
.
Query 5
: p=[0,0,0,0,0]
, it can be transformed into [1,2,3,4,5]
.
The numbers that were changed are highlighted in red.
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
