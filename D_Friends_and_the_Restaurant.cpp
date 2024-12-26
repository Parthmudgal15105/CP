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
    // Read the number of friends
    int n;
    cin >> n;
    // Initialize vectors to store spending and budget of each friend
    vector<ll> x(n), y(n);

    // Read the amount each friend plans to spend
    for (int i = 0; i < n; i++)
        cin >> x[i];
    // Read the budget of each friend
    for (int i = 0; i < n; i++)
        cin >> y[i];

    // Calculate the difference between budget and spending for each friend
    vector<ll> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = y[i] - x[i];
    }
    // Sort the differences to use two-pointer technique
    sort(d.begin(), d.end());
    ll ans = 0;
    int l = 0, r = n - 1;
    // Use two pointers to form valid groups
    while (l < r)
    {
        // If the sum of differences is non-negative, form a group
        if (d[l] + d[r] >= 0)
        {
            ans++;
            l++;
            r--;
        }
        else
        {
            // Move the left pointer to try with the next friend
            l++;
        }
    }
    // Output the maximum number of groups (days)
    cout << ans << nl;
}

/*
A group of n
 friends decide to go to a restaurant. Each of the friends plans to order meals for xi
 burles and has a total of yi
 burles (1≤i≤n
).

The friends decide to split their visit to the restaurant into several days. Each day, some group of at least two friends goes to the restaurant. Each of the friends visits the restaurant no more than once (that is, these groups do not intersect). These groups must satisfy the condition that the total budget of each group must be not less than the amount of burles that the friends in the group are going to spend at the restaurant. In other words, the sum of all xi
 values in the group must not exceed the sum of yi
 values in the group.

What is the maximum number of days friends can visit the restaurant?

For example, let there be n=6
 friends for whom x
 = [8,3,9,2,4,5
] and y
 = [5,3,1,4,5,10
]. Then:

first and sixth friends can go to the restaurant on the first day. They will spend 8+5=13
 burles at the restaurant, and their total budget is 5+10=15
 burles. Since 15≥13
, they can actually form a group.
friends with indices 2,4,5
 can form a second group. They will spend 3+2+4=9
 burles at the restaurant, and their total budget will be 3+4+5=12
 burles (12≥9
).
It can be shown that they will not be able to form more groups so that each group has at least two friends and each group can pay the bill.

So, the maximum number of groups the friends can split into is 2
. Friends will visit the restaurant for a maximum of two days. Note that the 3
-rd friend will not visit the restaurant at all.

Output the maximum number of days the friends can visit the restaurant for given n
, x
 and y
.

Input
The first line of the input contains an integer t
 (1≤t≤104
) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of each test case contains a single integer n
 (2≤n≤105
) — the number of friends.

The second line of each test case contains exactly n
 integers x1,x2,…,xn
 (1≤xi≤109
). The value of xi
 corresponds to the number of burles that the friend numbered i
 plans to spend at the restaurant.

The third line of each test case contains exactly n
 integers y1,y2,…,yn
 (1≤yi≤109
). The value yi
 corresponds to the number of burles that the friend numbered i
 has.

It is guaranteed that the sum of n
 values over all test cases does not exceed 105
.

Output
For each test case, print the maximum number of days to visit the restaurant. If friends cannot form even one group to visit the restaurant, print 0.

Example
InputCopy
6
6
8 3 9 2 4 5
5 3 1 4 5 10
4
1 2 3 4
1 1 2 2
3
2 3 7
1 3 10
6
2 3 6 9 5 7
3 2 7 10 6 10
6
5 4 2 1 8 100
1 1 1 1 1 200
6
1 4 1 2 4 2
1 3 3 2 3 4
OutputCopy
2
0
1
3
1
3
Note
The first test case in explained in the problem statement.

In the second test case, friends cannot form at least one group of two or more people.

In the third test case, one way to visit the restaurant in one day is to go in a group of all three friends (1+3+10≥2+3+7
). Note that they do not have the option of splitting into two groups.
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
