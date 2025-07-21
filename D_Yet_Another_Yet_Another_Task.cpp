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
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
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
int inf = -1e8;
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // Read the card values (1-based indexing)
    }
    int ans = inf; // Initialize answer to a very small value

    // Try every possible value for the card Bob could remove (mx)
    for (int mx = -30; mx <= 30; mx++)
    {
        int maxsubarraysum = inf; // Store the best sum for this mx
        vi dp(n + 1);             // dp[i]: max subarray sum ending at i with all elements <= mx
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > mx)
            {
                dp[i] = inf; // Can't include this card in the segment
                continue;
            }
            // Either start a new segment at i, or extend the previous segment
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            maxsubarraysum = max(maxsubarraysum, dp[i]); // Update best sum for this mx
        }
        // After Bob removes the card with value mx, Alice's score is maxsubarraysum - mx
        ans = max(ans, maxsubarraysum - mx); // Keep the maximum possible score
    }
    cout << ans << nl; // Output the answer
}

/*
Alice and Bob are playing yet another card game. This time the rules are the following. There are n
 cards lying in a row in front of them. The i
-th card has value ai
.

First, Alice chooses a non-empty consecutive segment of cards [l;r]
 (l≤r
). After that Bob removes a single card j
 from that segment (l≤j≤r)
. The score of the game is the total value of the remaining cards on the segment (al+al+1+⋯+aj−1+aj+1+⋯+ar−1+ar)
. In particular, if Alice chooses a segment with just one element, then the score after Bob removes the only card is 0
.

Alice wants to make the score as big as possible. Bob takes such a card that the score is as small as possible.

What segment should Alice choose so that the score is maximum possible? Output the maximum score.

Input
The first line contains a single integer n
 (1≤n≤105
) — the number of cards.

The second line contains n
 integers a1,a2,…,an
 (−30≤ai≤30
) — the values on the cards.

Output
Print a single integer — the final score of the game.

Examples
InputCopy
5
5 -2 10 -1 4
OutputCopy
6
InputCopy
8
5 2 5 3 -30 -30 6 9
OutputCopy
10
InputCopy
3
-10 6 -15
OutputCopy
0
Note
In the first example Alice chooses a segment [1;5]
 — the entire row of cards. Bob removes card 3
 with the value 10
 from the segment. Thus, the final score is 5+(−2)+(−1)+4=6
.

In the second example Alice chooses a segment [1;4]
, so that Bob removes either card 1
 or 3
 with the value 5
, making the answer 5+2+3=10
.

In the third example Alice can choose any of the segments of length 1
: [1;1]
, [2;2]
 or [3;3]
. Bob removes the only card, so the score is 0
. If Alice chooses some other segment then the answer will be less than 0
.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
