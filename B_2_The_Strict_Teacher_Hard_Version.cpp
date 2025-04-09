#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

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

// Utils ///////////////////////////////////////////////
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants/////////////////////////////////////////////
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m);
    for (auto &x : b)
        cin >> x;

    sort(b.begin(), b.end());

    while (q--)
    {
        int x;
        cin >> x;

        if (x < b[0])
        {
            cout << (b[0] - 1) << "\n";
        }
        else if (x > b.back())
        {
            cout << (n - b.back()) << "\n";
        }
        else
        {
            int id = lower_bound(b.begin(), b.end(), x) - b.begin();
            cout << ((b[id] - b[id - 1]) / 2) << "\n";
        }
    }
}

/*
This is the hard version of the problem. The only differences between the two versions are the constraints on m
 and q
. In this version, m,q≤105
. You can make hacks only if both versions of the problem are solved.

Narek and Tsovak were busy preparing this round, so they have not managed to do their homework and decided to steal David's homework. Their strict teacher noticed that David has no homework and now wants to punish him. She hires other teachers to help her catch David. And now m
 teachers together are chasing him. Luckily, the classroom is big, so David has many places to hide.

The classroom can be represented as a one-dimensional line with cells from 1
 to n
, inclusive.

At the start, all m
 teachers and David are in distinct cells. Then they make moves. During each move

David goes to an adjacent cell or stays at the current one.
Then, each of the m
 teachers simultaneously goes to an adjacent cell or stays at the current one.
This continues until David is caught. David is caught if any of the teachers (possibly more than one) is located in the same cell as David. Everyone sees others' moves, so they all act optimally.

Your task is to find how many moves it will take for the teachers to catch David if they all act optimally.

Acting optimally means the student makes his moves in a way that maximizes the number of moves the teachers need to catch him; and the teachers coordinate with each other to make their moves in a way that minimizes the number of moves they need to catch the student.

Also, as Narek and Tsovak think this task is easy, they decided to give you q
 queries on David's position.

Input
In the first line of the input, you are given a single integer t
 (1≤t≤105
) — the number of test cases. The description of each test case follows.

In the first line of each test case, you are given three integers n
, m
, and q
 (3≤n≤109
, 1≤m,q≤105
) — the number of cells on the line, the number of teachers, and the number of queries.

In the second line of each test case, you are given m
 distinct integers b1,b2,…,bm
 (1≤bi≤n
) — the cell numbers of the teachers.

In the third line of each test case, you are given q
 integers a1,a2,…,aq
 (1≤ai≤n
) — David's cell number for every query.

It is guaranteed that for any i
, j
 such that 1≤i≤m
 and 1≤j≤q
, bi≠aj
.

It is guaranteed that the sum of values of m
 over all test cases does not exceed 2⋅105
.

It is guaranteed that the sum of values of q
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output q
 lines, the i
-th of them containing the answer of the i
-th query.

Example
InputCopy
2
8 1 1
6
3
10 3 3
1 4 8
2 3 10
OutputCopy
5
1
1
2
Note
In the only query of the first example, the student can run to cell 1
. It will take the teacher five moves to reach from cell 6
 to cell 1
, so the answer is 5
.

In the second query of the second example, the student can just stay at cell 3
. The teacher, initially located in cell 4
, can reach cell 3
 in one move. Therefore, the answer is 1
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
