#include <bits/stdc++.h>

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
 
// Types
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
 
// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
 
// Constants
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
ll nCk(ll n, ll k)
{
	ll res = 1;
	for (ll i = 0; i < k; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}
/*----------------------------------------------------------------------------*/
void solve(){
	 int n,p;
        cin>>n>>p;
        vi A(n);
        vi B(n);
        for(int i = 0;i < n;i++){
            cin>>A[i];
        }
        for(int i = 0;i < n;i++){
            cin>>B[i];
        }
        vector<pair<ll,ll>> cost_cap;
        cost_cap.pb({p,n+1});//n+1 esse hi daal diya to represent chief jisko info pata hai pehle se 
        for(int i =0;i<n;i++){
            cost_cap.pb(make_pair(B[i],A[i]));
        }
        sort(all(cost_cap));

        int total = 1;//total residents informed  
        ll cost = p;
        int idx =0;

        while(total < n){
            int left = n - total;

            if(cost_cap[idx].second<=left){
                total += cost_cap[idx].second;
                cost = cost + cost_cap[idx].first * 1LL * cost_cap[idx].second;//toh jitna bhi cover kar skta usko uski cost se multilpy krke add karde
            }
            else{
                total = n;
                cost = cost + left*cost_cap[idx].first* 1LL ;//agar resident ke paas slots se zada shares pade ho.

            }
            idx++;
        }
    cout << cost << endl;
        //cost ko p bana de 
        //b[i] ka sabse chota index return AND COMPARE IT TO P 
        //a[i] ko minus till 0 and pick next two smallest b[i] index 
        //do this till all index are covered  
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