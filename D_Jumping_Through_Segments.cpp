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
void solve()
{
    int numberOfSegments;
    cin >> numberOfSegments;

    vector<long long> lowerBounds(numberOfSegments), upperBounds(numberOfSegments);

    for (int i = 0; i < numberOfSegments; i++)
    {
        cin >> lowerBounds[i] >> upperBounds[i];
    }

    long long lowerRange = -1e9, upperRange = 1e9;
    long long minimumK = 1e18;
    while (upperRange >= lowerRange)
    {
        bool isValidPath = true;
        long long currentMin = 0, currentMax = 0;
        long long middle = (upperRange + lowerRange) / 2;
        // For every segment, update the possible landing interval based on current move limit 'middle'
        for (int i = 0; i < numberOfSegments; i++)
        {
            // Adjust the possible interval by shifting the range using 'middle'
            currentMin -= middle;
            currentMax += middle;
            // Restrict the interval to lie within the current segment boundaries
            currentMin = max(currentMin, lowerBounds[i]);
            currentMax = min(currentMax, upperBounds[i]);
            if (currentMin > currentMax)
                isValidPath = false; // No valid landing for the current move
        }
        if (isValidPath)
        {
            minimumK = middle;
            upperRange = middle - 1; // Try finding a smaller valid step
        }
        else
            lowerRange = middle + 1; // Increase step size if no valid path was found
    }
    cout << minimumK << endl;
}

/*
Polycarp is designing a level for a game. The level consists of n
 segments on the number line, where the i
-th segment starts at the point with coordinate li
 and ends at the point with coordinate ri
.

The player starts the level at the point with coordinate 0
. In one move, they can move to any point that is within a distance of no more than k
. After their i
-th move, the player must land within the i
-th segment, that is, at a coordinate x
 such that li≤x≤ri
. This means:

After the first move, they must be inside the first segment (from l1
 to r1
);
After the second move, they must be inside the second segment (from l2
 to r2
);
...
After the n
-th move, they must be inside the n
-th segment (from ln
 to rn
).
The level is considered completed if the player reaches the n
-th segment, following the rules described above. After some thought, Polycarp realized that it is impossible to complete the level with some values of k
.

Polycarp does not want the level to be too easy, so he asks you to determine the minimum integer k
 with which it is possible to complete the level.

Input
The first line contains a single integer t
 (1≤t≤104
)—the number of test cases. Descriptions of the test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
)—the number of segments in the level.

The following n
 lines.

The i
-th line contain two integers li
 and ri
 (0≤li≤ri≤109
)—the boundaries of the i
-th segment. Segments may intersect.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer—the minimum value of k
 with which it is possible to complete the level.

Example
InputCopy
4
5
1 5
3 4
5 6
8 10
0 1
3
0 2
0 1
0 3
3
3 8
10 18
6 11
4
10 20
0 5
15 17
2 2
OutputCopy
7
0
5
13
Note
In the third example, the player can make the following moves:

Move from point 0
 to point 5
 (3≤5≤8
);
Move from point 5
 to point 10
 (10≤10≤18
);
Move from point 10
 to point 7
 (6≤7≤11
).
Note that for the last move, the player could have chosen not to move and still complete the level.
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
