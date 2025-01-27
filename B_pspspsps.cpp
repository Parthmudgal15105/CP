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

/*----------------------------------------------------------------------------*/
void solve()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    // 2. Convert first or last character if it's 's' (first) or 'p' (last) to '.' to avoid outer constraints.
    if (s[0] == 's')
        s[0] = '.';
    if (s.back() == 'p')
        s.back() = '.';

    /*
      Explanation:
      If the string starts with 's', convert it to '.' to remove
      the prefix constraint. Similarly, if the string ends with 'p',
      convert it to '.' to remove the suffix constraint.

      Afterward, if we find at least one 'p' and at least one 's'
      in the remaining string, the constraints contradict, so answer "NO".
      Otherwise, answer "YES".
    */

    // 3. Check if there's at least one 'p' and at least one 's' in s.
    bool found_p = false;
    bool found_s = false;
    for (const auto c : s)
    {
        switch (c)
        {
        case 'p':
            found_p = true;
            break;
        case 's':
            found_s = true;
            break;
        }
    }

    // 4. If both exist, it's "NO"; else "YES".
    cout << (found_p && found_s ? "NO" : "YES") << '\n';
}

/*
Cats are attracted to pspspsps, but Evirir, being a dignified dragon, is only attracted to pspspsps with oddly specific requirements...

Given a string s=s1s2…sn
 of length n
 consisting of characters p, s, and . (dot), determine whether a permutation∗
 p
 of length n
 exists, such that for all integers i
 (1≤i≤n
):

If si
 is p, then [p1,p2,…,pi]
 forms a permutation (of length i
);
If si
 is s, then [pi,pi+1,…,pn]
 forms a permutation (of length n−i+1
);
If si
 is ., then there is no additional restriction.
∗
A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤500
), the length of s
.

The second line of each test case contains a string s
 of length n
 that consists of the characters p, s, and ..

It is guaranteed that the sum of n
 over all test cases does not exceed 5000
.

Output
For each test case, output YES or NO on a line. Output YES if there is such a permutation and NO otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
9
4
s.sp
6
pss..s
5
ppppp
2
sp
4
.sp.
8
psss....
1
.
8
pspspsps
20
....................
OutputCopy
YES
NO
YES
YES
NO
NO
YES
NO
YES
Note
For the first test case, one permutation that works is p=[3,4,1,2]
. The restrictions are as follows:

s1=
 s: [p1,p2,p3,p4]=[3,4,1,2]
 forms a permutation.
s2=
 .: No additional restriction.
s3=
 s: [p3,p4]=[1,2]
 forms a permutation.
s4=
 p: [p1,p2,p3,p4]=[3,4,1,2]
 forms a permutation.
For the second test case, it can be proven that there is no permutation that satisfies all restrictions.

For the third test case, one permutation that satisfies the constraints is p=[1,2,3,4,5]
.


ANSWER
Since the entire p
 must be a permutation, if s1=
s, we can set s1=
., and if sn=
p, we can set sn=
..

After that, the answer is YES if and only if all non-dot characters in s
 are all p or s.

If all non-dot characters are p, we can choose the permutation p=[1,2,…,n]
. If all non-dot characters are s, we can choose p=[n,n−1,…,1]
.

Otherwise, there exists both a p and a s. Suppose for contradiction that there is a solution. Let a
 and b
 represent the subarrays represented by the p and s respectively. Without loss of generality, suppose a
 is the shorter subarray.

Since b
 is also a permutation, the elements of a
 must be in b
. Since p
 is a permutation, a
 must be a subarray of b
.
However, b
 cannot contain a
: since b
 is not the entire p
, b
 does not contain p1
. However, a
 contains p1
. Contradiction.
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
