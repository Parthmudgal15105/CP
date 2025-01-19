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
    int numPoints;
    cin >> numPoints;
    vector<pair<ll, ll>> points(numPoints);
    for (int i = 0; i < numPoints; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    vector<pair<ll, ll>> bowlShape;
    for (auto &currentPoint : points)
    {
        while (bowlShape.size() >= 2)
        {
            ll prevY = bowlShape[bowlShape.size() - 2].second;

            ll prevX = bowlShape[bowlShape.size() - 2].first;

            ll currX = bowlShape[bowlShape.size() - 1].first;
            ll nextY = currentPoint.second;
            ll currY = bowlShape[bowlShape.size() - 1].second;
            ll nextX = currentPoint.first;

            ll crossProduct = (currX - prevX) * (nextY - prevY) -
                              (currY - prevY) * (nextX - prevX);

            if (crossProduct <= 0)
                bowlShape.pop_back();
            else
                break;
        }
        bowlShape.push_back(currentPoint);
    }

    long double bowlPerimeter = 0.0;
    for (int i = 0; i + 1 < (int)bowlShape.size(); i++)
    {
        long double deltaX = bowlShape[i + 1].first - bowlShape[i].first;
        long double deltaY = bowlShape[i + 1].second - bowlShape[i].second;
        bowlPerimeter += sqrtl(deltaX * deltaX + deltaY * deltaY);
    }

    cout << (ll)llround(bowlPerimeter) << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();
}
