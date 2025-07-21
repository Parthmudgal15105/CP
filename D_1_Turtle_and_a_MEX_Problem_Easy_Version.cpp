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

/*
PROBLEM EXPLANATION:
--------------------
Given n sequences of integers, and a non-negative integer m, for each x in [0, m], define f(x) as the maximum value you can reach starting from x by repeatedly applying the following operation any number of times:
- Choose any sequence, and set x to the mex (minimum excluded value) of x and all elements of the chosen sequence.

You are to compute the sum f(0) + f(1) + ... + f(m).

SOLUTION EXPLANATION:
---------------------
- For each test case, for each sequence, collect all numbers present in the sequence.
- For each sequence, the maximum value you can reach by applying the operation is the smallest non-negative integer not present in the sequence (i.e., the mex of the sequence).
- The overall maximum value you can reach from any x is the maximum mex among all sequences.
- For x > this maximum mex, f(x) = x (since x is not present in any sequence, so mex(x, ...) = x+1).
- For x <= this maximum mex, f(x) = maximum mex.

So, for all x in [0, m]:
- If m <= maximum mex, then f(x) = maximum mex for all x in [0, m], so the answer is (m+1) * maximum mex.
- If m > maximum mex, then for x in [0, maximum mex], f(x) = maximum mex, and for x in [maximum mex+1, m], f(x) = x.
  The answer is: (maximum mex + 1) * maximum mex + sum_{x=maximum mex+1}^m x
  The sum of consecutive integers from a to b is (b*(b+1))/2 - ((a-1)*a)/2.

The code implements this logic efficiently for each test case.
*/

void solve()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll var = 0;
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
        ll len;
        cin >> len;
        while (len--)
        {
            ll num;
            cin >> num;
            st.insert(num);
        }
        int y = 0;
        ll j = 0;
        while (true)
        {
            if (st.find(j) == st.end())
            {
                if (y == 0)
                    y = 1;
                else
                {
                    var = max(var, j);
                    break;
                }
            }

            j++;
        }
        st.clear();
    }
    // cout<<var<<endl;
    if (var >= m)
    {
        cout << (m + 1) * var << endl;
    }
    else
    {
        cout << var * (var + 1) + (m * (m + 1)) / 2 - (var * (var + 1)) / 2 << endl;
    }
}

/*
The two versions are different problems. In this version of the problem, you can choose the same integer twice or more. You can make hacks only if both versions are solved.

One day, Turtle was playing with n
 sequences. Let the length of the i
-th sequence be li
. Then the i
-th sequence was ai,1,ai,2,…,ai,li
.

Piggy gave Turtle a problem to solve when Turtle was playing. The statement of the problem was:

There was a non-negative integer x
 at first. Turtle would perform an arbitrary number (possibly zero) of operations on the integer.
In each operation, Turtle could choose an integer i
 such that 1≤i≤n
, and set x
 to mex†(x,ai,1,ai,2,…,ai,li)
.
Turtle was asked to find the answer, which was the maximum value of x
 after performing an arbitrary number of operations.
Turtle solved the above problem without difficulty. He defined f(k)
 as the answer to the above problem when the initial value of x
 was k
.

Then Piggy gave Turtle a non-negative integer m
 and asked Turtle to find the value of ∑i=0mf(i)
 (i.e., the value of f(0)+f(1)+…+f(m)
). Unfortunately, he couldn't solve this problem. Please help him!

†mex(c1,c2,…,ck)
 is defined as the smallest non-negative integer x
 which does not occur in the sequence c
. For example, mex(2,2,0,3)
 is 1
, mex(1,2)
 is 0
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n,m
 (1≤n≤2⋅105,0≤m≤109
).

Each of the following n
 lines contains several integers. The first integer li
 (1≤li≤2⋅105
) represents the length of the i
-th sequence, and the following li
 integers ai,1,ai,2,…,ai,li
 (0≤ai,j≤109
) represent the elements of the i
-th sequence.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
, and the sum of ∑li
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the value of ∑i=0mf(i)
.

Example
InputCopy
6
3 4
2 0 2
3 2 3 3
4 7 0 1 5
3 4
5 0 2 0 4 11
1 1
5 1 3 0 3 3
2 50
2 1 2
2 1 2
1 1
7 1 2 4 1 4 9 5
4 114514
2 2 2
5 7 3 6 0 3
3 0 1 1
5 0 9 2 1 5
5 1919810
1 2
2 324003 0
3 1416324 2 1460728
4 1312631 2 0 1415195
5 1223554 192248 2 1492515 725556
OutputCopy
16
20
1281
6
6556785365
1842836177961
Note
In the first test case, when x
 is initially 2
, Turtle can choose i=3
 and set x
 to mex(x,a3,1,a3,2,a3,3,a3,4)=mex(2,7,0,1,5)=3
. It can be proved that Turtle can't make the value of x
 greater than 3
, so f(2)=3
.

It can be seen that f(0)=3
, f(1)=3
, f(2)=3
, f(3)=3
, and f(4)=4
. So f(0)+f(1)+f(2)+f(3)+f(4)=3+3+3+3+4=16
.

In the second test case, when x
 is initially 1
, Turtle can choose i=3
 and set x
 to mex(x,a3,1,a3,2,a3,3,a3,4,a3,5)=mex(1,1,3,0,3,3)=2
, and choose i=3
 and set x
 to mex(x,a3,1,a3,2,a3,3,a3,4,a3,5)=mex(2,1,3,0,3,3)=4
. It can be proved that Turtle can't make the value of x
 greater than 4
, so f(1)=4
.

It can be seen that f(0)=4
, f(1)=4
, f(2)=4
, f(3)=4
, and f(4)=4
. So f(0)+f(1)+f(2)+f(3)+f(4)=4+4+4+4+4=20
.

In the fourth test case, it can be seen that f(0)=3
 and f(1)=3
. So f(0)+f(1)=3+3=6
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
