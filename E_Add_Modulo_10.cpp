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
    cin >> n; // read number of elements

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // read each element

        // Mathematical insight: When repeatedly adding the last digit to a number,
        // eventually all numbers will end with either 0 or 2
        // We apply the operation multiple times to reach this stable state
        for (int j = 0; j < 10; j++)
        {
            a[i] += a[i] % 10; // add the current last digit
        }

        // If we haven't reached a stable last digit (0 or 2) yet,
        // continue applying the operation until we do
        // - Numbers ending with 0 will stay the same (adding 0 changes nothing)
        // - Numbers ending with 2 will follow a pattern cycling through values mod 20
        while (a[i] % 10 != 2 && a[i] % 10 != 0)
        {
            a[i] += a[i] % 10; // add last digit again
        }

        // For numbers ending with 2, they follow a cycle of length 20:
        // If x ≡ 2 (mod 10), then after applying operations:
        // x → x+2 → (x+2)+2 → ... and so on
        // Eventually we get: 2→4→8→16→14→18→16→... (cycling with period 20)
        if (a[i] % 10 == 2)
        {
            a[i] %= 20; // normalize to canonical form (either 2 or 12)
        }
        // Numbers ending with 0 stay fixed and don't change with further operations
    }

    // if all transformed values equal the first one, answer is YES
    if (a == vi(n, a[0]))
    {
        cyes; // print YES
    }
    else
    {
        cno; // print NO
    }
}

/*
You are given an array of n
 integers a1,a2,…,an

You can apply the following operation an arbitrary number of times:

select an index i
 (1≤i≤n
) and replace the value of the element ai
 with the value ai+(aimod10)
, where aimod10
 is the remainder of the integer dividing ai
 by 10
.
For a single index (value i
), this operation can be applied multiple times. If the operation is applied repeatedly to the same index, then the current value of ai
 is taken into account each time. For example, if ai=47
 then after the first operation we get ai=47+7=54
, and after the second operation we get ai=54+4=58
.

Check if it is possible to make all array elements equal by applying multiple (possibly zero) operations.

For example, you have an array [6,11]
.

Let's apply this operation to the first element of the array. Let's replace a1=6
 with a1+(a1mod10)=6+(6mod10)=6+6=12
. We get the array [12,11]
.
Then apply this operation to the second element of the array. Let's replace a2=11
 with a2+(a2mod10)=11+(11mod10)=11+1=12
. We get the array [12,12]
.
Thus, by applying 2
 operations, you can make all elements of an array equal.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases. What follows is a description of each test case.

The first line of each test case contains one integer n
 (1≤n≤2⋅105
) — the size of the array.

The second line of each test case contains n
 integers ai
 (0≤ai≤109
) — array elements.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case print:

YES if it is possible to make all array elements equal;
NO otherwise.
You can print YES and NO in any case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer) .

Example
InputCopy
10
2
6 11
3
2 18 22
5
5 10 5 10 5
4
1 2 4 8
2
4 5
3
93 96 102
2
40 6
2
50 30
2
22 44
2
1 5
OutputCopy
Yes
No
Yes
Yes
No
Yes
No
No
Yes
No
Note
The first test case is clarified above.

In the second test case, it is impossible to make all array elements equal.

In the third test case, you need to apply this operation once to all elements equal to 5
.

In the fourth test case, you need to apply this operation to all elements until they become equal to 8
.

In the fifth test case, it is impossible to make all array elements equal.

In the sixth test case, you need to apply this operation to all elements until they become equal to 102
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
