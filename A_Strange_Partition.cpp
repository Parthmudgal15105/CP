#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
//ll arr[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n,d; cin>>n>>d;
		int a[n];
		ll ans=0, sum=0;
		for (int i=0; i<n; i++)
		{
			cin>>a[i];
			sum+= a[i];
			ans += a[i]/d + (a[i]%d !=0);
		}
		
		
		cout<<sum/d + (sum%d!=0)<<" "<<ans<<'\n';
		
	}
}