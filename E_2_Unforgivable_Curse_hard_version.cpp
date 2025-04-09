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
    int n, k;
    string s, t;
    cin >> n >> k;
    cin >> s >> t;

    // Flag variable: z==1 means transformation is possible, 0 means impossible.
    int z = 1;

    // Loop through every character to check positions which are "fixed"
    // A position is fixed if it cannot be swapped (both i-k and i+k are out of range)
    for (int i = 0; i < n; i++)
    {
        // Check if no valid swap partner exists for s[i]. In such cases s[i] must equal t[i].
        if (i - k < 0 && i + k >= n)
        {
            if (s[i] != t[i])
            {
                z = 0; // Cannot adjust fixed character; answer becomes impossible.
            }
        }
    }

    // If we can freely swap letters, both strings must have the same set of characters.
    sort(all(s)), sort(all(t));
    if (s != t)
    {
        z = 0;
    }

    // Output answer based on the flag
    if (z)
    {
        // Transformation is possible
        cyes;
    }
    else
    {
        // Transformation is not possible
        cno;
    }
}

/*
This is a complex version of the problem. This version has no additional restrictions on the number k
.

The chief wizard of the Wizengamot once caught the evil wizard Drahyrt, but the evil wizard has returned and wants revenge on the chief wizard. So he stole spell s
 from his student Harry.

The spell — is a n
-length string of lowercase Latin letters.

Drahyrt wants to replace spell with an unforgivable curse — string t
.

Dragirt, using ancient magic, can swap letters at a distance k
 or k+1
 in spell as many times as he wants. In other words, Drahyrt can change letters in positions i
 and j
 in spell s
 if |i−j|=k
 or |i−j|=k+1
.

For example, if k=3,s=
 "talant" and t=
 "atltna", Drahyrt can act as follows:

swap the letters at positions 1
 and 4
 to get spell "aaltnt".
swap the letters at positions 2
 and 6
 to get spell "atltna".
You are given spells s
 and t
. Can Drahyrt change spell s
 to t
?

Input
The first line of input gives a single integer T
 (1≤T≤104
) — the number of test cases in the test.

Descriptions of the test cases are follow.

The first line contains two integers n,k
 (1≤n≤2⋅105
, 1≤k≤2⋅105
) — the length spells and the number k
 such that Drahyrt can change letters in a spell at a distance k
 or k+1
.

The second line gives spell s
 — a string of length n
 consisting of lowercase Latin letters.

The third line gives spell t
 — a string of length n
 consisting of lowercase Latin letters.

It is guaranteed that the sum of n
 values over all test cases does not exceed 2⋅105
. Note that there is no limit on the sum of k
 values over all test cases.

Output
For each test case, output on a separate line "YES" if Drahyrt can change spell s
 to t
 and "NO" otherwise.

You can output the answer in any case (for example, lines "yEs", "yes", "Yes" and "YES" will be recognized as positive answer).

Example
InputCopy
7
6 3
talant
atltna
7 1
abacaba
aaaabbc
12 6
abracadabraa
avadakedavra
5 3
accio
cicao
5 4
lumos
molus
4 3
uwjt
twju
4 3
kvpx
vxpk
OutputCopy
YES
YES
NO
YES
NO
YES
NO
Note
The first case is explained in the condition.

In the second case, we can swap adjacent letters, so we can sort the string using bubble sorting, for example.

In the third case, we can show that from the string s
 we cannot get the string t
 by swapping letters at a distance of 6
 or 7
.

In the fourth case, for example, the following sequence of transformations is appropriate:

"accio" →
 "aocic" →
 "cocia" →
 "iocca" →
 "aocci" →
 "aicco" →
 "cicao"
In the fifth case, we can show that it is impossible to get the string s
 from the string t
.

In the sixth example, it is enough to swap the two outermost letters.
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
