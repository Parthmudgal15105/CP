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
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0, c = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (c >= i)
        {
            c--;
            ans += i + 1;
            continue;
        }

        if (s[i] == '1')
        {
            c++;
        }
        else
        {
            ans += i + 1;
            c--;
            c = max(0ll, c);
        }
    }

    cout << ans << endl;
    return;
}

/*
There is a shop that sells action figures near Monocarp's house. A new set of action figures will be released shortly; this set contains n
 figures, the i
-th figure costs i
 coins and is available for purchase from day i
 to day n
.

For each of the n
 days, Monocarp knows whether he can visit the shop.

Every time Monocarp visits the shop, he can buy any number of action figures which are sold in the shop (of course, he cannot buy an action figure that is not yet available for purchase). If Monocarp buys at least two figures during the same day, he gets a discount equal to the cost of the most expensive figure he buys (in other words, he gets the most expensive of the figures he buys for free).

Monocarp wants to buy exactly one 1
-st figure, one 2
-nd figure, ..., one n
-th figure from the set. He cannot buy the same figure twice. What is the minimum amount of money he has to spend?

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer n
 (1≤n≤4⋅105
) — the number of figures in the set (and the number of days);
the second line contains a string s
 (|s|=n
, each si
 is either 0 or 1). If Monocarp can visit the shop on the i
-th day, then si
 is 1; otherwise, si
 is 0.
Additional constraints on the input:

in each test case, sn
 is 1, so Monocarp is always able to buy all figures during the n
-th day;
the sum of n
 over all test cases does not exceed 4⋅105
.
Output
For each test case, print one integer — the minimum amount of money Monocarp has to spend.

Example
InputCopy
4
1
1
6
101101
7
1110001
5
11111
OutputCopy
1
8
18
6
Note
In the first test case, Monocarp buys the 1
-st figure on the 1
-st day and spends 1
 coin.

In the second test case, Monocarp can buy the 1
-st and the 3
-rd figure on the 3
-rd day, the 2
-nd and the 4
-th figure on the 4
-th day, and the 5
-th and the 6
-th figure on the 6
-th day. Then, he will spend 1+2+5=8
 coins.

In the third test case, Monocarp can buy the 2
-nd and the 3
-rd figure on the 3
-rd day, and all other figures on the 7
-th day. Then, he will spend 1+2+4+5+6=18
 coins.
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
