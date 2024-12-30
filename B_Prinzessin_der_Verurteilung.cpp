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
    int n;
    cin >> n;
    string s;
    cin >> s;

    // STEP 1: Check for missing single characters
    {
        // Create array to mark which letters exist in string
        // count[0] represents 'a', count[1] represents 'b', etc.
        int count[26] = {0};

        // Mark each character as found in our string
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a'] = 1; // Convert char to index (e.g., 'a'->0, 'b'->1)
        }

        // Find first unused character
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
            {
                // If we find unused character, it's our answer
                cout << (char)('a' + i) << endl;
                return;
            }
        }
    }

    // STEP 2: Check for missing two-character combinations
    {
        // Store all existing two-character substrings in a set
        set<string> st;
        for (int i = 0; i < n - 1; i++)
        {
            string temp = "";
            temp += s[i];     // First character
            temp += s[i + 1]; // Adjacent character
            st.insert(temp);  // Add this pair to set
        }

        // Try all possible two-letter combinations
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string temp = "";
                temp += (char)('a' + i); // First letter
                temp += (char)('a' + j); // Second letter
                // If this combination doesn't exist in our string, it's our answer
                if (st.find(temp) == st.end())
                {
                    cout << temp << endl;
                    return;
                }
            }
        }
    }

    // STEP 3: Check for missing three-character combinations
    {
        // Store all existing three-character substrings
        set<string> st;
        for (int i = 0; i < n - 2; i++)
        {
            string temp = "";
            temp += s[i];     // First character
            temp += s[i + 1]; // Second character
            temp += s[i + 2]; // Third character
            st.insert(temp);
        }

        // Optimization: We only check combinations starting with 'a'
        // because we know shorter strings and lexicographically smaller
        // strings were already checked
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string temp = "a";       // First letter always 'a'
                temp += (char)('a' + i); // Second letter
                temp += (char)('a' + j); // Third letter
                if (st.find(temp) == st.end())
                {
                    cout << temp << endl;
                    return;
                }
            }
        }
    }
}

/*
I, Fischl, Prinzessin der Verurteilung, descend upon this land by the call of fate an — Oh, you are also a traveler from another world? Very well, I grant you permission to travel with me.

It is no surprise Fischl speaks with a strange choice of words. However, this time, not even Oz, her raven friend, can interpret her expressions! Maybe you can help us understand what this young princess is saying?

You are given a string of n
 lowercase Latin letters, the word that Fischl just spoke. You think that the MEX of this string may help you find the meaning behind this message. The MEX of the string is defined as the shortest string that doesn't appear as a contiguous substring in the input. If multiple strings exist, the lexicographically smallest one is considered the MEX. Note that the empty substring does NOT count as a valid MEX.

A string a
 is lexicographically smaller than a string b
 if and only if one of the following holds:

a
 is a prefix of b
, but a≠b
;
in the first position where a
 and b
 differ, the string a
 has a letter that appears earlier in the alphabet than the corresponding letter in b
.
A string a
 is a substring of a string b
 if a
 can be obtained from b
 by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Find out what the MEX of the string is!

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). Description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤1000
) — the length of the word. The second line for each test case contains a single string of n
 lowercase Latin letters.

The sum of n
 over all test cases will not exceed 1000
.

Output
For each test case, output the MEX of the string on a new line.

Example
InputCopy
3
28
qaabzwsxedcrfvtgbyhnujmiklop
13
cleanairactbd
10
aannttoonn
OutputCopy
ac
f
b
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
