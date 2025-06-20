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
    // Notes on the problem:
    // if s_i != s_j, we need a pleasant pair condition
    // if s_i = s_j, it's automatically a good pair

    int n;
    cin >> n;

    // Count frequency of each character (a-z) in the input string
    vector<int> f(26, 0);
    string s;
    cin >> s;
    for (auto x : s)
    {
        f[x - 'a']++;
    }

    // Create a set of pairs: (frequency, character_index)
    // This automatically sorts by frequency (and character as tiebreaker)
    set<pair<int, int>> st;

    for (int i = 0; i < 26; i++)
    {
        st.insert({f[i], i});
    }

    // Greedy construction of the output string:
    // Always pick the most frequent remaining character
    for (int i = 0; i < n; i++)
    {
        // Get the character with highest frequency (last element in the sorted set)
        auto pi = *(--st.end());

        // Remove it from the set
        st.erase(pi);

        // Decrease its frequency by 1 (we used one occurrence)
        pi.first -= 1;

        // Output this character
        cout << (char)('a' + pi.second);

        // Put the updated frequency back into the set
        st.insert(pi);
    }
    cout << "\n";
}

/*
Turtle gives you a string s
, consisting of lowercase Latin letters.

Turtle considers a pair of integers (i,j)
 (1≤i<j≤n
) to be a pleasant pair if and only if there exists an integer k
 such that i≤k<j
 and both of the following two conditions hold:

sk≠sk+1
;
sk≠si
 or sk+1≠sj
.
Besides, Turtle considers a pair of integers (i,j)
 (1≤i<j≤n
) to be a good pair if and only if si=sj
 or (i,j)
 is a pleasant pair.

Turtle wants to reorder the string s
 so that the number of good pairs is maximized. Please help him!

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) — the length of the string.

The second line of each test case contains a string s
 of length n
, consisting of lowercase Latin letters.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the string s
 after reordering so that the number of good pairs is maximized. If there are multiple answers, print any of them.

Example
InputCopy
5
3
abc
5
edddf
6
turtle
8
pppppppp
10
codeforces
OutputCopy
acb
ddedf
urtlet
pppppppp
codeforces
Note
In the first test case, (1,3)
 is a good pair in the reordered string. It can be seen that we can't reorder the string so that the number of good pairs is greater than 1
. bac and cab can also be the answer.

In the second test case, (1,2)
, (1,4)
, (1,5)
, (2,4)
, (2,5)
, (3,5)
 are good pairs in the reordered string. efddd can also be the answer.
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
