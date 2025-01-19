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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n, m;
    cin >> n >> m; // n = number of friends, m = number of presents available

    vector<ll> k(n); // k[i] represents the maximum present index friend i can receive
    vector<ll> c(m); // c[i] represents the cost of present i

    // Input friend preferences and present costs
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];

    // Sort friend preferences in descending order to handle greedily
    // Friends who can receive more expensive presents are considered first
    sort(k.begin(), k.end(), greater<>());

    ll total = 0; // Total cost of gifts
    int j = 0;    // Counter for tracking cheaper presents used

    // For each friend
    for (int i = 0; i < n; i++)
    {
        if (j < m) // If we still have cheaper presents available
        {
            // Compare cost of giving money directly (c[k[i] - 1]) vs giving the next cheapest present (c[j])
            if (c[j] < c[k[i] - 1])
            {
                total += c[j]; // Give the cheaper present
                j++;           // Move to next present
            }
            else
            {
                total += c[k[i] - 1]; // Give money directly
            }
        }
        else
        {
            // If we've used all cheaper presents, give money directly
            total += c[k[i] - 1];
        }
    }
    cout << total << endl;
}

/*
memory limit per test256 megabytes
Petya organized a strange birthday party. He invited n
 friends and assigned an integer ki
 to the i
-th of them. Now Petya would like to give a present to each of them. In the nearby shop there are m
 unique presents available, the j
-th present costs cj
 dollars (1≤c1≤c2≤…≤cm
). It's not allowed to buy a single present more than once.

For the i
-th friend Petya can either buy them a present j≤ki
, which costs cj
 dollars, or just give them cki
 dollars directly.

Help Petya determine the minimum total cost of hosting his party.

Input
The first input line contains a single integer t
 (1≤t≤103
) — the number of test cases.

The first line of each test case contains two integers n
 and m
 (1≤n,m≤3⋅105
) — the number of friends, and the number of unique presents available.

The following line contains n
 integers k1,k2,…,kn
 (1≤ki≤m
), assigned by Petya to his friends.

The next line contains m
 integers c1,c2,…,cm
 (1≤c1≤c2≤…≤cm≤109
) — the prices of the presents.

It is guaranteed that sum of values n
 over all test cases does not exceed 3⋅105
, and the sum of values m
 over all test cases does not exceed 3⋅105
.

Output
For each test case output a single integer — the minimum cost of the party.

Examples
InputCopy
2
5 4
2 3 4 3 2
3 5 12 20
5 5
5 4 3 2 1
10 40 90 160 250
OutputCopy
30
190
InputCopy
1
1 1
1
1
OutputCopy
1
Note
In the first example, there are two test cases. In the first one, Petya has 5
 friends and 4
 available presents. Petya can spend only 30
 dollars if he gives

5
 dollars to the first friend.
A present that costs 12
 dollars to the second friend.
A present that costs 5
 dollars to the third friend.
A present that costs 3
 dollars to the fourth friend.
5
 dollars to the fifth friend.
In the second one, Petya has 5
 and 5
 available presents. Petya can spend only 190
 dollars if he gives

A present that costs 10
 dollars to the first friend.
A present that costs 40
 dollars to the second friend.
90
 dollars to the third friend.
40
 dollars to the fourth friend.
10
 dollars to the fifth friend.
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
