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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int sumall = 0;
        for (int i = 0; i < n; ++i)
        {
            sumall += (a[i] + 2 * mid) * (a[i] + 2 * mid);
            if (sumall > c)
                break;
        }
        if (sumall == c)
        {
            cout << mid << "\n";
            return;
        }
        if (sumall > c)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}
/*
Mircea has n
 pictures. The i
-th picture is a square with a side length of si
 centimeters.

He mounted each picture on a square piece of cardboard so that each picture has a border of w
 centimeters of cardboard on all sides. In total, he used c
 square centimeters of cardboard. Given the picture sizes and the value c
, can you find the value of w
?

A picture of the first test case. Here c=50=52+42+32
, so w=1
 is the answer.
Please note that the piece of cardboard goes behind each picture, not just the border.

Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases.

The first line of each test case contains two positive integers n
 (1≤n≤2⋅105
) and c
 (1≤c≤1018
) — the number of paintings, and the amount of used square centimeters of cardboard.

The second line of each test case contains n
 space-separated integers si
 (1≤si≤104
) — the sizes of the paintings.

The sum of n
 over all test cases doesn't exceed 2⋅105
.

Additional constraint on the input: Such an integer w
 exists for each test case.

Please note, that some of the input for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

Output
For each test case, output a single integer — the value of w
 (w≥1
) which was used to use exactly c
 squared centimeters of cardboard.

Example
InputCopy
10
3 50
3 2 1
1 100
6
5 500
2 2 2 2 2
2 365
3 4
2 469077255466389
10000 2023
10 635472106413848880
9181 4243 7777 1859 2017 4397 14 9390 2245 7225
7 176345687772781240
9202 9407 9229 6257 7743 5738 7966
14 865563946464579627
3654 5483 1657 7571 1639 9815 122 9468 3079 2666 5498 4540 7861 5384
19 977162053008871403
9169 9520 9209 9013 9300 9843 9933 9454 9960 9167 9964 9701 9251 9404 9462 9277 9661 9164 9161
18 886531871815571953
2609 10 5098 9591 949 8485 6385 4586 1064 5412 6564 8460 2245 6552 5089 8353 3803 3764
OutputCopy
1
2
4
5
7654321
126040443
79356352
124321725
113385729
110961227
Note
The first test case is explained in the statement.

For the second test case, the chosen w
 was 2
, thus the only cardboard covers an area of c=(2⋅2+6)2=102=100
 squared centimeters.

For the third test case, the chosen w
 was 4
, which obtains the covered area c=(2⋅4+2)2×5=102×5=100×5=500
 squared centimeters.
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
