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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int i = n - 1; // Pointer for s, starting from the end
    int f = 1;     // Flag to check if t can be formed

    // Traverse t from the end to the beginning
    for (int j = m - 1; j >= 0; j--)
    {
        // Move i leftwards in s until we find a character matching t[j]
        // Each time we skip a character (i.e., s[i] != t[j]), it simulates a backspace
        while (i >= 0 && s[i] != t[j])
        {
            i -= 2; // Skip current character and one more (simulate backspace)
        }
        // If i < 0, we have run out of characters in s before matching t[j]
        if (i < 0)
        {
            f = 0;
            break;
        }
        // Move to the previous character in s for the next round
        i -= 1;
    }
    // If all characters in t are matched, print YES, else NO
    if (f)
    {
        cyes;
    }
    else
    {
        cno;
    }
}

/*
You are given two strings s
 and t
, both consisting of lowercase English letters. You are going to type the string s
 character by character, from the first character to the last one.

When typing a character, instead of pressing the button corresponding to it, you can press the "Backspace" button. It deletes the last character you have typed among those that aren't deleted yet (or does nothing if there are no characters in the current string). For example, if s
 is "abcbd" and you press Backspace instead of typing the first and the fourth characters, you will get the string "bd" (the first press of Backspace deletes no character, and the second press deletes the character 'c'). Another example, if s
 is "abcaa" and you press Backspace instead of the last two letters, then the resulting text is "a".

Your task is to determine whether you can obtain the string t
, if you type the string s
 and press "Backspace" instead of typing several (maybe zero) characters of s
.

Input
The first line contains a single integer q
 (1≤q≤105
) — the number of test cases.

The first line of each test case contains the string s
 (1≤|s|≤105
). Each character of s
 is a lowercase English letter.

The second line of each test case contains the string t
 (1≤|t|≤105
). Each character of t
 is a lowercase English letter.

It is guaranteed that the total number of characters in the strings over all test cases does not exceed 2⋅105
.

Output
For each test case, print "YES" if you can obtain the string t
 by typing the string s
 and replacing some characters with presses of "Backspace" button, or "NO" if you cannot.

You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

Example
InputCopy
4
ababa
ba
ababa
bb
aaa
aaaa
aababa
ababa
OutputCopy
YES
NO
NO
YES
Note
Consider the example test from the statement.

In order to obtain "ba" from "ababa", you may press Backspace instead of typing the first and the fourth characters.

There's no way to obtain "bb" while typing "ababa".

There's no way to obtain "aaaa" while typing "aaa".

In order to obtain "ababa" while typing "aababa", you have to press Backspace instead of typing the first character, then type all the remaining characters.



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
