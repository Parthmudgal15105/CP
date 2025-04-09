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
    string s;
    cin >> s;
    int res = s.size();
    if (n % 2 == 0)
    {
        // Even length string:
        // We split the string into two groups based on index parity.
        // v[0] counts frequencies for characters at even indices,
        // v[1] counts frequencies for characters at odd indices.
        vector<int> v[2] = {vector<int>(26), vector<int>(26)};
        for (int i = 0; i < n; i++)
        {
            v[i % 2][s[i] - 'a']++;
        }
        // For each group, we find the character with maximum frequency.
        // The number of operations required equals total elements minus this maximum,
        // since we "fix" the positions with the common character.
        for (int i = 0; i < 2; i++)
        {
            int mx = 0;
            for (int j = 0; j < 26; j++)
            {
                mx = max(mx, v[i][j]);
            }
            res -= mx;
        }
        cout << res << endl;
    }
    else
    {
        // Odd length string:
        // We need to delete one character to make the string even.
        // After deletion, indices after the deleted character will shift parity.
        // To handle this, we use two arrays:
        // 'pref' for prefix frequency counts (already processed), and
        // 'suf' for suffix frequency counts (yet to be processed).
        vector<int> pref[2] = {vector<int>(26), vector<int>(26)};
        vector<int> suf[2] = {vector<int>(26), vector<int>(26)};
        // Initialize suffix counts with the entire string frequencies.
        for (int i = n - 1; i >= 0; i--)
        {
            suf[i % 2][s[i] - 'a']++;
        }
        // Try deleting each character one by one.
        for (int i = 0; i < n; i++)
        {
            // Remove the current character from the suffix count
            // as if it's been deleted.
            suf[i % 2][s[i] - 'a']--;
            int ans = n;
            // For both groups (k=0 and k=1), the new distribution after deletion becomes:
            // - prefix for group k (untouched part before deletion)
            // - suffix for the opposite group (since indices shift)
            for (int k = 0; k < 2; k++)
            {
                int mx = 0;
                for (int j = 0; j < 26; j++)
                {
                    mx = max(mx, suf[1 - k][j] + pref[k][j]);
                }
                ans -= mx;
            }
            // Keep the best (minimal) operations needed after deleting a character.
            res = min(res, ans);
            // Update prefix counts with the current character for future iterations.
            pref[i % 2][s[i] - 'a']++;
        }
        cout << res << endl;
    }
}

/*
Sakurako really loves alternating strings. She calls a string s
 of lowercase Latin letters an alternating string if characters in the even positions are the same, if characters in the odd positions are the same, and the length of the string is even.

For example, the strings 'abab' and 'gg' are alternating, while the strings 'aba' and 'ggwp' are not.

As a good friend, you decided to gift such a string, but you couldn't find one. Luckily, you can perform two types of operations on the string:

Choose an index i
 and delete the i
-th character from the string, which will reduce the length of the string by 1
. This type of operation can be performed no more than 1
 time;
Choose an index i
 and replace si
 with any other letter.
Since you are in a hurry, you need to determine the minimum number of operations required to make the string an alternating one.

Input
The first line contains a single integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains a single number n
 (1≤n≤2⋅105
)  — the length of the string.

The second line of each test case contains a string s
, consisting of lowercase Latin letters.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of operations required to turn the string s
 into an alternating one.

Example
InputCopy
10
1
a
2
ca
3
aab
5
ababa
6
acdada
9
ejibmyyju
6
bbccbc
6
abacba
5
bcbca
5
dcbdb
OutputCopy
1
0
1
1
2
6
2
3
1
1
Note
For the string ababa, you can delete the first character to get baba, which is an alternating string.

For the string acdada, you can change the first two characters to get dadada, which is an alternating string.

Solution
Firstly, since first operation can be used at most 1 time, we need to use it only when string has odd length.

Let's assume that the string has even length, then we can look at characters on odd and even positions independently. So, if we change all characters on even positions to the character that which is occurs the most. Same goes to the characters on the odd position.

Now, we have case where we need to delete one character. We can make prefix sum on even positions (let's call pref1[i][c]
 number of c
 on such even i>j
 and s[j]=c
), prefix sum on odd position (let's call it pref2[i][c]
. Definition same as for pref1[i][c]
 but with odd instead of even), suffix sum on even positions (let's call it suff1[i][c]
 and definition same as pref1[i][c]
 but with j>i
 instead of i>j
) and suffix sum on odd positions (let's call it suff2[i][c]
 and definition same as pref2[i][c]
 but with j>i
 instead of i>j
). If we delete character on index i
, our string after i
 shift right and changes parity for all indeces bigger then i
, so to find how many characters c
 there are on even positions after deleting index i
 is pref1[i][c]+suf2[i][c]
. Using this, we can try to delete each character independently and solve the task as it has even length.
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
