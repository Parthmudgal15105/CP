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
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 1 << nl;
        cout << a << nl;
    }
    else if (a > b)
    {
        int x = b, y = b, z = 3 * a - 2 * b;

        cout << 3 << nl;
        cout << x << sp << y << sp << z << nl;
    }
    else
    {
        int x = 3 * a - 2 * b, y = b, z = b;

        cout << 3 << nl;
        cout << x << sp << y << sp << z << nl;
    }
}

/*
A-Ming's birthday is coming and his friend A-May decided to give him an integer array as a present. A-Ming has two favorite numbers a
 and b
, and he thinks an array is beautiful if its mean is exactly a
 and its median is exactly b
. Please help A-May find a beautiful array so her gift can impress A-Ming.

The mean of an array is its sum divided by its length. For example, the mean of array [3,−1,5,5]
 is 12÷4=3
.

The median of an array is its middle element after sorting if its length is odd, or the mean of two middle elements after sorting if its length is even. For example, the median of [1,1,2,4,8]
 is 2
 and the median of [3,−1,5,5]
 is (3+5)÷2=4
.

Note that the mean and median are not rounded to an integer. For example, the mean of array [1,2]
 is 1.5
.

Input
The only line contains two integers a
 and b
.

−100≤a,b≤100
.
The length of the array must be between 1
 and 1000
.
The elements of the array must be integers and their absolute values must not exceed 106
.
Output
In the first line, print the length of the array.

In the second line, print the elements of the array.

If there are multiple solutions, you can print any. It can be proved that, under the constraints of the problem, a solution always exists.

Examples
InputCopy
3 4
OutputCopy
4
3 -1 5 5
InputCopy
-100 -100
OutputCopy
1
-100
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();
}
