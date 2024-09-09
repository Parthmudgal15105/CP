#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define endl '\n';
#define lowbit(x) ((x)&-(x))
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
const int N=100005,M=100005;
typedef pair<ll,ll>PII;
 
 
void solve()
{
	int i,j;
	int n;
	cin>>n;
	int ans=1;
	for(i=2;i<=n;i++)
	{
		if(n%i==0) ans++;
		else break;
	}
	
	cout<<ans<<endl;
}
 
signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int i,j;
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
 