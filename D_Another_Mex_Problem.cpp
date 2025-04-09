#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

void solve()
{

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (A[n - 1] != n + 1)
    {
        cout << 0 << "\n";
        return;
    }

    long long ans = 1;
    long long freeCount = 0;

    if (A[0] == 1)
    {
        freeCount = 1;
    }
    else if (A[0] == 2)
    {
        freeCount = 0;
    }
    else
    {
        cout << 0 << "\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {

        if (A[i] < A[i - 1])
        {
            cout << 0 << "\n";
            return;
        }

        if (A[i] == A[i - 1])
        {
            freeCount++;
            ans = (ans * freeCount) % MOD;
        }
        else
        {

            int gap = A[i] - A[i - 1] - 1;
            // If there aren’t enough free numbers to cover the gap, the MEX pattern isn’t achievable.
            if (freeCount < gap)
            {
                cout << 0 << "\n";
                return;
            }
            // Consume the free numbers that are now forced.
            freeCount -= gap;
        }
    }
    cout << ans % MOD << "\n";
}
/*
Soumil is really fond of permutations and he has recently become aware of the concept of prefix MEX
 arrays. A permutation P
 of 1,...,n
 has its prefix MEX
 array A
 defined as

A[i]=MEX(P[1:i])
for 1≤i≤n
, where P[1:i]
 denotes the elements P[1],...P[i]
 and MEX
 of an array is defined as the smallest positive integer not present in it. More formally, for an array B
,

MEX(B)=min{x≥1 | x∉B}
You are given an array A
 of length n
, where 1≤A[j]≤n+1
. Your task is to determine how many permutations P
 of 1,...,n
 exist such that their prefix MEX array is exactly A
. Since the answer can be large, output it modulo 109+7
.

Input
The first line of input contains a number t
 (1≤t≤5⋅103)
 — the number of test cases.

In the first line of each test case, there is a single integer n
 (1≤n≤105)
 — the length of the array A
.

In the second line of each test case, there are n
 space separated integers A[j]
 −
 (1≤A[j]≤n+1)
 — the elements of the array A
.

It is guaranteed that the sum of n
 across all test cases does not exceed 106
.

Output
For each test case, output the number of permutations (modulo 109+7
) of length n
 which have the given array A
 as their prefix MEX
 array.

Example
InputCopy
2
2
1 3
4
1 2 2 5
OutputCopy
1
2
Note
In the first test case, n=2
. The only possible permutations are [1,2]
 and [2,1]
 which have [2,3]
 and [1,3]
 as their prefix MEX
 arrays respectively. So, for A=[1,3]
, answer is 1
.



*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
