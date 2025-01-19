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
// Helper functions for checking odd/even numbers
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime
// Function to check if a number is prime
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
// Standard GCD and LCM implementations
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
// Binary search implementation for integer square root
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
    // Read input: n cities, k major cities, start city a, end city b
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    // Store coordinates of all cities in a vector of pairs
    vector<pair<int, int>> coordinates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coordinates[i].first;
        cin >> coordinates[i].second;
    }

    // Calculate Manhattan distance between start and end cities
    long long directDist = llabs((long long)coordinates[a - 1].first - coordinates[b - 1].first) + 
                          llabs((long long)coordinates[a - 1].second - coordinates[b - 1].second);
    
    // If both cities are major cities, cost is 0
    if (a <= k && b <= k)
    {
        cout << 0 << nl;
        return;
    }

    // Initialize distances with INF unless the city is a major city
    long long INF = 1e18;
    long long distA = (a <= k ? 0 : INF);  // Distance from start to nearest major city
    long long distB = (b <= k ? 0 : INF);  // Distance from end to nearest major city

    // Find minimum distance from start city to any major city
    if (distA == INF)
    {
        for (int i = 1; i <= k; i++)
        {
            long long d = llabs((long long)coordinates[a - 1].first - coordinates[i - 1].first) + 
                         llabs((long long)coordinates[a - 1].second - coordinates[i - 1].second);
            distA = min(distA, d);
        }
    }

    // Find minimum distance from end city to any major city
    if (distB == INF)
    {
        for (int i = 1; i <= k; i++)
        {
            long long d = llabs((long long)coordinates[b - 1].first - coordinates[i - 1].first) + 
                         llabs((long long)coordinates[b - 1].second - coordinates[i - 1].second);
            distB = min(distB, d);
        }
    }

    // Output minimum of: direct path OR path through major cities
    cout << min(directDist, distA + distB) << nl;
}

/*
Piggy lives on an infinite plane with the Cartesian coordinate system on it.

There are n
 cities on the plane, numbered from 1
 to n
, and the first k
 cities are defined as major cities. The coordinates of the i
-th city are (xi,yi)
.

Piggy, as a well-experienced traveller, wants to have a relaxing trip after Zhongkao examination. Currently, he is in city a
, and he wants to travel to city b
 by air. You can fly between any two cities, and you can visit several cities in any order while travelling, but the final destination must be city b
.

Because of active trade between major cities, it's possible to travel by plane between them for free. Formally, the price of an air ticket f(i,j)
 between two cities i
 and j
 is defined as follows:

f(i,j)={0,|xi−xj|+|yi−yj|,if cities i and j are both major citiesotherwise

Piggy doesn't want to save time, but he wants to save money. So you need to tell him the minimum value of the total cost of all air tickets if he can take any number of flights.

Input
The first line of input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains four integers n
, k
, a
 and b
 (2≤n≤2⋅105
, 0≤k≤n
, 1≤a,b≤n
, a≠b
) — the number of cities, the number of major cities and the numbers of the starting and the ending cities.

Then n
 lines follow, the i
-th line contains two integers xi
 and yi
 (−109≤xi,yi≤109
) — the coordinates of the i
-th city. The first k
 lines describe major cities. It is guaranteed that all coordinates are pairwise distinct.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the minimum value of the total price of all air tickets.

Example
InputCopy
5
6 2 3 5
0 0
1 -2
-2 1
-1 3
2 -2
-3 -3
2 0 1 2
-1000000000 -1000000000
1000000000 1000000000
7 5 4 2
154 147
-154 -147
123 456
20 23
43 20
998 244
353 100
3 1 3 1
0 10
1 20
2 30
4 3 2 4
0 0
-100 100
-1 -1
-1 0
OutputCopy
4
4000000000
0
22
1
Note
In the first test case:

The major cities are marked red.
The optimal way to choose the flights is: 3→1→2→5
, which will cost 3+0+1=4
. Note that the flight 1→2
 costs 0
, because both city 1
 and 2
 are major cities.

In the second test case, since there are only 2
 cities, the only way is to take a flight from city 1
 to 2
.

In the third test case, since city 2
 and 4
 are both major cities, Piggy can directly take a flight from city 2
 to 4
, which costs 0
.

In the fourth test case, Piggy can choose to take the following flights: 3→2→1
, and the cost is 11+11=22
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
