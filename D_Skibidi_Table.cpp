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

// Helper function: returns value at cell (x,y) in a 2^n x 2^n table
ll getValue(int n, int x, int y)
{
    if (n == 1)
    { // base 2x2
        // mapping: (1,1)=1, (1,2)=4, (2,1)=3, (2,2)=2
        if (x == 1 && y == 1)
            return 1;
        if (x == 1 && y == 2)
            return 4;
        if (x == 2 && y == 1)
            return 3;
        if (x == 2 && y == 2)
            return 2;
    }
    int half = 1 << (n - 1);
    ll block_size = 1LL << (2 * (n - 1));
    int quadrant, new_x, new_y;
    if (x <= half && y <= half)
    {
        quadrant = 0;
        new_x = x;
        new_y = y;
    }
    else if (x > half && y > half)
    {
        quadrant = 1;
        new_x = x - half;
        new_y = y - half;
    }
    else if (x > half && y <= half)
    {
        quadrant = 2;
        new_x = x - half;
        new_y = y;
    }
    else
    { // (x<=half && y>half)
        quadrant = 3;
        new_x = x;
        new_y = y - half;
    }
    return quadrant * block_size + getValue(n - 1, new_x, new_y);
}

// Helper function: returns cell coordinates for number d in a 2^n x 2^n table
pair<int, int> getCoord(int n, ll d)
{
    if (n == 1)
    { // base 2x2 mapping
        if (d == 1)
            return {1, 1};
        if (d == 2)
            return {2, 2};
        if (d == 3)
            return {2, 1};
        if (d == 4)
            return {1, 2};
    }
    int half = 1 << (n - 1);
    ll block_size = 1LL << (2 * (n - 1));
    int quadrant = (d - 1) / block_size;
    ll remainder = d - quadrant * block_size;
    auto sub = getCoord(n - 1, remainder);
    if (quadrant == 0)
        return {sub.first, sub.second};
    else if (quadrant == 1)
        return {sub.first + half, sub.second + half};
    else if (quadrant == 2)
        return {sub.first + half, sub.second};
    else /* quadrant 3 */
        return {sub.first, sub.second + half};
}

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "->")
        {
            int x, y;
            cin >> x >> y;
            cout << getValue(n, x, y) << nl;
        }
        else if (op == "<-")
        {
            ll d;
            cin >> d;
            auto res = getCoord(n, d);
            cout << res.first << sp << res.second << nl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
