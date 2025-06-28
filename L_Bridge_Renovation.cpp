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

    // x, y, z represent the number of planks needed for each bridge (all equal to n)
    int x = n, y = n, z = n;
    int ans = 0;

    // Try to use one plank for 2 planks of length 21 (y) and 1 plank of length 18 (x)
    // This is because 21+21+18 = 60, which fits perfectly in one standard plank
    while (y >= 2 && x >= 1)
    {
        y -= 2;
        x -= 1;
        ans++;
    }

    // Try to use one plank for 3 planks of length 18 (x)
    // 18+18+18 = 54, which fits in one plank (with some waste)
    while (x >= 3)
    {
        x -= 3;
        ans++;
    }

    // For the remaining planks (x, y, z), just pair them up as best as possible
    // Each standard plank can fit at least two of the remaining planks (since 25+18=43, 25+21=46, etc.)
    // So, (x + y + z + 1) / 2 gives the minimum number of planks needed for leftovers
    ans += (x + y + z + 1) / 2;

    cout << ans << "\n";
}

/*
Recently, Monocarp started working as a director of a park located near his house. The park is quite large, so it even has a small river splitting it into several zones. Several bridges are built across this river. Three of these bridges are especially old and need to be repaired.

All three bridges have the same length but differ in width. Their widths are 18
, 21
 and 25
 units, respectively.

During the park renovation process, Monocarp has to replace the old planks that served as the surface of the bridges with the new ones.


Planks are sold with a standard length of 60
 units. Monocarp already knows that he needs n
 planks for each bridge. But since the bridges have different widths, he needs n
 planks of length 18
 for the first bridge, n
 planks of length 21
 for the second one, and n
 planks of length 25
 for the last one.

Workers in charge of renovation have no problem with cutting planks into parts but refuse to join planks, since it creates weak spots and looks ugly.

Monocarp wants to buy as few planks as possible but struggles to calculate the required number of planks. Can you help him?

Input
The first and only line contains a single integer n
 (1≤n≤1000
) — the number of planks required for each of the three bridges.

Output
Print a single integer — the minimum number of planks of standard length (60
 units) Monocarp needs to cover all three bridges if the planks can be cut into parts.

Examples
InputCopy
1
OutputCopy
2
InputCopy
3
OutputCopy
4
InputCopy
1000
OutputCopy
1167
Note
In the first example, it is possible to cut one plank of length 60
 into three planks with lengths 25
, 18
 and 17
, and cut another plank of length 60
 into two planks with lengths 39
 and 21
. That way, Monocarp will have all the required planks.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();
}
