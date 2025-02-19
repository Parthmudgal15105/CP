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
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
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
    int n;
    cin >> n;
    vector<int> a(n);
    // Read the topics for all students.
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // sz: number of groups/pairs to consider;
    // For odd n, the middle element is unpaired.
    int sz = (n + 1) / 2;
    // dp[i][0]: minimal disturbance when the i-th pair is taken without swap.
    // dp[i][1]: minimal disturbance when the i-th pair is taken as swapped.
    vector<vector<int>> dp(sz, vector<int>(2, 0));

    // Process pairs from the second pair onwards.
    for (int i = 1; i < sz; i++)
    {
        // Transition when the current pair is not swapped (dp[i][0]):
        // Compare current front element (a[i]) with previous front and current back (a[n-i-1]) with previous back.
        // Two scenarios: inheriting from previous not swapped or swapped arrangement.
        dp[i][0] =
            min(dp[i - 1][0] + (a[i] == a[i - 1]) + (a[n - i - 1] == a[n - i]),
                dp[i - 1][1] + (a[i] == a[n - i]) + (a[n - i - 1] == a[i - 1]));

        // Transition when the current pair is swapped (dp[i][1]):
        // Here the roles of the two elements in the pair are reversed. The comparisons are accordingly adjusted.
        dp[i][1] =
            min(dp[i - 1][1] + (a[i] == a[i - 1]) + (a[n - i - 1] == a[n - i]),
                dp[i - 1][0] + (a[i] == a[n - i]) + (a[n - i - 1] == a[i - 1]));
    } // end for pairs

    // The answer is the minimal disturbance among both configurations for the last pair.
    int ans = min(dp[sz - 1][0], dp[sz - 1][1]);

    // For even n, adjust the cost of the split between the two halves.
    if (n % 2 == 0)
        ans += (a[n / 2 - 1] == a[n / 2]);

    cout << ans << '\n';
}

/*
Even in university, students need to relax. That is why Sakurakos teacher decided to go on a field trip. It is known that all of the students will be walking in one line. The student with index i
 has some topic of interest which is described as ai
. As a teacher, you want to minimise the disturbance of the line of students.

The disturbance of the line is defined as the number of neighbouring people with the same topic of interest. In other words, disturbance is the number of indices j
 (1≤j<n
) such that aj=aj+1
.

In order to do this, you can choose index i
 (1≤i≤n
) and swap students at positions i
 and n−i+1
. You can perform any number of swaps.

Your task is to determine the minimal amount of disturbance that you can achieve by doing the operation described above any number of times.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case is described by two lines.

The first line contains one integer n
 (2≤n≤105
) — the length of the line of students.
The second line contains n
 integers ai
 (1≤ai≤n
) — the topics of interest of students in line.
It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimal possible disturbance of the line that you can achieve.

Example
InputCopy
9
5
1 1 1 2 3
6
2 1 2 2 1 1
4
1 2 1 1
6
2 1 1 2 2 4
4
2 1 2 3
6
1 2 2 1 2 1
5
4 5 5 1 5
7
1 4 3 5 1 1 3
7
3 1 3 2 2 3 3
OutputCopy
1
2
1
0
0
1
1
0
2
Note
In the first example, it is necessary to apply the operation to i=2
, thus the array will become [1,2,1,1,3]
, with the bold elements indicating those that have swapped places. The disturbance of this array is equal to 1
.

In the fourth example, it is sufficient to apply the operation to i=3
, thus the array will become [2,1,2,1,2,4]
. The disturbance of this array is equal to 0
.

In the eighth example, it is sufficient to apply the operation to i=3
, thus the array will become [1,4,1,5,3,1,3]
. The disturbance of this array is equal to 0
.


4

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
