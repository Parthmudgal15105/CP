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
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
*/

/*
check all edge cases
check for integer overflow
check for corner cases
check for constraints
check for time complexity
check for array bounds
check for negative values
*/
#define cno cout << "NO\n"
#define cyes cout << "YES\n"

/*----------------------------------------------------------------------------*/
void solve()
{
    // Step 1: Read input.
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Step 2: Count occurrences of each instruction (N, S, E, W).
    int countN = 0, countS = 0, countE = 0, countW = 0;
    for (char c : s)
    {
        if (c == 'N')
            countN++;
        else if (c == 'S')
            countS++;
        else if (c == 'E')
            countE++;
        else if (c == 'W')
            countW++;
    }

    // Step 3: Check if it's possible:
    // The differences (N-S) and (E-W) must be even for an equal split.
    if (((countN - countS) & 1) || ((countE - countW) & 1))
    {
        cout << "NO" << nl;
        return;
    }

    // Step 4: Compute how many moves from each direction should go to the helicopter.
    int needN = 0, needS = 0, needE = 0, needW = 0;
    int dY = countN - countS; // overall vertical difference
    int dX = countE - countW; // overall horizontal difference
    if (dY > 0)
        needN = dY / 2;
    else
        needS = (-dY) / 2;
    if (dX > 0)
        needE = dX / 2;
    else
        needW = (-dX) / 2;

    // Step 5: By default, assign all instructions to the rover.
    vector<char> assign(n, 'R');

    // Step 6: Greedily assign instructions (H) for helicopter based on the required counts.
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == 'N' && needN > 0)
        {
            assign[i] = 'H';
            needN--;
        }
        else if (c == 'S' && needS > 0)
        {
            assign[i] = 'H';
            needS--;
        }
        else if (c == 'E' && needE > 0)
        {
            assign[i] = 'H';
            needE--;
        }
        else if (c == 'W' && needW > 0)
        {
            assign[i] = 'H';
            needW--;
        }
    }

    // Step 7: If no instruction was assigned to helicopter but overall displacement is 0,
    // we choose a balanced pair (one N and one S, or one E and one W) so both devices execute at least one move.
    int countH = 0;
    for (auto ch : assign)
        if (ch == 'H')
            countH++;
    if (countH == 0 && (dX == 0 && dY == 0))
    {
        int posN = -1, posS = -1, posE = -1, posW = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N' && posN == -1)
                posN = i;
            if (s[i] == 'S' && posS == -1)
                posS = i;
            if (s[i] == 'E' && posE == -1)
                posE = i;
            if (s[i] == 'W' && posW == -1)
                posW = i;
        }
        if (posN != -1 && posS != -1)
        {
            assign[posN] = 'H';
            assign[posS] = 'H';
        }
        else if (posE != -1 && posW != -1)
        {
            assign[posE] = 'H';
            assign[posW] = 'H';
        }
    }

    // Step 8: Final check that both the rover and helicopter receive at least one instruction.
    bool hasH = false, hasR = false;
    for (auto ch : assign)
    {
        if (ch == 'H')
            hasH = true;
        if (ch == 'R')
            hasR = true;
    }
    if (!hasH || !hasR)
    {
        cout << "NO" << nl;
        return;
    }

    // Step 9: Output the final assignment of instructions.
    for (char ch : assign)
        cout << ch;
    cout << nl;
}

/*
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
