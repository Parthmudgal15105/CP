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
const ll MOD = 998244353;
/*----------------------------------------------------------------------------*/

ll exp(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll Ans(ll N)
{
    // Explanation:
    // For each round, the game strategy effectively multiplies the outcome by 4 for each move.
    // When N is odd:
    //    - The number of effective moves is (N - 1) / 2.
    //    - Thus, the result is simply 4^((N-1)/2) modulo MOD.
    // When N is even:
    //    - The effective moves are (N/2) - 1.
    //    - Then, a multiplication by 3 adjusts the final result.
    if (N % 2 == 0)
    {
        ll p = exp(4, (N / 2) - 1, MOD); // Compute 4^((N/2)-1) % MOD.
        return (3LL * p) % MOD;          // Multiply by 3 to account for the extra adjustment.
    }
    else
    {
        return exp(4, (N - 1) / 2, MOD); // For odd N, directly compute 4^((N-1)/2) % MOD.
    }
}

void solve()
{
    ll n;
    cin >> n;
    cout << Ans(n) << nl;
}

/*
Shall we play a game
Alice and Bob play a game over
N
N rounds, starting with an initial score of
0
0. Alice takes the first turn.

In the
i
t
h
i
th
​
  round (
1
≤
i
≤
N
1≤i≤N), the current player must either add or subtract
2
i
−
1
2
i−1
  from the current score.

As the game progresses, let:

X
X be the maximum score reached at any point.
Y
Y be the minimum score reached at any point.
Alice’s goal is to minimize the final difference
X
−
Y
X−Y, while Bob aims to maximize it.

Assuming both players play optimally, determine the final value of
X
−
Y
X−Y after all
N
N rounds. Since this value can be very large, output it modulo
998244353
998244353.

Input Format
The first line of input will contain a single integer
T
T, denoting the number of test cases.
Each test case consists a single line of input.
The only line of each test case contains an integer
N
N — the number of rounds played.
Output Format
For each test case, output a single line containing one integer — the final value of
X
−
Y
X−Y modulo
998244353
998244353.

Constraints
1
≤
T
≤
1
0
3
1≤T≤10
3

1
≤
N
≤
1
0
3
1≤N≤10
3

Sample 1:
Input
Output
3
1
2
10
1
3
768
Explanation:
Test Case 1: Alice increases/decreases the score by 1, so the final value of
X
−
Y
=
1
X−Y=1.

Test Case 2: Alice increases/decreases the score by 1. In his turn, Bob increases the score to 3 if the score after the first round is 1 or decreases it to -3, if it is -1. In either case, the final value of
X
−
Y
X−Y is 3.
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
