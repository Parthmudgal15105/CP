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
    // Read number of cows (n) and cards per cow (m)
    int n, m;
    cin >> n >> m;

    // Create 2D vector to store cards for each cow
    vector<vector<int>> cards(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cards[i][j];
        }
    }

    // Create owner array where owner[x] = index of cow who owns card x
    vector<int> owner(n * m, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            owner[cards[i][j]] = i;
        }
    }

    // Create permutation array p
    vector<int> p(n);
    // Key insight: For valid solution, all cards with same remainder when divided by n
    // must belong to the same cow
    for (int k = 0; k < n; k++)
    {
        int real = owner[k]; // Get owner of first card in this remainder group
        // Check all cards that have same remainder when divided by n
        for (int c = k; c < n * m; c += n)
        {
            if (owner[c] != real)
            {
                // If any card has different owner, solution impossible
                cout << -1 << nl;
                return;
            }
        }
        p[k] = real; // Add this cow to permutation
    }

    // Print the valid permutation (1-indexed)
    for (int i = 0; i < n; i++)
    {
        cout << p[i] + 1;
        if (i < n - 1)
            cout << " ";
    }
    cout << nl;
}

/*
Farmer John's n
 cows are playing a card game! Farmer John has a deck of n⋅m
 cards numbered from 0
 to n⋅m−1
. He distributes m
 cards to each of his n
 cows.

Farmer John wants the game to be fair, so each cow should only be able to play 1
 card per round. He decides to determine a turn order, determined by a permutation∗
 p
 of length n
, such that the pi
'th cow will be the i
'th cow to place a card on top of the center pile in a round.

In other words, the following events happen in order in each round:

The p1
'th cow places any card from their deck on top of the center pile.
The p2
'th cow places any card from their deck on top of the center pile.
...
The pn
'th cow places any card from their deck on top of the center pile.
There is a catch. Initially, the center pile contains a card numbered −1
. In order to place a card, the number of the card must be greater than the number of the card on top of the center pile. Then, the newly placed card becomes the top card of the center pile. If a cow cannot place any card in their deck, the game is considered to be lost.

Farmer John wonders: does there exist p
 such that it is possible for all of his cows to empty their deck after playing all m
 rounds of the game? If so, output any valid p
. Otherwise, output −1
.

∗
A permutation of length n
 contains each integer from 1
 to n
 exactly once

Input
The first line contains an integer t
 (1≤t≤400
) — the number of test cases.

The first line of each test case contains two integers n
 and m
 (1≤n⋅m≤2000
) — the number of cows and the number of cards each cow receives.

The following n
 lines contain m
 integers each – the cards received by each cow. It is guaranteed all given numbers (across all n
 lines) are distinct and in the range from 0
 to n⋅m−1
, inclusive.

It is guaranteed the sum of n⋅m
 over all test cases does not exceed 2000
.

Output
For each test case, output the following on a new line:

If p
 exists, output n
 space-separated integers p1,p2,…,pn
.
Otherwise, output −1
.
Example
InputCopy
4
2 3
0 4 2
1 5 3
1 1
0
2 2
1 2
0 3
4 1
1
2
0
3
OutputCopy
1 2
1
-1
3 1 2 4
Note
In the first test case, one turn order that allows all cards to be played is by having the first cow go before the second cow. The cards played will be 0→1→2→3→4→5
.

In the second test case, there is only one cow, so having the cow play all of her cards in increasing order will empty the deck.

In the third test case, it can be shown there is no valid turn order that allows all cards to be played
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
