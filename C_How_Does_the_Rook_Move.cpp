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
const ll mod = 1000000007;
/*----------------------------------------------------------------------------*/

// Updated function with in-depth dp explanation:
ll findAns(ll n, vector<ll> &dp)
{
    // dp[i] stores the number of valid final configurations for i free rows/columns.
    // Base case: 0 or 1 free row/column means only one configuration is possible.
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        // Use the cached result to save computation time.
        return dp[n];
    }
    // Two options to extend a configuration:
    // 1. Place a white rook in one free row (reducing free count by 1): findAns(n-1)
    // 2. Place a white rook and get the computer's mirror move,
    //    which uses 2 free rows. There are (n-1) ways to choose the pairing,
    //    and we multiply by 2 for the placement order.
    dp[n] = (findAns(n - 1, dp) % mod + (((n - 1) % mod * findAns(n - 2, dp) % mod) % mod * 2) % mod) % mod;
    return dp[n];
}

// Updated function with dp usage explanation:
void solve()
{
    int dp[(int)3e5 + 5];
    int n, k;
    cin >> n >> k;
    int used = 0;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        used += 2 - (r == c);
    }
    int m = n - used;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= m; i++)
        dp[i] = (dp[i - 1] + 2ll * (i - 1) * dp[i - 2] % mod) % mod;
    cout << dp[m] << "\n";
}

// Explanation of DP (Dynamic Programming) in our solution:
//
// 1. We first calculate how many rows (and columns) remain free after the already played moves.
//    In our updated version, each move uses either 2 free positions (if r != c) or only 1 (if r == c).
//    Let m = n - used, where 'used' is the total number of rows/columns that have been occupied.
//
// 2. We use a dp array where dp[i] represents the number of valid final configurations
//    when i free rows/columns are left.
//
// 3. Base Cases:
//    - dp[0] = 1 : If there are no free rows, the configuration is fixed.
//    - dp[1] = 1 : If there is one free row left, there's only one way to place a rook.
//
// 4. For i free rows (i >= 2), there are 2 choices to form a new configuration:
//    Option A: Place a white rook using one free row.
//              This leaves i-1 free rows, contributing dp[i-1] ways.
//    Option B: Place a white rook and pair it with a mirror move by the computer (uses two rows).
//              There are (i-1) ways to choose a pair and a factor of 2 for the placement order.
//              This contributes 2*(i-1)*dp[i-2] ways.
//
// 5. Thus, the recurrence relation is:
//       dp[i] = dp[i-1] + 2*(i-1)*dp[i-2]   (all calculations are done modulo mod)
//
// 6. We compute dp[2] to dp[m] iteratively and output dp[m] as the final answer.
//
// This approach is efficient given the constraint m ≤ 3e5 and avoids recalculating the same values.

/*
You are given an n×n
 chessboard where you and the computer take turns alternatingly to place white rooks & black rooks on the board respectively. While placing rooks, you have to ensure that no two rooks attack each other. Two rooks attack each other if they share the same row or column regardless of color.

A valid move is placing a rook on a position (r
, c
) such that it doesn't attack any other rook.

You start first, and when you make a valid move in your turn, placing a white rook at position (r
, c
), the computer will mirror you and place a black rook at position (c
, r
) in its turn. If r=c
, then the computer can't mirror your move, and skips its turn.

You have already played k
 moves with the computer (the computer tries to mirror these moves too), and you must continue playing the game until there are no valid moves remaining. How many different final configurations are possible when you continue the game after the k
 moves? It is guaranteed that the k
 moves and the implied computer moves are valid. Since the answer may be large, print it modulo 109+7
.

Two configurations are considered different if there exists a coordinate (r
, c
) which has a rook in one configuration, but not in the other or the color of the rook on the coordinate is different.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤3⋅105
, 0≤k≤n
) — the size of the chessboard and the number of moves you have already played respectively.

Each of the next k
 lines of the test case contains two integers ri
 and ci
, denoting the i
-th move you made.

It is guaranteed that the k
 moves and the implied computer moves are valid.

It is guaranteed that the sum of n
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer on a new line — the total number of possible final configurations modulo 109+7
.

Example
InputCopy
3
4 1
1 2
8 1
7 6
1000 4
4 4
952 343
222 333
90 91
OutputCopy
3
331
671968183
Note
In the first test case, we have a 4×4
 grid and you've already played 1
 move. After you and the computer play a turn, we have a white rook at (1
, 2
), and a black rook at (2
, 1
). There are three possible configurations from this state —

You place a white rook at (3
, 4
) and the computer places a black rook at (4
, 3
) as a response.
You place a white rook at (4
, 3
) and the computer places a black rook at (3
, 4
) as a response.
You place a white rook at (3
, 3
) and then at (4
, 4
), or the other way around. They both result in the same configuration.
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
