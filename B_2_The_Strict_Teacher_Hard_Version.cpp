#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
 
#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
 
 
// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
// Types of declarations /////////////////////////////////
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
 
// Utils ///////////////////////////////////////////////
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
 
// Constants/////////////////////////////////////////////
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// Odd Even /////////////////////////////////////////////
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) return false;
    }
    return true;
}

///////////////////////////////////////////////////////// LCM GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; 
}
////////////////////////////////////////////////////////// SQR ROOT

long long sqrt(long long x) {
    long long s = 0, e = 2e9, res = s;
    while (s <= e) {
        long long m = (s + e) / 2;
        if (m * m <= x) res = m, s = m + 1;
        else e = m - 1;
    }
    return res;
}

/*----------------------------------------------------------------------------*/
void solve() {
    
        int n, m, q;
        cin >> n >> m >> q;  

        vector<int> b(m);  
        for (int i = 0; i < m; i++) { 
            cin >> b[i]; 
        }

        vector<int> a(q);  
        for (int i = 0; i < q; i++) { 
            cin >> a[i]; 
        }

        if(m == 1){
            int first = abs(b[0] - 1);
            int second = abs(b[0] - n);
            int maxDistance = max(first , second);

            cout << maxDistance << endl;
        }
        else{

        for (int i = 0; i < q; i++) {
            int minDistance = abs(a[i] - b[0]); 
            for (int j = 1; j < m; j++) {
               
                minDistance = min(minDistance, abs(a[i] - b[j]));
            }
            if(minDistance == 0){
                cout << 0 << endl;
            }
            else if(even(n)){
            cout << minDistance << endl;  }
            else{
                cout << minDistance + 1 << endl;
            }
        }
        }
    
}
 
/*

*/
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1;
	cin>>t;
	while(t--)
		solve();
}
