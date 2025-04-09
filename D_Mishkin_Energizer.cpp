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
    string s;
    cin >> s;

    vector<int> ans;
    int j = -1; // Tracks the last index at which an operation was applied

    // Loop through string to find adjacent characters that differ.
    for (int i = 0; i < n - 1; i++)
    {
        // If the adjacent characters are same, no operation can be applied here.
        if (s[i] == s[i + 1])
        {
            continue;
        }
        int x = i - j;      // Distance from the last operation position (or start if none)
        int c = ans.size(); // Current count of operations already performed
        // Insert operations: each valid gap requires 2*x operations.
        for (int ii = 0; ii < 2 * x; ii++)
        {
            ans.push_back(i + c + 1); // Calculate insertion index adjusted by previous operations.
        }
        j = i; // Update j to the current index after processing the gap.
    }
    // If no valid gap was found, it's impossible to balance.
    if (j == -1)
    {
        cout << -1 << nl;
        return;
    }
    int x = n - j - 1; // Remaining gap after the last operation index.
    // Process the trailing segment by adding the necessary operations.
    for (int ii = 0; ii < 2 * x; ii++)
    {
        ans.push_back(n + ans.size() - x); // Adjust the insertion index for the trailing segment.
    }
    // Output the total number of operations performed.
    cout << ans.size() << nl;
    // List all the operation positions.
    for (auto i : ans)
    {
        cout << i << nl;
    }
}

/*
In anticipation of a duel with his old friend Fernan, Edmond is preparing an energy drink called "Mishkin Energizer". The drink consists of a string s
 of length n
, made up only of the characters L, I, and T, which correspond to the content of three different substances in the drink.

We call the drink balanced if it contains an equal number of all substances. To boost his aura and ensure victory in the duel, Edmond must make the initial string balanced by applying the following operation:

Choose an index i
 such that si≠si+1
 (where i+1
 must not exceed the current size of the string).
Insert a character x
, either L, I, or T, between them such that x≠si
 and x≠si+1
.
Help Edmond make the drink balanced and win the duel by performing no more than 2n
 operations. If there are multiple solutions, any one of them can be output. If it is impossible, you must report this.

Input
Each test consists of several test cases. The first line of the input data contains one integer t
 (1≤t≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer n
 (1≤n≤100
) — the length of the string s
.

The second line of each test case contains a string s
 of length n
, consisting only of the characters L, I, and T.

Output
For each test case, output −1
 if there is no solution. Otherwise, in the first line, output a single integer m
 (0≤m≤2n
) — the number of operations you performed.

Then the l
-th of the following m
 lines should contain a single integer i
 (1≤i<n+l−1
), indicating the operation of inserting a character between si
 and si+1
. It must hold that si≠si+1
.

If there are multiple solutions, any one of them can be output. Note that you do not need to minimize the number of operations in this problem.

Example
InputCopy
3
5
TILII
1
L
3
LIT
OutputCopy
4
1
2
3
4
-1
0
Note
In the first test case, the following sequence of operations can be performed: TILII →
 TLILII →
 TLTILII →
 TLTLILII →
 TLTLTILII.

In the second test case, no operations can be performed, so the answer is −1
.

In the third test case, the initial string already has equal quantities of all substances.
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
