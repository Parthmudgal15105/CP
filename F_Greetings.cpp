#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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

// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        v[i] = make_pair(a, b);
    }

    // Sort people by their starting positions
    sort(v.begin(), v.end());

    // Create ordered set to track ending positions
    Oset st;
    for (ll i = 0; i < n; i++)
    {
        st.insert(v[i].second);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        // Count how many people have ending positions < current ending position
        // These are the people this person will cross paths with
        ans += st.order_of_key(v[i].second);

        // Remove current person's ending position from set to avoid double counting
        st.erase(v[i].second);
    }

    cout << ans << endl;
    return;
}

/*
There are n
 people on the number line; the i
-th person is at point ai
 and wants to go to point bi
. For each person, ai<bi
, and the starting and ending points of all people are distinct. (That is, all of the 2n
 numbers a1,a2,…,an,b1,b2,…,bn
 are distinct.)

All the people will start moving simultaneously at a speed of 1
 unit per second until they reach their final point bi
. When two people meet at the same point, they will greet each other once. How many greetings will there be?

Note that a person can still greet other people even if they have reached their final point.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of people.

Then n
 lines follow, the i
-th of which contains two integers ai
 and bi
 (−109≤ai<bi≤109
) — the starting and ending positions of each person.

For each test case, all of the 2n
 numbers a1,a2,…,an,b1,b2,…,bn
 are distinct.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer denoting the number of greetings that will happen.

Example
InputCopy
5
2
2 3
1 4
6
2 6
3 9
4 5
1 8
7 10
-2 100
4
-10 10
-5 5
-12 12
-13 13
5
-4 9
-2 5
3 4
6 7
8 10
4
1 2
3 4
5 6
7 8
OutputCopy
1
9
6
4
0
Note
In the first test case, the two people will meet at point 3
 and greet each other.
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
