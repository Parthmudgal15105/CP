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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = n - 2; i >= 0 && k > 0; i--)
    {
        if (s[i] == '0' && s[i + 1] == '1')
        {
            s[i] = '1';
            k--;
        }
    }

    int ones = 0;
    for (char c : s)
        if (c == '1')
            ones++;
    cout << ones << nl;
}

/*
Maximum Ones
You are given a binary string
S
S of length
N
N consisting only of characters
0
0 and
1
1. You are allowed to perform at most
K
K operations on this string. In each operation, you can choose an index
i
i (where
0
≤
i
<
N
−
1
0≤i<N−1) and update the character at position
i
i as follows:

S
i
=
max
⁡
(
S
i
,
S
i
+
1
)
S
i
​
 =max(S
i
​
 ,S
i+1
​
 )
Here, the maximum is taken in the numerical sense, i.e.,
′
1
′
′
 1
′
  is considered greater than
′
0
′
′
 0
′
 . This operation essentially means that if
S
i
+
1
S
i+1
​
  is
′
1
′
′
 1
′
 , then
S
i
S
i
​
  becomes
′
1
′
′
 1
′
  regardless of its previous value.

Your task is to determine the maximum possible number of
1
1s in the string after performing at most
K
K such operations.

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers
N
N and
K
K.
The second line of each test case contains a binary string
S
S of length
N
N, consisting of the characters
0
0 and
1
1.
Output Format
For each test case, output on a new line the maximum number of
1
1s that can be achieved in the string after performing at most
K
K operations.

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
0
≤
K
≤
N
0≤K≤N
S
i
∈
{
0
,
1
}
S
i
​
 ∈{0,1}
Sample 1:
Input
Output
3
3 1
101
3 1
001
3 2
001
3
2
3
Explanation:
Test Case 1: You can apply the operation at index
i
=
1
i=1 and the string changes to "111". Maximum possible ones = 3.
Test Case 2: You can apply the operation at index
i
=
1
i=1 and the string changes to "011". Maximum possible ones = 2.
Test Case 3: You can apply the operation at index
i
=
1
i=1 and the string changes to "011". The next operation will be applied at index
i
=
0
i=0 and the string changes to "111". Maximum possible ones = 3.
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