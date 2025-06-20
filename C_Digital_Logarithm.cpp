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
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    priority_queue<int> qa(a.begin(), a.end());
    priority_queue<int> qb(all(b));

    int ans = 0;

    while (!qa.empty())
    {
        if (qa.top() == qb.top())
        {
            qa.pop();
            qb.pop();
            continue;
        }
        ++ans; // We increment ans here because we are about to perform an operation
               // (either on qa.top() or qb.top()) to reduce the difference between the arrays.
               // The actual operation (replacing the number with its number of digits) is done
               // immediately after this increment, before the next comparison.
        // If the largest element in 'a' is greater than the largest in 'b',
        // we need to reduce 'a's element to try to match 'b's.
        // We do this by replacing qa.top() with its digital logarithm (number of digits).
        // This simulates the allowed operation: replace ai with f(ai).
        if (qa.top() > qb.top())
        {
            qa.push(to_string(qa.top()).size()); // Replace ai with its number of digits
            qa.pop();
        }
        // Otherwise, the largest in 'b' is greater, so we reduce 'b's element similarly.
        // We replace qb.top() with its digital logarithm (number of digits).
        else
        {
            qb.push(to_string(qb.top()).size()); // Replace bi with its number of digits
            qb.pop();
        }
    }
    cout << ans << nl;
}

/*
Let's define f(x)
 for a positive integer x
 as the length of the base-10 representation of x
 without leading zeros. I like to call it a digital logarithm. Similar to a digital root, if you are familiar with that.

You are given two arrays a
 and b
, each containing n
 positive integers. In one operation, you do the following:

pick some integer i
 from 1
 to n
;
assign either f(ai)
 to ai
 or f(bi)
 to bi
.
Two arrays are considered similar to each other if you can rearrange the elements in both of them, so that they are equal (e. g. ai=bi
 for all i
 from 1
 to n
).

What's the smallest number of operations required to make a
 and b
 similar to each other?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of testcases.

The first line of the testcase contains a single integer n
 (1≤n≤2⋅105
) — the number of elements in each of the arrays.

The second line contains n
 integers a1,a2,…,an
 (1≤ai<109
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bj<109
).

The sum of n
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print the smallest number of operations required to make a
 and b
 similar to each other.

Example
InputCopy
4
1
1
1000
4
1 2 3 4
3 1 4 2
3
2 9 3
1 100 9
10
75019 709259 5 611271314 9024533 81871864 9 3 6 4865
9503 2 371245467 6 7 37376159 8 364036498 52295554 169
OutputCopy
2
0
2
18
Note
In the first testcase, you can apply the digital logarithm to b1
 twice.

In the second testcase, the arrays are already similar to each other.

In the third testcase, you can first apply the digital logarithm to a1
, then to b2
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
