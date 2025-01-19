#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// Compiler optimizations for faster execution
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// Define common macros for ease of use
#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Type declarations for shorthand
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

// Functions to check if a number is odd or even
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

// Function to check if a number is prime
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to compute the greatest common divisor (GCD)
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

// Function to compute the least common multiple (LCM) using GCD
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

// Custom square root function using binary search
long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1; // Move to the right half
        else
            e = m - 1; // Move to the left half
    }
    return res;
}

/*
Checklist for problem-solving:
- Check all edge cases
- Check for integer overflow
- Check for corner cases
- Check for constraints
- Check for time complexity
- Check for array bounds
- Check for negative values
*/

void solve()
{
    int n;
    cin >> n; // Read the number of cars
    vector<int> a(n), b(n);

    // Read the order of cars entering the tunnel
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Read the order of cars exiting the tunnel
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Create a mapping from car ID to its exit index for quick lookup
    map<int, int> exitIndex;
    for (int i = 0; i < n; i++)
        exitIndex[b[i]] = i;

    int maxExit = -1; // Initialize the maximum exit index seen so far
    int ans = 0;      // Counter for the number of cars to be fined

    // Iterate through each car in the order they entered
    for (int i = 0; i < n; i++)
    {
        int currentExit = exitIndex[a[i]]; // Get the exit index of the current car
        if (currentExit < maxExit)
            ans++; // Current car exited before the maximum exit index, needs to be fined
        else
            maxExit = currentExit; // Update the maximum exit index
    }

    cout << ans << nl; // Output the result
}

/*
Problem Description:

Consider a tunnel on a one-way road. During a particular day, n cars numbered from 1 to n entered and exited the tunnel exactly once. All the cars passed through the tunnel at constant speeds.

A traffic enforcement camera is mounted at the tunnel entrance. Another traffic enforcement camera is mounted at the tunnel exit. Perfectly balanced.

Thanks to the cameras, the order in which the cars entered and exited the tunnel is known. No two cars entered or exited at the same time.

Traffic regulations prohibit overtaking inside the tunnel. If car i overtakes any other car j inside the tunnel, car i must be fined. However, each car can be fined at most once.

Formally, let's say that car i definitely overtook car j if car i entered the tunnel later than car j and exited the tunnel earlier than car j. Then, car i must be fined if and only if it definitely overtook at least one other car.

Find the number of cars that must be fined.

Input:
The first line contains a single integer n (2≤n≤10^5), denoting the number of cars.

The second line contains n integers a1,a2,…,an (1≤ai≤n), denoting the ids of cars in order of entering the tunnel. All ai are pairwise distinct.

The third line contains n integers b1,b2,…,bn (1≤bi≤n), denoting the ids of cars in order of exiting the tunnel. All bi are pairwise distinct.

Output:
Output the number of cars to be fined.

Examples:
Input:
5
3 5 2 1 4
4 3 2 5 1

Output:
2

Explanation:
Car 2 definitely overtook car 5, while car 4 definitely overtook cars 1, 2, 3, and 5. Cars 2 and 4 must be fined.

*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // Number of test cases

    while (t--)
        solve(); // Execute the solve function for each test case
}
