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

/*----------------------------------------------------------------------------*/
void solve()
{
    int n, m;
    long long v;
    cin >> n >> m >> v;
    vector<long long> taste(n);
    for (int i = 0; i < n; i++)
        cin >> taste[i];

    // build prefix sum for quick subarray sums
    vector<long long> psum(n + 1, 0);
    for (int i = 0; i < n; i++)
        psum[i + 1] = psum[i] + taste[i];

    // prefixIndices[x] = smallest index so that we formed x subarrays from left
    vector<int> prefixIndices(m + 1, -1);
    prefixIndices[0] = 0;
    {
        long long partSum = 0;
        int count = 0, idx = 0;
        while (idx < n && count < m)
        {
            partSum += taste[idx++];
            if (partSum >= v)
            {
                count++;
                prefixIndices[count] = idx;
                partSum = 0;
            }
        }
    }

    // suffixIndices[x] = largest index so that we formed x subarrays from right
    vector<int> suffixIndices(m + 1, -1);
    suffixIndices[0] = n;
    {
        long long partSum = 0;
        int count = 0, idx = n - 1;
        while (idx >= 0 && count < m)
        {
            partSum += taste[idx--];
            if (partSum >= v)
            {
                count++;
                suffixIndices[count] = idx + 1;
                partSum = 0;
            }
        }
    }

    long long ans = -1;
    // try x subarrays from left, m-x from right
    for (int x = 0; x <= m; x++)
    {
        int leftEnd = prefixIndices[x];
        int rightStart = suffixIndices[m - x];
        if (leftEnd != -1 && rightStart != -1 && leftEnd <= rightStart)
        {
            long long leftover = psum[rightStart] - psum[leftEnd];
            ans = max(ans, leftover);
        }
    }
    cout << ans << nl;
}

/*
Alice is at the Mad Hatter's tea party! There is a long sheet cake made up of n
 sections with tastiness values a1,a2,…,an
. There are m
 creatures at the tea party, excluding Alice.

Alice will cut the cake into m+1
 pieces. Formally, she will partition the cake into m+1
 subarrays, where each subarray consists of some number of adjacent sections. The tastiness of a piece is the sum of tastiness of its sections. Afterwards, she will divvy these m+1
 pieces up among the m
 creatures and herself (her piece can be empty). However, each of the m
 creatures will only be happy when the tastiness of its piece is v
 or more.

Alice wants to make sure every creature is happy. Limited by this condition, she also wants to maximize the tastiness of her own piece. Can you help Alice find the maximum tastiness her piece can have? If there is no way to make sure every creature is happy, output −1
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains three integers n,m,v
 (1≤m≤n≤2⋅105
; 1≤v≤109
) — the number of sections, the number of creatures, and the creatures' minimum requirement for tastiness, respectively.

The next line contains n
 space separated integers a1,a2,…,an
 (1≤ai≤109
) — the tastinesses of the sections.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum tastiness Alice can achieve for her piece, or −1
 if there is no way to make sure every creature is happy.

Example
InputCopy
7
6 2 1
1 1 10 1 1 10
6 2 2
1 1 10 1 1 10
6 2 3
1 1 10 1 1 10
6 2 10
1 1 10 1 1 10
6 2 11
1 1 10 1 1 10
6 2 12
1 1 10 1 1 10
6 2 12
1 1 1 1 10 10
OutputCopy
22
12
2
2
2
0
-1
Note
For the first test case, Alice can give the first and second section as their own pieces, and then take the remaining 10+1+1+10=22
 tastiness for herself. We can show that she cannot do any better.

For the second test case, Alice could give the first and second section as one piece, and the sixth section as one piece. She can then take the remaining 10+1+1=12
 tastiness for herself. We can show that she cannot do any better.

For the seventh test case, Alice cannot give each creature a piece of at least 12
 tastiness.
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
