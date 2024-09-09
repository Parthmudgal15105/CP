#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
 
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
 
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int Gcd = findGCD(arr, n);
    int ans = 0;
 
    if (Gcd > n)
    {
        cout << "No" << endl;
    }
    else
    {
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (gcd(arr[i], arr[j]) <= 2 && i != j)
                {
                    ans = 1;
                    break;
                }
            }
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
 
    while (t--)
    {
 
        solve();
    }
}
