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
    int n, k;
    cin >> n >> k;
    string bs;
    cin >> bs;

    int ones = 0;
    for (char c : bs)
    {
        if (c == '1')
            ones++;
    }
    if (ones == 0)
    {
        cout << "Alice" << nl;
        return;
    }

    if (k == 1)
    {
        if (ones % 2 == 1)
            cout << "Alice" << nl;
        else
            cout << "Bob" << nl;
        return;
    }
    if (ones == n)
    {
        int x = n / k;
        if (x % 2 == 1)
            cout << "Alice" << nl;
        else
            cout << "Bob" << nl;
        return;
    }
    int x = ones / k;
    if (x % 2 == 0)
    {
        cout << "Alice" << nl;
    }
    else
    {
        cout << "Bob" << nl;
    }
}

/*
Alice and Bob are given a binary string s
 of length n
, and an integer k
 (1≤k<n
).

Alice wins if she is able to transform all characters of s
 into zeroes. If Alice is unable to win in a finite number of moves, then Bob wins.

Alice and Bob take turns, with Alice going first.

On Alice's turn, she may choose any subsequence∗
 of length k
 in s
, then set all characters in that subsequence to zero.
On Bob's turn, he may choose any substring†
 of length k
 in s
, then set all characters in that substring to one.
Note that Alice wins if the string consists of all zeros at any point during the game, including in between Alice's and Bob's turns.

Determine who wins with optimal play.

∗
A subsequence of a string s
 is a set of characters in s
. Note that these characters do not have to be adjacent.

†
A substring of a string s
 is a contiguous group of characters in s
. Note that these characters must be adjacent.

Input
The first line contains an integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains two integers n
 and k
 (2≤n≤2⋅105
, 1≤k<n
).

The second line of each test case contains a binary string s
 of length n
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "Alice" if Alice wins with optimal play, and "Bob" if Bob wins with optimal play.

You can output the answer in any case (upper or lower). For example, the strings "aLiCe", "alice", "ALICE", and "alICE" will be recognized as "Alice".

Example
InputCopy
6
5 2
11011
7 4
1011011
6 1
010000
4 1
1111
8 3
10110110
6 4
111111
OutputCopy
Bob
Alice
Alice
Bob
Bob
Alice
Note
In the third sample, Alice can choose the subsequence consisting of s2
, turning s
 into 000000
. Then she wins immediately.

In the fourth sample, it can be shown that there is no way for Alice to guarantee that she can turn s
 into 0000
 within a finite number of moves.



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
