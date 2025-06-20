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

const int N = 2e5 + 10, SQR = 1e3;
const int INF = 1e9 + 10, MOD = 998244353;
const long double EPS = 1e-5, PI = 3.14159265359;
const ll LINF = 1e18;

pair<int, int> wins[N];

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        wins[i] = {0, 0};
    }

    // Read the first two athletes' strengths
    int first, second;
    cin >> first >> second;
    int mx, mx_i;
    // Determine which of the first two athletes is stronger
    // The stronger one wins the first round and goes to the front of the line
    if (first > second)
    {
        mx = first; // Current maximum strength
        mx_i = 1;   // Index of athlete with maximum strength
    }
    else
    {
        mx = second;
        mx_i = 2;
    }
    int last_round = 1; // Track when the current strongest athlete started winning

    // Process remaining athletes (3 to n)
    for (int i = 3; i <= n; i++)
    {
        int a;
        cin >> a;

        int round = i - 1; // Current round number (rounds start from 1)

        // If we found a stronger athlete
        if (mx < a)
        {
            // Record the previous strongest athlete's winning period
            // They won from last_round to (round-1) inclusive
            wins[mx_i] = {last_round, round - 1};

            // Update to the new strongest athlete
            mx = a;
            mx_i = i;
            last_round = round; // New strongest athlete starts winning from this round
        }
        // If current max is still the strongest, they continue winning (no update needed)
    }

    // Process queries
    while (q--)
    {
        int i, k;
        cin >> i >> k;

        // Case 1: Query is about the overall strongest athlete
        // They win every round after they first reach the front of the line
        if (i == mx_i)
        {
            // Calculate how many rounds they win out of the first k rounds
            // They start winning from last_round onwards
            cout << max(0, k - last_round + 1) << '\n';
        }
        // Case 2: Athlete who never won a round
        else if (wins[i].first == 0)
        {
            cout << "0\n";
        }
        else
        {
            // For other athletes, calculate the winning rounds based on their recorded periods
            cout << max(0, min(k - wins[i].first + 1, wins[i].second - wins[i].first + 1)) << '\n';
        }
    }
}

/*
Burenka is about to watch the most interesting sporting event of the year — a fighting tournament organized by her friend Tonya.

n
 athletes participate in the tournament, numbered from 1
 to n
. Burenka determined the strength of the i
-th athlete as an integer ai
, where 1≤ai≤n
. All the strength values are different, that is, the array a
 is a permutation of length n
. We know that in a fight, if ai>aj
, then the i
-th participant always wins the j
-th.

The tournament goes like this: initially, all n
 athletes line up in ascending order of their ids, and then there are infinitely many fighting rounds. In each round there is exactly one fight: the first two people in line come out and fight. The winner goes back to the front of the line, and the loser goes to the back.

Burenka decided to ask Tonya q
 questions. In each question, Burenka asks how many victories the i
-th participant gets in the first k
 rounds of the competition for some given numbers i
 and k
. Tonya is not very good at analytics, so he asks you to help him answer all the questions.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers n
 and q
 (2≤n≤105
, 1≤q≤105
) — the number of tournament participants and the number of questions.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the array a
, which is a permutation.

The next q
 lines of a test case contain questions. Each line contains two integers i
 and k
 (1≤i≤n
, 1≤k≤109
) — the number of the participant and the number of rounds.

It is guaranteed that the sum of n
 and the sum of q
 over all test cases do not exceed 105
.

Output
For each Burenka's question, print a single line containing one integer — the answer to the question.

Example
InputCopy
3
3 1
3 1 2
1 2
4 2
1 3 4 2
4 5
3 2
5 2
1 2 3 5 4
5 1000000000
4 6
OutputCopy
2
0
1
0
4
Note
In the first test case, the first numbered athlete has the strength of 3
, in the first round he will defeat the athlete with the number 2
 and the strength of 1
, and in the second round, the athlete with the number 3
 and the strength of 2
.

In the second test case, we list the strengths of the athletes fighting in the first 5
 fights: 1
 and 3
, 3
 and 4
, 4
 and 2
, 4
 and 1
, 4
 and 3
. The participant with the number 4
 in the first 5
 rounds won 0
 times (his strength is 2
). The participant with the number 3
 has a strength of 4
 and won 1
 time in the first two fights by fighting 1
 time.



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
