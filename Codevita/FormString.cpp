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

string findMaxPossibleString(string target, vector<string> &words, int K)
{
    int n = target.length();
    vector<pair<bool, int>> dp(n + 1, {false, 0}); // {possible, deletions needed}
    dp[0] = {true, 0};

    int maxPossibleLen = 0;
    for (int i = 1; i <= n; i++)
    {
        for (const string &word : words)
        {
            if (word.length() <= i)
            {
                string sub = target.substr(i - word.length(), word.length());
                if (sub == word)
                {
                    if (dp[i - word.length()].first)
                    {
                        dp[i] = {true, dp[i - word.length()].second};
                        if (dp[i].second <= K)
                        {
                            maxPossibleLen = i;
                        }
                    }
                }
            }
        }
        if (!dp[i].first && dp[i - 1].first)
        {
            dp[i] = {true, dp[i - 1].second + 1};
            if (dp[i].second <= K)
            {
                maxPossibleLen = i;
            }
        }
    }

    if (maxPossibleLen == 0)
        return "Nothing";
    if (maxPossibleLen == n && dp[n].second <= K)
        return "Possible";
    if (maxPossibleLen == n && dp[n].second > K)
        return target.substr(0, maxPossibleLen);
    if (maxPossibleLen < n)
        return target.substr(0, maxPossibleLen);
    return "Impossible";
}

void solve()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    string target;
    int K;
    cin >> target >> K;

    cout << findMaxPossibleString(target, words, K) << nl;
}

/*

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
