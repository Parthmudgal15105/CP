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

long long mySqrt(long long x)
{
    // Custom integer square root
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

void solve()
{
    // Read number of rectangles and box width
    int n;
    cin >> n;
    int w;
    cin >> w;

    // Store rectangle widths in vector
    vector<int> a(n);

    // multiset to track available spaces in each level
    // each element represents remaining width in a level
    multiset<int> st;

    // Input rectangle widths
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sort rectangles in descending order to fit larger ones first
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    // ans represents number of levels/height needed
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // If no level has enough space for current rectangle
        if (st.lower_bound(a[i]) == st.end())
        {
            // Create new level with full width
            st.insert(w);
            ans++;
        }

        // Find smallest space that can fit current rectangle
        auto it = st.lower_bound(a[i]);
        // Insert remaining space after placing rectangle
        st.insert(*it - a[i]);
        // Remove the original space as it's now occupied
        st.erase(st.find(*it));
    }

    // Print minimum height needed
    cout << ans << endl;
}

/*
You are given n
 rectangles, each of height 1
. Each rectangle's width is a power of 2
 (i. e. it can be represented as 2x
 for some non-negative integer x
).

You are also given a two-dimensional box of width W
. Note that W
 may or may not be a power of 2
. Moreover, W
 is at least as large as the width of the largest rectangle.

You have to find the smallest height of this box, such that it is able to fit all the given rectangles. It is allowed to have some empty space left in this box after fitting all the rectangles.

You cannot rotate the given rectangles to make them fit into the box. Moreover, any two distinct rectangles must not overlap, i. e., any two distinct rectangles must have zero intersection area.

See notes for visual explanation of sample input.

Input
The first line of input contains one integer t
 (1≤t≤5⋅103
) — the number of test cases. Each test case consists of two lines.

For each test case:

the first line contains two integers n
 (1≤n≤105
) and W
 (1≤W≤109
);
the second line contains n
 integers w1,w2,…,wn
 (1≤wi≤106
), where wi
 is the width of the i
-th rectangle. Each wi
 is a power of 2
;
additionally, maxi=1nwi≤W
.
The sum of n
 over all test cases does not exceed 105
.

Output
Output t
 integers. The i
-th integer should be equal to the answer to the i
-th test case — the smallest height of the box.

Example
InputCopy
2
5 16
1 2 8 4 8
6 10
2 8 8 2 2 8
OutputCopy
2
3
Note
For the first test case in the sample input, the following figure shows one way to fit the given five rectangles into the 2D box with minimum height:


In the figure above, the number inside each rectangle is its width. The width of the 2D box is 16
 (indicated with arrow below). The minimum height required for the 2D box in this case is 2
 (indicated on the left).

In the second test case, you can have a minimum height of three by keeping two blocks (one each of widths eight and two) on each of the three levels.



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
