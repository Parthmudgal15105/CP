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
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    int ans = 0;

    // Try for each letter from 'a' to 'e'
    for (char ch = 'a'; ch <= 'e'; ch++)
    {
        vector<int> scores;
        // For each word, calculate the "score" for the current letter
        for (auto &w : words)
        {
            int cnt_ch = 0, cnt_other = 0;
            for (char c : w)
            {
                if (c == ch)
                    cnt_ch++; // count occurrences of current letter
                else
                    cnt_other++; // count occurrences of other letters
            }
            // Score: how much this word helps the current letter dominate
            scores.push_back(cnt_ch - cnt_other);
        }
        // Sort scores in descending order to pick the most helpful words first
        sort(scores.rbegin(), scores.rend());
        int sum = 0, cnt = 0;
        // Greedily add words as long as the current letter dominates
        for (int s : scores)
        {
            sum += s;
            if (sum > 0)
                cnt++; // can include this word
            else
                break; // can't include more words for this letter
        }
        ans = max(ans, cnt); // update answer for the best letter
    }
    cout << ans << nl; // print the result for this test case
}

/*
Stephen Queen wants to write a story. He is a very unusual writer, he uses only letters 'a', 'b', 'c', 'd' and 'e'!

To compose a story, Stephen wrote out n
 words consisting of the first 5
 lowercase letters of the Latin alphabet. He wants to select the maximum number of words to make an interesting story.

Let a story be a sequence of words that are not necessarily different. A story is called interesting if there exists a letter which occurs among all words of the story more times than all other letters together.

For example, the story consisting of three words "bac", "aaada", "e" is interesting (the letter 'a' occurs 5
 times, all other letters occur 4
 times in total). But the story consisting of two words "aba", "abcde" is not (no such letter that it occurs more than all other letters in total).

You are given a sequence of n
 words consisting of letters 'a', 'b', 'c', 'd' and 'e'. Your task is to choose the maximum number of them to make an interesting story. If there's no way to make a non-empty story, output 0
.

Input
The first line contains one integer t
 (1≤t≤5000
) — the number of test cases. Then t
 test cases follow.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the number of the words in the sequence. Then n
 lines follow, each of them contains a word — a non-empty string consisting of lowercase letters of the Latin alphabet. The words in the sequence may be non-distinct (i. e. duplicates are allowed). Only the letters 'a', 'b', 'c', 'd' and 'e' may occur in the words.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
; the sum of the lengths of all words over all test cases doesn't exceed 4⋅405
.

Output
For each test case, output the maximum number of words that compose an interesting story. Print 0 if there's no way to make a non-empty interesting story.

Example
InputCopy
6
3
bac
aaada
e
3
aba
abcde
aba
2
baba
baba
4
ab
ab
c
bc
5
cbdca
d
a
d
e
3
b
c
ca
OutputCopy
3
2
0
2
3
2
Note
In the first test case of the example, all 3
 words can be used to make an interesting story. The interesting story is "bac aaada e".

In the second test case of the example, the 1
-st and the 3
-rd words can be used to make an interesting story. The interesting story is "aba aba". Stephen can't use all three words at the same time.

In the third test case of the example, Stephen can't make a non-empty interesting story. So the answer is 0
.

In the fourth test case of the example, Stephen can use the 3
-rd and the 4
-th words to make an interesting story. The interesting story is "c bc".
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
