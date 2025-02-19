#include <bits/stdc++.h>			 // Standard library includes
#include <ext/pb_ds/tree_policy.hpp> // For advanced data structures
using namespace std;

// Compiler optimization flags
#pragma GCC optimize("Ofast")			 // Fast optimization
#pragma GCC target("avx,avx2,fma")		 // Use specific CPU instructions
#pragma GCC optimization("unroll-loops") // Loop unrolling optimization

// Macros for common operations
#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Control Flow macros
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// Type aliases for convenience
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

// Utility macros
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants and RNG initialization
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Helper Functions
// Returns true if the number is odd
bool odd(ll num)
{
	return ((num & 1) == 1);
}
// Returns true if the number is even
bool even(ll num)
{
	return ((num & 1) == 0);
}
// Returns a random number between l and r inclusive
ll getRandomNumber(ll l, ll r)
{
	return uniform_int_distribution<ll>(l, r)(rng);
}
// Computes the binomial coefficient nCk
ll nCk(ll n, ll k)
{
	ll res = 1;
	for (ll i = 0; i < k; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}

void solve()
{
	// Read input values: array size 'n' and divisor 'k'
	int n, k;
	cin >> n >> k;

	vi arr(n);
	// Input array elements
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// Initialize variables:
	// d: minimum operations needed to adjust an element modulo k
	// e_cnt: count of even numbers
	int d = k - 1;
	int e_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (even(arr[i]))
			e_cnt++;

		// Adjust d based on divisibility by k
		if (arr[i] % k == 0)
			d = 0;
		else
			d = min(d, k - arr[i] % k);
	}

	// Logic handling for k == 4 with special conditions for even counts
	if (k != 4)
	{
		cout << d << nl;
	}
	else
	{
		if (e_cnt >= 2)
			cout << 0 << nl;
		else if (e_cnt == 1)
			cout << min(d, 1) << nl;
		else // No even numbers present
			cout << min(2, d) << nl;
	}
}

/*
You are given an array of integers a1,a2,…,an
 and a number k
 (2≤k≤5
). In one operation, you can do the following:

Choose an index 1≤i≤n
,
Set ai=ai+1
.
Find the minimum number of operations needed to make the product of all the numbers in the array a1⋅a2⋅…⋅an
 divisible by k
.

Input
Each test consists of multiple test cases. The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers n
 and k
 (2≤n≤105
, 2≤k≤5
) — the size of the array a
 and the number k
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤10
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k
.

Example
InputCopy
15
2 5
7 3
3 3
7 4 1
5 2
9 7 7 3 9
5 5
5 4 1 2 3
7 4
9 5 1 5 9 5 1
3 4
6 3 6
3 4
6 1 5
3 4
1 5 9
4 4
1 4 1 1
3 4
3 5 3
4 5
8 9 9 3
2 5
1 6
2 5
10 10
4 5
1 6 1 1
2 5
7 7
OutputCopy
2
2
1
0
2
0
1
2
0
1
1
4
0
4
3
Note
In the first test case, we need to choose the index i=2
 twice. After that, the array will be a=[7,5]
. The product of all the numbers in the array is 35
.

In the fourth test case, the product of the numbers in the array is 120
, which is already divisible by 5
, so no operations are needed.

In the eighth test case, we can perform two operations by choosing i=2
 and i=3
 in any order. After that, the array will be a=[1,6,10]
. The product of the numbers in the array is 60
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