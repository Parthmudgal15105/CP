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
    string s;
    cin >> n >> s;

    int ans = 0;
    // Iterate over all possible starting positions of substrings
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(10, 0); // Count of each digit (0-9) in the current substring
        int distinct = 0;       // Number of distinct digits in the current substring
        int max_freq = 0;       // Maximum frequency of any digit in the current substring

        // Try all substrings starting at i, but limit length to 100 for efficiency
        for (int j = i; j < n && j - i < 100; j++)
        {
            int d = s[j] - '0'; // Convert character to digit
            if (cnt[d] == 0)
                distinct++;                   // New digit found, increment distinct count
            cnt[d]++;                         // Increment count for this digit
            max_freq = max(max_freq, cnt[d]); // Update max frequency

            // A substring is diverse if no digit appears more than the number of distinct digits
            if (max_freq <= distinct)
                ans++;
        }
    }
    cout << ans << nl; // Output the total number of diverse substrings for this test case
}

/*
A non-empty digit string is diverse if the number of occurrences of each character in it doesn't exceed the number of distinct characters in it.

For example:

string "7" is diverse because 7 appears in it 1
 time and the number of distinct characters in it is 1
;
string "77" is not diverse because 7 appears in it 2
 times and the number of distinct characters in it is 1
;
string "1010" is diverse because both 0 and 1 appear in it 2
 times and the number of distinct characters in it is 2
;
string "6668" is not diverse because 6 appears in it 3
 times and the number of distinct characters in it is 2
.
You are given a string s
 of length n
, consisting of only digits 0
 to 9
. Find how many of its n(n+1)2
 substrings are diverse.

A string a
 is a substring of a string b
 if a
 can be obtained from b
 by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Note that if the same diverse string appears in s
 multiple times, each occurrence should be counted independently. For example, there are two diverse substrings in "77" both equal to "7", so the answer for the string "77" is 2
.

Input
Each test contains multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤105
) — the length of the string s
.

The second line of each test case contains a string s
 of length n
. It is guaranteed that all characters of s
 are digits from 0
 to 9
.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case print one integer — the number of diverse substrings of the given string s
.

Example
InputCopy
7
1
7
2
77
4
1010
5
01100
6
399996
5
23456
18
789987887987998798
OutputCopy
1
2
10
12
10
15
106
Note
In the first test case, the diverse substring is "7".

In the second test case, the only diverse substring is "7", which appears twice, so the answer is 2
.

In the third test case, the diverse substrings are "0" (2
 times), "01", "010", "1" (2
 times), "10" (2
 times), "101" and "1010".

In the fourth test case, the diverse substrings are "0" (3
 times), "01", "011", "0110", "1" (2
 times), "10", "100", "110" and "1100".

In the fifth test case, the diverse substrings are "3", "39", "399", "6", "9" (4
 times), "96" and "996".

In the sixth test case, all 15
 non-empty substrings of "23456" are diverse.
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
