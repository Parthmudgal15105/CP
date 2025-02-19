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
    string s;
    cin >> s;

    int q;
    cin >> q;

    int count = 0;
    for (int i = 0; i < (int)s.length() - 3; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        {
            count++;
        }
    }

    while (q--)
    {
        int pos;
        char val;
        cin >> pos >> val;
        pos--;

        for (int i = max(0, pos - 3); i <= min(pos, (int)s.length() - 4); i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                count--;
            }
        }

        s[pos] = val;

        for (int i = max(0, pos - 3); i <= min(pos, (int)s.length() - 4); i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                count++;
            }
        }

        cout << (count > 0 ? "YES" : "NO") << '\n';
    }
}

/*
While rummaging through things in a distant drawer, Anya found a beautiful string s
 consisting only of zeros and ones.

Now she wants to make it even more beautiful by performing q
 operations on it.

Each operation is described by two integers i
 (1≤i≤|s|
) and v
 (v∈{0,1}
) and means that the i
-th character of the string is assigned the value v
 (that is, the assignment si=v
 is performed).

But Anya loves the number 1100
, so after each query, she asks you to tell her whether the substring "1100" is present in her string (i.e. there exist such 1≤i≤|s|−3
 that sisi+1si+2si+3=1100
).

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

The first line of the test case contains the string s
 (1≤|s|≤2⋅105
), consisting only of the characters "0" and "1". Here |s|
 denotes the length of the string s
.

The next line contains an integer q
 (1≤q≤2⋅105
) — the number of queries.

The following q
 lines contain two integers i
 (1≤i≤|s|
) and v
 (v∈{0,1}
), describing the query.

It is guaranteed that the sum of |s|
 across all test cases does not exceed 2⋅105
. It is also guaranteed that the sum of q
 across all test cases does not exceed 2⋅105
.

Output
For each query, output "YES", if "1100" is present in Anya's string; otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
4
100
4
1 1
2 0
2 0
3 1
1100000
3
6 1
7 1
4 1
111010
4
1 1
5 0
4 1
5 0
0100
4
3 1
1 1
2 0
2 1
OutputCopy
NO
NO
NO
NO
YES
YES
NO
NO
YES
YES
YES
NO
NO
NO
NO
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
