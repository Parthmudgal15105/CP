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
/*
Dry Run for test case:
n = 2, k = 0
a[] = [2, 1]  // max prices for positive reviews
b[] = [3, 4]  // max prices for negative reviews

Step 1: Sort arrays
as = [1, 2]  // sorted a[]
bs = [3, 4]  // sorted b[]

Step 2: Collect candidate prices
candidates = [1, 2, 3, 4]

Step 3: For each price:

Price = 1:
- totalBuyers = 2 (both can buy at price 1)
- posCount = 2 (both give positive reviews as price ≤ their a[i])
- negCount = 0 (totalBuyers - posCount)
- negCount <= k (0 <= 0), so valid
- earnings = 1 * 2 = 2

Price = 2:
- totalBuyers = 2 (both can buy at price 2)
- posCount = 1 (only one gives positive review)
- negCount = 1 (one gives negative review)
- negCount > k (1 > 0), so invalid

Price = 3, 4:
- Similar calculations show these are invalid

Final answer = 2 (maximum valid earnings)
*/

long long countLessEqual(vector<long long> &arr, long long target)
{
    int left = 0, right = arr.size() - 1;
    int count = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            count = mid + 1; // including current element
            left = mid + 1;
        }
    }
    return count;
}

void solve()
{
    // Read the number of customers and the maximum allowed negative reviews
    int n, k;
    cin >> n >> k;

    // Read the array 'a' representing the maximum price for positive reviews
    vector<long long> a(n), b(n);
    for (auto &x : a)
        cin >> x;

    // Read the array 'b' representing the maximum price for negative reviews
    for (auto &x : b)
        cin >> x;

    // Create sorted copies of 'a' and 'b' for binary search
    vector<long long> as = a, bs = b;
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    // Collect all unique candidate prices from both 'a' and 'b'
    vector<long long> candidates;
    candidates.reserve(2LL * n);
    for (int i = 0; i < n; i++)
    {
        candidates.push_back(a[i]);
        candidates.push_back(b[i]);
    }
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    long long ans = 0; // Initialize the maximum earnings

    // Iterate through each candidate price to evaluate earnings
    for (auto price : candidates)
    {
        // Calculate the number of buyers who will buy at this price (positive + negative)
        // Equivalent to the number of b[i] >= price
        long long totalBuyers = n - countLessEqual(bs, price - 1);

        // Calculate the number of buyers who will leave positive reviews
        // Equivalent to the number of a[i] >= price
        long long posCount = n - countLessEqual(as, price - 1);

        // Calculate the number of buyers who will leave negative reviews
        long long negCount = totalBuyers - posCount;

        // If the number of negative reviews is within the allowed limit, update the maximum earnings
        if (negCount <= k)
            ans = max(ans, price * totalBuyers);
    }

    // Output the maximum possible earnings
    cout << ans << nl;
}

/*
A batch of Christmas trees has arrived at the largest store in Berland. n
 customers have already come to the store, wanting to buy them.

Before the sales begin, the store needs to determine the price for one tree (the price is the same for all customers). To do this, the store has some information about each customer.

For the i
-th customer, two integers ai
 and bi
 are known, which define their behavior:

if the price of the product is at most ai
, the customer will buy a tree and leave a positive review;
otherwise, if the price of the product is at most bi
, the customer will buy a tree but leave a negative review;
otherwise, the customer will not buy a tree at all.
Your task is to calculate the maximum possible earnings for the store, given that it can receive no more than k
 negative reviews.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤2⋅105
; 0≤k≤n
).

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤2⋅109
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤2⋅109
; ai<bi
).

Additional constraint on the input: the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible earnings for the store, given that it can receive no more than k
 negative reviews.

Example
InputCopy
5
2 0
2 1
3 4
1 1
2
5
3 3
1 5 2
3 6 4
4 3
2 3 2 8
3 7 3 9
3 1
2 9 5
12 14 9
OutputCopy
2
5
9
14
15
Note
Consider the example from the statement:

In the first test case, the price should be set to 1
. Then both customers will buy one tree each and leave no negative reviews;
In the second test case, the price should be set to 5
. Then the only customer will buy a tree and leave a negative review;
In the third test case, the price should be set to 3
. Then all customers will buy one tree each, and the store will receive two negative reviews.
In the fourth test case, the price should be set to 7
. Then two customers will buy one tree each, and the store will receive one negative review.
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
