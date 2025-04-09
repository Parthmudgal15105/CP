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
    ll n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vll st;
    sort(v.begin(), v.end());
    st.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            st.push_back(v[i]);
        }
    }
    for (int i = st.size() - 1; i > 0; i--)
    {
        st[i] = st[i] - st[i - 1];
    }
    bool ans = true; // alice will win
    for (int i = 0; i < st.size(); i++)
    {
        if (i == st.size() - 1)
            break;
        if (st[i] == 1)
        {
            ans = !ans;
        }
        else
        {
            break;
        }
    }
    if (ans)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
}

/*
Alice and Bob are playing a game on n
 piles of stones. On each player's turn, they select a positive integer k
 that is at most the size of the smallest nonempty pile and remove k
 stones from each nonempty pile at once. The first player who is unable to make a move (because all piles are empty) loses.

Given that Alice goes first, who will win the game if both players play optimally?

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of piles in the game.

The next line of each test case contains n
 integers a1,a2,…an
 (1≤ai≤109
), where ai
 is the initial number of stones in the i
-th pile.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single line with the name of the winner, assuming both players play optimally. If Alice wins, print "Alice", otherwise print "Bob" (without quotes).

Example
InputCopy
7
5
3 3 3 3 3
2
1 7
7
1 3 9 7 4 2 100
3
1 2 3
6
2 1 3 4 2 4
8
5 7 2 9 6 3 3 2
1
1000000000
OutputCopy
Alice
Bob
Alice
Alice
Bob
Alice
Alice
Note
In the first test case, Alice can win by choosing k=3
 on her first turn, which will empty all of the piles at once.

In the second test case, Alice must choose k=1
 on her first turn since there is a pile of size 1
, so Bob can win on the next turn by choosing k=6
.
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
