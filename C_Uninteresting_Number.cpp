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
    int size = s.size();
    int sum = 0, c3 = 0, c2 = 0;
    for (int i = 0; i < size; i++)
    {
        sum += s[i] - '0';
        if (s[i] == '3')
            c3++;
        if (s[i] == '2')
            c2++;
    }
    int val = sum % 9;
    for (int i = 0; i <= 8; i++, c2--)
    {
        for (int j = 0; j <= 8; j++)
        {
            if (j > c3)
                break;
            int cur = val + (i * 2) + (j * 6);
            if (cur % 9 == 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
        if (!c2)
            break;
    }
    cout << "NO" << endl;
}

/*
The requirement that a digit must remain a digit imposes the following restrictions on transformations: we can transform 0
 into 0
, 1
 into 1
, 2
 into 4
, and 3
 into 9
. Any other digit squared will exceed 9, therefore, it cannot be transformed. Transformations involving 0
 and 1
 are useless, leaving us with two possible actions: squaring the digit 2
 or the digit 3
.

We will use the divisibility rule for 9
. It states that a number is divisible by 9
 if and only if the sum of its digits is divisible by 9
. Let's see how the sum of the digits will change with the possible transformations. If we square 2
, the sum of the digits increases by 22−2=2
, and if we square 3
, the sum of the digits increases by 32−3=6
.

We will count the number of digits 2
 in the number and the number of digits 3
 in the number. We can choose how many of the available digits 2
 and 3
 we will transform. Transforming more than 8 twos and more than 8 threes is pointless because remainders modulo 9
 their transformation adds to the sum will repeat.

Thus, the final solution looks like this: we calculate the sum of the digits in the number, count the number of digits 2
 and 3
. We will iterate over how many digits 2
 we change (possibly 0, but no more than 8), and how many digits 3
 we change (possibly 0, but also no more than 8). Let's say we changed x
 digits 2
 and y
 digits 3
, then the sum of the digits in the number increased by x∗2+y∗6
. If new sum is divisible by 9
, the answer is "YES". If such a situation was never reached during the iteration, then the answer is "NO".

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
