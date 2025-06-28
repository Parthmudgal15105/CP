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

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Remove consecutive duplicates to get the sequence of unique button weights in order
    vector<int> b;
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != l)
        {
            b.push_back(a[i]);
            l = a[i];
        }
    }
    n = b.size();

    // Pair each value with its index for sorting
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = {b[i], i};
    }
    // Sort by value descending (so we press larger weights first)
    sort(vec.rbegin(), vec.rend());

    // chk[j] = 1 means the button at position j has been pressed
    vector<int> chk(n, 0);
    int ans = 0; // Number of clones needed

    // Iterate over buttons in order of decreasing weight
    for (int i = 0; i < n; i++)
    {
        int j = vec[i].second; // index in the original sequence

        // If the left neighbor is already pressed, this button can be pressed by moving a clone from there
        if (j > 0 && chk[j - 1])
        {
            chk[j] = 1;
            continue;
        }
        // If the right neighbor is already pressed, this button can be pressed by moving a clone from there
        if (j < n - 1 && chk[j + 1])
        {
            chk[j] = 1;
            continue;
        }
        // Otherwise, we need to create a new clone at this position
        chk[j] = 1;
        ans++;
    } // n
    cout << ans << '\n';
}

/*
Neo wants to escape from the Matrix. In front of him are n
 buttons arranged in a row. Each button has a weight given by an integer: a1,a2,…,an
.

Neo is immobilized, but he can create and move clones. This means he can perform an unlimited number of actions of the following two types in any order:

Create a clone in front of a specific button.
Move an existing clone one position to the left or right.
As soon as a clone is in front of another button that has not yet been pressed—regardless of whether he was created or moved — he immediately presses it. If the button has already been pressed, a clone does nothing — buttons can only be pressed once.

For Neo to escape, he needs to press all the buttons in such an order that the sequence of their weights is non-increasing — that is, if b1,b2,…,bn
 are the weights of the buttons in the order they are pressed, then it must hold that b1≥b2≥⋯≥bn
.

Your task is to determine the minimum number of clones that Neo needs to create in order to press all the buttons in a valid order.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the number of buttons.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the weights of the buttons.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of clones that need to be created to press all the buttons in a valid order.

Example
InputCopy
4
5
4 3 2 1 5
3
1 1 1
6
7 8 1 5 9 2
10
1 7 9 7 1 10 2 10 10 7
OutputCopy
2
1
2
3
Note
In the first test case, Neo can act as follows:

Create a clone in front of the fifth button (with weight 5
).
Create a clone in front of the first button (with weight 4
).
Move the second clone from the first button to the second (with weight 3
).
Move the second clone from the second button to the third (with weight 2
).
Move the first clone from the fifth button to the fourth (with weight 1
).
Thus, the sequence of button presses will be 5→4→3→2→1
, which meets the requirement. It can be shown that the number of clones created is the smallest possible.
In the second test case, Neo can act as follows:

Create a clone in front of the second button (with weight 1
).
Move the clone from the second button to the third (with weight 1
).
Move the clone from the third button to the second (already pressed).
Move the clone from the second button to the first (with weight 1
).
Thus, the sequence of button presses will be 1→1→1
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
