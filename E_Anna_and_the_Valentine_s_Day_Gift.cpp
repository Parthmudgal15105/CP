#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath> // ensure support for ceil
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
    vi arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
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

/*----------------------------------------------------------------------------*/
ll countZeroes(ll n)
{
    ll c = 0;
    while (n > 0)
    {
        if (n % 10 != 0)
            break;
        c++;
        n /= 10;
    }
    return c;
}
ll countDigits(ll n)
{
    ll c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll sum = 0;
    vll z(n);
    for (int i = 0; i < n; i++)
    {
        sum += countDigits(v[i]);
        z[i] = countZeroes(v[i]);
    }
    sort(z.begin(), z.end(), greater<ll>());
    for (int i = 0; i < n; i += 2)
    {
        sum -= z[i];
    }
    if (sum >= (m + 1))
    {
        cout << "Sasha\n";
    }
    else
    {
        cout << "Anna\n";
    }
}

/*
Sasha gave Anna a list a
 of n
 integers for Valentine's Day. Anna doesn't need this list, so she suggests destroying it by playing a game.

Players take turns. Sasha is a gentleman, so he gives Anna the right to make the first move.

On her turn, Anna must choose an element ai
 from the list and reverse the sequence of its digits. For example, if Anna chose the element with a value of 42
, it would become 24
; if Anna chose the element with a value of 1580
, it would become 851
. Note that leading zeros are removed. After such a turn, the number of elements in the list does not change.
On his turn, Sasha must extract two elements ai
 and aj
 (i≠j
) from the list, concatenate them in any order and insert the result back into the list. For example, if Sasha chose the elements equal to 2007
 and 19
, he would remove these two elements from the list and add the integer 200719
 or 192007
. After such a turn, the number of elements in the list decreases by 1
.
Players can't skip turns. The game ends when Sasha can't make a move, i.e. after Anna's move there is exactly one number left in the list. If this integer is not less than 10m
 (i.e., ≥10m
), Sasha wins. Otherwise, Anna wins.

It can be shown that the game will always end. Determine who will win if both players play optimally.

Input
The first line contains an integer t
 (1≤t≤104
) — the number of test cases.

Then follows the description of the test cases.

The first line of each test case contains integers n
, m
 (1≤n≤2⋅105
, 0≤m≤2⋅106
) — the number of integers in the list and the parameter determining when Sasha wins.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
) — the list that Sasha gave to Anna.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output:

"Sasha", if Sasha wins with optimal play;
"Anna", if Anna wins with optimal play.
Example
InputCopy
9
2 2
14 2
3 5
9 56 1
4 10
1 2007 800 1580
4 5
5000 123 30 4
10 10
6 4 6 2 3 1 10 9 10 7
1 1
6
1 1
10
8 9
1 2 9 10 10 2 10 2
4 5
10 10 10 10
OutputCopy
Sasha
Anna
Anna
Sasha
Sasha
Anna
Anna
Anna
Sasha
Note
Consider the first test case.

Anna can reverse the integer 2
, then Sasha can concatenate the integers 2
 and 14
, obtaining the integer 214
, which is greater than 102=100
. If Anna had reversed the integer 14
, Sasha would have concatenated the integers 41
 and 2
, obtaining the integer 412
, which is greater than 102=100
. Anna has no other possible moves, so she loses.
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
