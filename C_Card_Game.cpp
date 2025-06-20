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
    string s;
    cin >> s;
    int n = s.size();

    if (s == "AB")
    {
        cout << "Alice" << nl;
        return;
    }
    if (s == "BA")
    {
        cout << "Bob" << nl;
        return;
    }

    if (s[0] == s[n - 1])
    {
        if (s[0] == 'A')
            cout << "Alice" << nl;
        else
            cout << "Bob" << nl;
        return;
    }

    if (s[n - 2] == 'A' && s[n - 1] == 'A')
    {
        cout << "Alice" << nl;
        return;
    }
    if (s[n - 2] == 'B' && s[n - 1] == 'B')
    {
        cout << "Alice" << nl;
        return;
    }
}
/*
Alice and Bob are playing a game. They have n
 cards numbered from 1
 to n
. At the beginning of the game, some of these cards are given to Alice, and the rest are given to Bob.

Card with number i
 beats card with number j
 if and only if i>j
, with one exception: card 1
 beats card n
.

The game continues as long as each player has at least one card. During each turn, the following occurs:

Alice chooses one of her cards and places it face up on the table;
Bob, seeing Alice's card, chooses one of his cards and places it face up on the table;
if Alice's card beats Bob's card, both cards are taken by Alice. Otherwise, both cards are taken by Bob.
A player can use a card that they have taken during one of the previous turns.

The player who has no cards at the beginning of a turn loses. Determine who will win if both players play optimally.

Input
The first line contains a single integer t
 (1≤t≤5000
) — the number of test cases.

Each test case consists of two lines:

the first line contains a single integer n
 (2≤n≤50
) — the number of cards;
the second line contains n
 characters, each either A or B. If the i
-th character is A, then card number i
 is initially given to Alice; otherwise, it is given to Bob.
Additional constraint on the input: in each test case, at least one card is initially given to Alice, and at least one card is initially given to Bob.

Output
For each test case, output Alice if Alice wins with optimal play, or Bob if Bob wins. It can be shown that if both players play optimally, the game will definitely end in a finite number of turns with one of the players winning.

Example
InputCopy
8
2
AB
2
BA
4
ABAB
4
BABA
3
BAA
5
AAAAB
5
BAAAB
6
BBBAAA
OutputCopy
Alice
Bob
Bob
Bob
Alice
Alice
Bob
Alice
Note
In the first test case, Alice has only one card, and Bob has only one card. Since Alice's card beats Bob's card, she wins after the first turn.

In the second test case, Alice has only one card, and Bob has only one card. Since Bob's card beats Alice's card, he wins after the first turn.

In the third test case, there are two possible game scenarios:

if Alice plays the card 1
 on the first turn, Bob can respond with the card 2
 and take both cards. Then, Alice has to play the card 3
 on the second turn, and Bob will respond by playing the card 4
. Then, he wins;
if Alice plays the card 3
 on the first turn, Bob can respond with the card 4
 and take both cards. Then, Alice has to play the card 1
, and Bob can respond either with the card 2
 or the card 3
. Then, he wins.
In the fourth test case, there are two possible game scenarios:

if Alice plays the card 2
 on the first turn, Bob can respond with the card 3
 and take both cards. Then, Alice has to play the card 4
 on the second turn, and Bob will respond by playing the card 1
. Then, he wins;
if Alice plays the card 4
 on the first turn, Bob can respond with the card 1
 and take both cards. Then, Alice has to play the card 2
, and Bob can respond either with the card 3
 or the card 4
. Then, he wins.
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
