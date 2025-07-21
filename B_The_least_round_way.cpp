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
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define ll long long
#define ld long double
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
int n = 1e3;
// g1 counts factors of 2 for each number, g2 counts factors of 5
vvi g1(n, vi(n)), g2(n, vi(n)), dp1(n, vi(n)), dp2(n, vi(n));
// iv, jv store the coordinates of a zero if one exists
int iv = -1, jv = -1;

void solve()
{

    cin >> n;
    bool has = false; // flag to check if matrix contains a zero

    // Read the matrix and count factors of 2 and 5 for each element
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            int y = x;

            // Count factors of 2
            while (y % 2 == 0 && y != 0)
            {
                g1[i][j]++;
                y /= 2;
            }

            // Count factors of 5
            while (x % 5 == 0 && x != 0)
            {
                g2[i][j]++;
                x /= 5;
            }

            // Special case: if element is 0, mark it and save its position
            if (x == 0)
            {
                g1[i][j] = g2[i][j] = -1; // Mark with -1 to identify later
                has = true;
                iv = i, jv = j; // Store coordinates of the zero
            }
        }
    }

    // Case 1: No zeros in the matrix
    if (!has)
    {
        // Initialize DP table for first cell
        dp1[0][0] = g1[0][0], dp2[0][0] = g2[0][0];

        // Fill first column (can only go down)
        for (int i = 1; i < n; i++)
        {
            dp1[i][0] = dp1[i - 1][0] + g1[i][0],
            dp2[i][0] = dp2[i - 1][0] + g2[i][0];
        }

        // Fill first row (can only go right)
        for (int j = 1; j < n; j++)
        {
            dp1[0][j] = dp1[0][j - 1] + g1[0][j],
            dp2[0][j] = dp2[0][j - 1] + g2[0][j];
        }

        // Fill DP tables for the rest of the matrix
        // dp1 counts min factors of 2, dp2 counts min factors of 5
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // For each cell, choose the path with fewer factors
                dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) + g1[i][j],
                dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) + g2[i][j];
            }
        }

        // Choose the table with fewer factors at the end
        // (fewer trailing zeros = min(factors of 2, factors of 5))
        if (dp1[n - 1][n - 1] > dp2[n - 1][n - 1])
        {
            swap(dp1, dp2); // Use dp1 for the path with fewer factors
        }
        cout << dp1[n - 1][n - 1] << endl; // Print minimum trailing zeros

        // Reconstruct the optimal path from end to start
        int i = n - 1, j = n - 1;
        vector<char> ans;
        while (!(i == 0 && j == 0))
        {
            if (i == 0) // Can only move horizontally (right)
            {
                j--;
                ans.push_back('R');
            }
            else if (j == 0) // Can only move vertically (down)
            {
                i--;
                ans.push_back('D');
            }
            else if (dp1[i - 1][j] > dp1[i][j - 1]) // Compare paths: from above vs from left
            {
                j--; // Left has fewer factors, so we came from left
                ans.push_back('R');
            }
            else
            {
                i--; // Above has fewer factors, so we came from above
                ans.push_back('D');
            }
        }
        reverse(ans.begin(), ans.end()); // Path was built backwards, so reverse it
        for (auto it : ans)
        {
            cout << it; // Print the path
        }
    }
    // Case 2: There is at least one zero in the matrix
    else
    {
        // Replace all zeros with a value that adds 1 trailing zero
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g1[i][j] == -1)
                {
                    g1[i][j] = g2[i][j] = 1; // Adds 1 trailing zero
                }
            }
        }

        // Compute DP tables same as before
        dp1[0][0] = g1[0][0], dp2[0][0] = g2[0][0];
        for (int i = 1; i < n; i++)
        {
            dp1[i][0] = dp1[i - 1][0] + g1[i][0],
            dp2[i][0] = dp2[i - 1][0] + g2[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp1[0][j] = dp1[0][j - 1] + g1[0][j],
            dp2[0][j] = dp2[0][j - 1] + g2[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp1[i][j] = min(dp1[i][j - 1], dp1[i - 1][j]) + g1[i][j],
                dp2[i][j] = min(dp2[i][j - 1], dp2[i - 1][j]) + g2[i][j];
            }
        }

        // Check if best path is to go through a zero (this gives exactly 1 trailing zero)
        if (min(dp1[n - 1][n - 1], dp2[n - 1][n - 1]) >= 1)
        {
            cout << 1 << endl; // We can achieve exactly 1 trailing zero by going through a zero

            // Construct path through the zero at (iv, jv):
            // First go down to the zero's row
            for (int x = 0; x < iv; x++)
            {
                cout << 'D';
            }
            // Then right to the zero's column
            for (int y = 0; y < jv; y++)
            {
                cout << 'R';
            }
            // Then down to the bottom row
            for (int x = iv + 1; x < n; x++)
            {
                cout << 'D';
            }
            // Finally right to the end
            for (int y = jv + 1; y < n; y++)
            {
                cout << 'R';
            }
            return;
        }

        // If going through zero doesn't give the best answer,
        // find the optimal path without going through a zero
        if (dp1[n - 1][n - 1] > dp2[n - 1][n - 1])
        {
            swap(dp1, dp2);
        }
        cout << dp1[n - 1][n - 1] << endl;

        // Reconstruct path (similar to Case 1 but with different logic)
        int i = n - 1, j = n - 1;
        vector<char> ans;
        while (i >= 0 && j >= 0)
        {
            if (i == 0 && j == 0)
            {
                break;
            }
            if (i == 0 || (j >= 1 && dp1[i - 1][j] >= dp1[i][j - 1]))
            {
                j--;
                ans.push_back('R');
            }
            else
            {
                i--;
                ans.push_back('D');
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it;
        }
    }
    return;
}

/*
There is a square matrix n × n, consisting of non-negative integer numbers. You should find such a way on it that

starts in the upper left cell of the matrix;
each following cell is to the right or down from the current cell;
the way ends in the bottom right cell.
Moreover, if we multiply together all the numbers along the way, the result should be the least "round". In other words, it should end in the least possible number of zeros.

Input
The first line contains an integer number n (2 ≤ n ≤ 1000), n is the size of the matrix. Then follow n lines containing the matrix elements (non-negative integer numbers not exceeding 109).

Output
In the first line print the least number of trailing zeros. In the second line print the correspondent way itself.

Examples
InputCopy
3
1 2 3
4 5 6
7 8 9
OutputCopy
0
DDRR

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
