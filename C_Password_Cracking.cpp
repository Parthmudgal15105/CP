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
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
*/

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
    int n;
    cin >> n;

    deque<char> ans;
    int type = 0;
    int queries_count = 0;

    // Interactive query lambda:
    // This sends a query using the format "? <string>".
    // IMPORTANT: Always flush output (endl flushes in C++), or use fflush(stdout) if required.
    auto query = [&](char ch)
    {
        if (++queries_count > 2 * n)
            return 1;
        cout << "? ";
        if (type == 0)
            cout << ch;
        for (char c : ans)
        {
            cout << c;
        }
        if (type == 1)
            cout << ch;
        cout << endl; // flushes output automatically
        // fflush(stdout); // Uncomment if additional flush is needed for your environment

        int res;
        cin >> res;
        return res;
    };

    // Interactive answer lambda:
    // This prints the final answer using the format "! <password>".
    auto answer = [&]()
    {
        cout << "! ";
        for (char c : ans)
            cout << c;
        cout << endl; // flushes output - mandatory for interactive problems
        // fflush(stdout); // Uncomment if additional flush is needed for your environment
    };

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (char c = '0'; c <= '1'; c++)
        {
            if (query(c) == 1)
            {
                if (type == 0)
                    ans.push_front(c);
                else
                    ans.push_back(c);
                found = true;
                break;
            }
        }
        if (!found)
        {
            assert(++type <= 1);
            i--;
        }
    }

    answer();
}

/*
Dimash learned that Mansur wrote something very unpleasant about him to a friend, so he decided to find out his password at all costs and discover what exactly he wrote.

Believing in the strength of his password, Mansur stated that his password — is a binary string of length n
. He is also ready to answer Dimash's questions of the following type:

Dimash says a binary string t
, and Mansur replies whether it is true that t
 is a substring of his password.

Help Dimash find out the password in no more than 2n
 operations; otherwise, Mansur will understand the trick and stop communicating with him.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100
). The description of the test cases follows.

Interaction
At the beginning of each test case, first read n
 (1≤n≤100
) — the size of the binary string. Then proceed to guessing it.

To guess each string s
, you can make no more than 2n
 queries of the following type:

"? t", where t
 is a binary string such that (1≤|t|≤n
).
In response to this query, you will receive 1
 if t
 is a substring of s
, and 0
 otherwise.

Once you receive the answer, output a single string in the following format:

"! s", where s
 is a binary string of size n
.
After that, proceed to solve the next test case.

If you make an incorrect attempt or exceed the limit of 2n
 attempts, you will receive −1
 instead of an answer and get the verdict Wrong answer. In this case, your program should terminate immediately to avoid undefined verdicts.

After outputting the queries, do not forget to output a newline character and flush the output buffer. Otherwise, you will receive the verdict Solution "hung". To flush the buffer, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
refer to the documentation for other languages.
Hacks:

To use hacks, use the following format of tests:

The first line should contain a single integer t
 (1≤t≤100
) — the number of test cases.

The first line of each test case should contain a single number n
 (1≤n≤100
) — the length of the string. The second line should contain a binary string of size n
.

Example
InputCopy
4
3

0

0

1

4

4

2
OutputCopy


? 00

? 000

? 010

! 010

! 1100

! 0110

! 10
Note
In the first example, the string 010
 is given. Therefore, the answers to the queries are as follows:

"? 00" 00
 is not a substring of 010
, so the answer is 0
.

"? 000" 000
 is not a substring, so the answer is 0
.

"? 010" 010
 is a substring, so the answer is 1
.

In the second example, the string is 1100
, in the third 0110
, and in the fourth 10
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
