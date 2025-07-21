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

void solve()
{
    int n, k;
    cin >> n >> k;

    // Read the array (1-based indexing)
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp[i][j] = max number of fixed points we can achieve
    //            using only the first i elements of a[],
    //            if we have removed exactly j elements so far.
    // A “fixed point” means a[x] == its new index in the filtered array.
    vvi dp(n + 1, vi(n + 1, 0));

    // Build the DP table incrementally
    for (int i = 1; i <= n; i++)
    {
        // Case j = 0 (no removals yet): just carry over previous fixed‐point count
        // and add 1 if a[i] happens to equal its original position i.
        dp[i][0] = dp[i - 1][0] + (a[i] == i ? 1 : 0);

        // Now consider all possible removal counts j = 1..i
        for (int j = 1; j <= i; j++)
        {
            // Option 1: we remove the i-th element
            //   -> we must have removed j-1 among the first i-1 elements,
            //      so dp[i][j] can come from dp[i-1][j-1].
            int remove_i = dp[i - 1][j - 1];

            // Option 2: we keep the i-th element
            //   -> its new position in the filtered array is (i - j),
            //   -> check if a[i] == (i - j) gives a fixed point (+1),
            //   -> we have still removed j among the first i-1 elements,
            //      so we add to dp[i-1][j].
            int keep_i = dp[i - 1][j] + (a[i] == (i - j) ? 1 : 0);

            // Choose the better of the two options
            dp[i][j] = max(remove_i, keep_i);
        }
    }

    // Find the smallest j (removals) so that dp[n][j] >= k
    // i.e., we achieve at least k fixed points after j removals.
    int answer = -1;
    for (int j = 0; j <= n; j++)
    {
        if (dp[n][j] >= k)
        {
            answer = j;
            break;
        }
    }

    cout << answer << nl;
}

/*
Consider a sequence of integers a1,a2,…,an
. In one move, you can select any element of the sequence and delete it. After an element is deleted, all elements to the right are shifted to the left by 1
 position, so there are no empty spaces in the sequence. So after you make a move, the sequence's length decreases by 1
. The indices of the elements after the move are recalculated.

E. g. let the sequence be a=[3,2,2,1,5]
. Let's select the element a3=2
 in a move. Then after the move the sequence will be equal to a=[3,2,1,5]
, so the 3
-rd element of the new sequence will be a3=1
 and the 4
-th element will be a4=5
.

You are given a sequence a1,a2,…,an
 and a number k
. You need to find the minimum number of moves you have to make so that in the resulting sequence there will be at least k
 elements that are equal to their indices, i. e. the resulting sequence b1,b2,…,bm
 will contain at least k
 indices i
 such that bi=i
.

Input
The first line contains one integer t
 (1≤t≤100
) — the number of test cases. Then t
 test cases follow.

Each test case consists of two consecutive lines. The first line contains two integers n
 and k
 (1≤k≤n≤2000
). The second line contains a sequence of integers a1,a2,…,an
 (1≤ai≤n
). The numbers in the sequence are not necessarily different.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2000
.

Output
For each test case output in a single line:

−1
 if there's no desired move sequence;
otherwise, the integer x
 (0≤x≤n
) — the minimum number of the moves to be made so that the resulting sequence will contain at least k
 elements that are equal to their indices.
Example
InputCopy
4
7 6
1 1 2 3 4 5 6
5 2
5 1 3 2 3
5 2
5 5 5 5 4
8 4
1 2 3 3 2 2 5 5
OutputCopy
1
2
-1
2
Note
In the first test case the sequence doesn't satisfy the desired condition, but it can be provided by deleting the first element, hence the sequence will be [1,2,3,4,5,6]
 and 6
 elements will be equal to their indices.

In the second test case there are two ways to get the desired result in 2
 moves: the first one is to delete the 1
-st and the 3
-rd elements so that the sequence will be [1,2,3]
 and have 3
 elements equal to their indices; the second way is to delete the 2
-nd and the 3
-rd elements to get the sequence [5,2,3]
 with 2
 desired elements.



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
