#include<iostream>
using namespace std;
void solve(){
	int n,a,b,p=-1,ans=0,s=1;
	cin>>n;
	int t[2*n+5]={};
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==p)s++;
		else s=1;
		t[a]=max(t[a],s);
		p=a;
	}
	p=-1;
	s=1;
	for(int i=0;i<n;i++){
		cin>>b;
		if(b==p)s++;
		else s=1;
		ans=max(ans,s+t[b]);
		p=b;
	}
	for(int i=0;i<=2*n;i++)ans=max(ans,t[i]);
	cout<<ans<<endl;
	return;
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
 