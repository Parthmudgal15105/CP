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
    int n;
    cin >> n;

    // Use a single-dimensional array instead of pair
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Calculate total sum and build frequency map
    long long sum = 0;
    unordered_map<ll, int> freq;
    for (auto &val : a)
    {
        sum += val;
        freq[val]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        long long new_sum = sum - a[i];
        if (new_sum % 2 == 0)
        {
            long long x = new_sum / 2;
            // Temporarily remove a[i]
            freq[a[i]]--;
            if (freq[x] > 0) // Check if x still exists
                ans.push_back(i + 1);
            // Restore a[i]
            freq[a[i]]++;
        }
    }

    cout << ans.size() << nl;
    for (auto &idx : ans)
        cout << idx << " ";
    cout << nl;
}

/*
Let's call an array good if there is an element in the array that equals to the sum of all other elements. For example, the array a=[1,3,3,7]
 is good because there is the element a4=7
 which equals to the sum 1+3+3
.

You are given an array a
 consisting of n
 integers. Your task is to print all indices j
 of this array such that after removing the j
-th element from the array it will be good (let's call such indices nice).

For example, if a=[8,3,5,2]
, the nice indices are 1
 and 4
:

if you remove a1
, the array will look like [3,5,2]
 and it is good;
if you remove a4
, the array will look like [8,3,5]
 and it is good.
You have to consider all removals independently, i. e. remove the element, check if the resulting array is good, and return the element into the array.

Input
The first line of the input contains one integer n
 (2≤n≤2⋅105
) — the number of elements in the array a
.

The second line of the input contains n
 integers a1,a2,…,an
 (1≤ai≤106
) — elements of the array a
.

Output
In the first line print one integer k
 — the number of indices j
 of the array a
 such that after removing the j
-th element from the array it will be good (i.e. print the number of the nice indices).

In the second line print k
 distinct integers j1,j2,…,jk
 in any order — nice indices of the array a
.

If there are no such indices in the array a
, just print 0
 in the first line and leave the second line empty or do not print it at all.

Examples
InputCopy
5
2 5 1 2 2
OutputCopy
3
4 1 5
InputCopy
4
8 3 5 2
OutputCopy
2
1 4
InputCopy
5
2 1 2 4 3
OutputCopy
0

Note
In the first example you can remove any element with the value 2
 so the array will look like [5,1,2,2]
. The sum of this array is 10
 and there is an element equals to the sum of remaining elements (5=1+2+2
).

In the second example you can remove 8
 so the array will look like [3,5,2]
. The sum of this array is 10
 and there is an element equals to the sum of remaining elements (5=3+2
). You can also remove 2
 so the array will look like [8,3,5]
. The sum of this array is 16
 and there is an element equals to the sum of remaining elements (8=3+5
).

In the third example you cannot make the given array good by removing exactly one element.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();
}
