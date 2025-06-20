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
    int a, b, c;
    cin >> a >> b >> c;

    int p = b - a;

    c -= p;

    if (c - b >= 0 && (c - b) % 3 == 0)
    {
        cyes;
    }
    else
    {
        cno;
    }
}

/*
Monocarp placed three decks of cards in a row on the table. The first deck consists of a
 cards, the second deck consists of b
 cards, and the third deck consists of c
 cards, with the condition a<b<c
.

Monocarp wants to take some number of cards (at least one, but no more than c
) from the third deck and distribute them between the first two decks so that each of the taken cards ends up in either the first or the second deck. It is possible that all the cards taken from the third deck will go into the same deck.

Your task is to determine whether Monocarp can make the number of cards in all three decks equal using the described operation.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The only line of each test case contains three integers a,b
, and c
 (1≤a,b,c≤108
) — the number of cards in the first, second, and third decks, respectively.

Additional constraint on the input: a<b<c
.

Output
For each test case, output "YES" (without quotes) if Monocarp can make the number of cards in all three decks equal using the described operation. Otherwise, output "NO" (without quotes).

Example
InputCopy
4
3 5 10
12 20 30
3 5 7
1 5 6
OutputCopy
YES
NO
YES
NO
Note
In the first test case, Monocarp has to take 4
 cards from the third deck, put 3
 cards in the first deck, and 1
 card in the second deck. Thus, there will be 6
 cards in all three decks.

In the second test case, it is impossible to make the number of cards in all three decks equal.

In the third test case, Monocarp has to take 2
 cards from the third deck and put both in the first deck. Thus, there will be 5
 cards in all three decks.

In the fourth test case, it is also impossible to make the number of cards in all three decks equal.
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
