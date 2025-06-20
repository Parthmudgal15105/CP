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
    int length;
    cin >> length;
    string s;
    cin >> s;
    int cost = length;
    int transitions = 0;

    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            transitions++;
        }
    }
    if (s[0] == '1')
    {
        transitions++;
    }
    if (transitions == 2)
    {
        transitions--;
    }
    else if (transitions > 2)
    {
        transitions = transitions - 2;
    }
    cost += transitions;
    cout << cost << endl;
}
/*
You are given a binary string s
 of length n
 and a typewriter with two buttons: 0 and 1. Initially, your finger is on the button 0. You can do the following two operations:

Press the button your finger is currently on. This will type out the character that is on the button.
Move your finger to the other button. If your finger is on button 0, move it to button 1, and vice versa.
The cost of a binary string is defined as the minimum number of operations needed to type the entire string.

Before typing, you may reverse at most one substring∗
 of s
. More formally, you can choose two indices 1≤l≤r≤n
, and reverse the substring sl…r
, resulting in the new string s1s2…sl−1srsr−1…slsr+1…sn
.

Your task is to find the minimum possible cost among all strings obtainable by performing at most one substring reversal on s
.

∗
A string a
 is a substring of a string b
 if a
 can be obtained from b
 by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the length of the binary string s
.

The second line of each test case contains a binary string s1s2…sn
 (si=0
 or si=1
) — the characters of the binary string s
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum cost of string s
 after performing at most one substring reversal.

Example
InputCopy
6
3
000
3
111
3
011
3
100
5
10101
19
1101010010011011100
OutputCopy
3
4
4
4
8
29
Note
In the first test case, we can choose not to reverse any substrings. We can do operation 1
 three times to type 000.

In the second test case, we can choose not to reverse any substrings. We can do operation 2
 to move our finger to button 1. Then, we do operation 1
 three times to type 111.

In the third test case, we can choose not to reverse any substring. We can do operation 1
 to type 0. Then, we do operation 2
 to move our finger to button 1. Finally, we do operation 1
 two times to type 11, resulting in the final string 011 using only 4
 operations.

In the fourth test case, we can reverse the substring s1…3
, resulting in the string 001. We can do operation 1
 two times to type 00. Then we do operation 2
 to move our finger to button 1. Finally, we do operation 1
 once to type 1, resulting in the final string 001 using only 4
 operations.

In the fifth test case, we can reverse the substring s2…3
, resulting in the string 11001. The cost of the string is 8
 as we can do the following sequence of operations:

Do operation 2
 to move our finger to button 1.
Do operation 1
 two times to type 11.
Do operation 2
 to move our finger to button 0.
Do operation 1
 two times to type 00.
Do operation 2
 to move our finger to button 1.
Do operation 1
 once to type 1.
In the sixth test case, we can reverse the substring s5…17
, resulting in the string 1101111011001001000. It can be proven that the minimum number of operations needed to type the binary string is 29
.*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
