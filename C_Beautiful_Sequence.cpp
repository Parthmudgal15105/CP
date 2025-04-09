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
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

void solve()
{
    int n;
    cin >> n;

    // dp states:
    // dp[0]: count of the empty subsequence (always 1)
    // dp[1]: count of subsequences that have chosen a '1' as the start (first element of the pattern)
    // dp[2]: count of subsequences that have a '1' followed by at least one '2' (middle part)
    // dp[3]: count of complete beautiful subsequences (pattern: 1, one or more 2's, then 3)
    vector<int> dp(4, 0);
    dp[0] = 1;

    while (n--)
    {
        int x;
        cin >> x;

        // When x is 2:
        //   We can extend any subsequence that already has some 2's by including this new 2.
        //   This doubles the count in dp[2] since for each current subsequence ending in 2,
        //   we have the option to append the new 2.
        if (x == 2)
        {
            dp[x] = add(dp[x], dp[x]);
        }

        // Transition: For any x (1, 2 or 3), adding this element to all subsequences
        // in state x-1 will produce new subsequences in state x.
        // For example:
        // x == 1: from empty to [1]  => dp[1] += dp[0]
        // x == 2: from a subsequence ending with 1 to now include 2 => dp[2] += dp[1]
        // x == 3: from a subsequence that includes some 2's to now complete with 3 => dp[3] += dp[2]
        dp[x] = add(dp[x], dp[x - 1]);
    }

    // dp[3] now holds the count of beautiful subsequences of the pattern 1, (2,...,2),3.
    cout << dp[3] << nl;
}

/*
Let's call an integer sequence beautiful if the following conditions hold:

its length is at least 3
;
for every element except the first one, there is an element to the left less than it;
for every element except the last one, there is an element to the right larger than it;
For example, [1,4,2,4,7]
 and [1,2,4,8]
 are beautiful, but [1,2]
, [2,2,4]
, and [1,3,5,3]
 are not.

Recall that a subsequence is a sequence that can be obtained from another sequence by removing some elements without changing the order of the remaining elements.

You are given an integer array a
 of size n
, where every element is from 1
 to 3
. Your task is to calculate the number of beautiful subsequences of the array a
. Since the answer might be large, print it modulo 998244353
.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (3≤n≤2⋅105
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤3
).

Additional constraint on the input: the sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a single integer — the number of beautiful subsequences of the array a
, taken modulo 998244353
.

Example
InputCopy
4
7
3 2 1 2 2 1 3
4
3 1 2 2
3
1 2 3
9
1 2 3 2 1 3 2 2 3
OutputCopy
3
0
1
22
Note
In the first test case of the example, the following subsequences are beautiful:

[a3,a4,a7]
;
[a3,a5,a7]
;
[a3,a4,a5,a7]
.

ANSWER ->
Let's change the definition of a beautiful sequence a bit. We can prove that the condition "for every element except the first one, there is an element to the left less than it" is equivalent to "the first element is less than every other element in the sequence". We can prove that these two conditions are equivalent by induction:

for the 2
-nd element of the sequence s2
, the only element to the left is the 1
-st (s1
), so s1<s2
;
assume we have proved that, for every i∈[2,k]
, s1<si
. Let's prove that s1<si+1
. Suppose that the element to the left of si+1
 which is less than si+1
 is sj
; if j=1
, then obviously, s1<si+1
; otherwise, s1<sj
 and sj<si+1
, so s1<si+1
.
Using similar induction, we can prove that "for every element except the last one, there is an element to the right larger than it" is the same as "the last element is greater than every other element in the sequence".

Since the array consists only of 1
, 2
 and 3
, we can notice that there is only one possible beautiful sequence pattern: 122...223 (i. e. one 1
, followed by any number of consecutive 2
 and one final 3
). Any other pattern is invalid: the leftmost element should be strictly less than every element in the middle (every element from the 2
-nd to the second-to-last), and the rightmost should be strictly greater than every element in the middle; so, the leftmost element should be 1
, the rightmost element should be 3
, and every element in the middle should be 2
.

In order to calculate the number of subsequences that match the aforementioned pattern, we can use dynamic programming. Let dpi,j
 be the number of subsequences if we have considered the first i
 elements of the array, and the current state is j
 (for example, state 0
 means that the sequence is empty, state 1
 means that we have taken the element equal to 1
, state 2
 means that we have taken some number of 2
's, state 3
 means that we have taken the element 3
 and the sequence is finished). The transitions in this dynamic programming are pretty simple and can be done in O(1)
 for each state.

So the total complexity of the solution is O(n)
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
