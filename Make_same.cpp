// This program computes the minimum number of swap operations required to convert three binary strings of length N so that each string becomes homogeneous
// (i.e., contains all '0's or all '1's). If conversion is not possible, it outputs -1.

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
bool odd(ll num)
{
    return ((num & 1) == 1);
}
bool even(ll num)
{
    return ((num & 1) == 0);
}

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
void solve()
{
    // Reading the string length and the three binary strings
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    // Count the number of '1's in each string
    int onesA = 0, onesB = 0, onesC = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
            onesA++;
        if (b[i] == '1')
            onesB++;
        if (c[i] == '1')
            onesC++;
    }

    int totalOnes = onesA + onesB + onesC;

    // Check if strings are already homogeneous or if transformation is impossible
    if (totalOnes != 0 && totalOnes != n && totalOnes != 2 * n && totalOnes != 3 * n)
    {
        cout << -1 << nl;
        return;
    }

    // If all strings are homogeneous (all '0's or all '1's), no operations required
    if (totalOnes == 0 || totalOnes == 3 * n)
    {
        cout << 0 << nl;
        return;
    }

    int ans = INT_MAX;

    // Case where exactly one string is homogeneous w.r.t '1's count
    if (totalOnes == n)
    {
        {
            // a is the string to be converted
            int mini = n - onesA;     // operations needed to convert a to all '1's
            int maxi = onesB + onesC; // operations available from b and c
            ans = min(ans, max(mini, maxi));
        }
        {
            // b is the string to be converted
            int mini = n - onesB;
            int maxi = onesA + onesC;
            ans = min(ans, max(mini, maxi));
        }
        {
            // c is the string to be converted
            int mini = n - onesC;
            int maxi = onesA + onesB;
            ans = min(ans, max(mini, maxi));
        }
    }
    // Case where exactly one string is homogeneous to '0's (i.e., two strings homogeneous to '1's)
    else if (totalOnes == 2 * n)
    {
        {
            // a already has some ones; b and c need conversion towards '0's
            int mini = onesA;                     // operations needed from a
            int maxi = (n - onesB) + (n - onesC); // operations needed to convert b and c to all '0's
            ans = min(ans, max(mini, maxi));
        }
        {
            // Similar calculation assuming b as the donor for conversion
            int mini = onesB;
            int maxi = (n - onesA) + (n - onesC);
            ans = min(ans, max(mini, maxi));
        }
        {
            // Similar calculation assuming c as the donor for conversion
            int mini = onesC;
            int maxi = (n - onesA) + (n - onesB);
            ans = min(ans, max(mini, maxi));
        }
    }

    // Output the computed minimal number of operations
    cout << ans << nl;
}

/*
You are given three binary strings
†
†

S
1
,
S
2
,
S
3
S
1
​
 ,S
2
​
 ,S
3
​
  each of length
N
N. Your goal is to make each string contain identical characters (all
0
′
s
0
′
 s or all
1
′
s
1
′
 s).

To achieve this, you can perform the following operation:

Choose
x
,
y
x,y from
{
1
,
2
,
3
}
{1,2,3}.
Choose index
i
,
j
i,j such that
0
≤
i
,
j
<
N
0≤i,j<N.
Swap
S
x
i
S
xi
​
  and
S
y
j
S
yj
​
  (character at
i
t
h
i
th
  index in
S
x
S
x
​
  and character at
j
t
h
j
th
  index in
S
y
S
y
​
 ).
Find the minimum number of operations required to make each string contain identical characters. Print
−
1
−1 if not possible.

†
†
 A binary string is a sequence of characters where each character is either
′
0
′
′
 0
′
  or
′
1
′
′
 1
′
 .

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains
N
N, the length of the string.
The next
3
3 lines of input contain
3
3 binary strings.
Output Format
For each test case, output on a new line the minimum number of operations to required to make all strings have same characters,
−
1
−1 if it is not possible.

Constraints
1
≤
T
≤
1
0
5
1≤T≤10
5

1
≤
N
≤
10
1≤N≤10
Sum of
N
N over all test cases
≤
1
0
5
≤10
5
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Read the number of test cases and process each
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}