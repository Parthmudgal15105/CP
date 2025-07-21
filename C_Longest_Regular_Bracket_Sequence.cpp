#include <bits/stdc++.h>             // Includes most standard C++ libraries
#include <algorithm>                 // For algorithms like sort, etc.
#include <ext/pb_ds/tree_policy.hpp> // For advanced data structures (not used here)
using namespace std;
#pragma GCC optimize("Ofast")            // Compiler optimization
#pragma GCC target("avx,avx2,fma")       // Target specific CPU instructions
#pragma GCC optimization("unroll-loops") // Loop unrolling optimization

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
bool odd(ll num) { return ((num & 1) == 1); }  // Returns true if num is odd
bool even(ll num) { return ((num & 1) == 0); } // Returns true if num is even

//////////////////////////////////////////////////////// Prime

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) // Check divisibility up to sqrt(n)
    {
        if (n % i == 0)
            return false; // Not prime if divisible
    }
    return true; // Prime if no divisors found
}

///////////////////////////////////////////////////////// LCM GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b; // Euclidean algorithm
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b; // LCM formula
}
////////////////////////////////////////////////////////// SQR ROOT

long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1; // Move right if m*m <= x
        else
            e = m - 1; // Move left otherwise
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
    string s;              // Input string of brackets
    cin >> s;              // Read the string
    stack<int> st;         // Stack to store indices of '('
    int n = (int)s.size(); // Length of the string
    vi dp(n, 0);           // dp[i] stores the length of the longest valid bracket sequence ending at i

    int length = 0, cnt = 0; // length: max length found, cnt: number of such substrings
    for (int i = 0; i < n; i++)
    {
        char c = s[i]; // Current character
        if (c == '(')
        {
            st.push(i); // Push index of '(' onto stack
            continue;   // Move to next character
        }
        if (st.empty())
        {
            continue; // No matching '(' for current ')', skip
        }
        int j = st.top(); // Index of matching '('
        st.pop();         // Remove it from stack
        // dp[i]: length of valid substring ending at i
        // i-j+1: length between matching '(' and ')'
        // If there is a valid sequence ending just before j, add its length
        dp[i] = i - j + 1 + (j >= 1 ? dp[j - 1] : 0);
        if (dp[i] > length)
        {
            length = dp[i]; // Update max length
            cnt = 1;        // Reset count
        }
        else if (dp[i] == length)
        {
            cnt++; // Another substring of max length found
        }
    }
    if (length == 0)
    {
        cout << 0 << sp << 1; // If no valid sequence, output "0 1"
    }
    else
    {
        cout << length << sp << cnt; // Output max length and count
    }
}

/*
This is yet another problem dealing with regular bracket sequences.

We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not.

You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.

Input
The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

Output
Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".

Examples
InputCopy
)((())))(()())
OutputCopy
6 2
InputCopy
))(
OutputCopy
0 1
 */

int main()
{
    ios::sync_with_stdio(0); // Fast IO
    cin.tie(0);              // Untie cin from cout

    int t = 1; // Number of test cases (fixed to 1 for this problem)

    while (t--)
        solve(); // Solve each test case
}
