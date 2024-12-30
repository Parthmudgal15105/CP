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

bool isPalindrome(string &s, char skip)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        while (i < j && s[i] == skip)
            i++;
        while (i < j && s[j] == skip)
            j--;
        if (i < j && s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    set<char> uniqueChars(s.begin(), s.end());
    int answer = INT_MAX;

    for (char ch : uniqueChars)
    {
        int l = 0, r = n - 1, deletions = 0;
        bool possible = true;

        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else if (s[l] == ch)
            {
                l++;
                deletions++;
            }
            else if (s[r] == ch)
            {
                r--;
                deletions++;
            }
            else
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            answer = min(answer, deletions);
        }
    }

    cout << (answer == INT_MAX ? -1 : answer) << nl;
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
