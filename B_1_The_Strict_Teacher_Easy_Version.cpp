#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pof pop_front
#define pob pop_back
#define pf push_front
#define FILE(NAME) freopen(NAME".inp","r",stdin);freopen(NAME".out","w",stdout);
#define FASTER  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,x,y)  for(int i = x;i<=y;i++)
#define FOr(i,x,y)  for(int i = x;i<y;i++)
#define FOD(i,x,y)  for(int i =x;i>=y;i--)
#define FOd(i,x,y)  for(int i =x;i>y;i--)
#define el "\n"
#define sp " "
 
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename type1,typename type2> bool tmin(type1&a,type2 b){if(a>b){a=b;return true;}return false;}
template<typename type1,typename type2> bool tmax(type1&a,type2 b){if(a<b){a=b;return true;}return false;}
 
const ll MOD = 1e9 + 7;
const ll base = 31;
const int nmax = 1e5 + 7;
const ll INF = 1e18;
 
int t, n, m, q, a[nmax];
 
int main()
{
    //FILE()
    FASTER
    cin >> t;
    while(t -- )
    {
        cin >> n >> m >> q;
        FOR(i, 1, m)
            cin >> a[i];
        sort(a + 1, a + m + 1);
        FOR(i, 1, q)
        {
            int pos;
            cin >> pos;
            if(pos < a[1])
                cout << a[1] - 1;
            else if(pos > a[2])
                cout << n - a[2];
            else if(pos > a[1] && pos < a[2])
                cout << (a[2] - a[1])/2;
        }
        cout << el;
    }
    return 0;
}