#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int solve(){
    long long n;
    string str;
    cin>>n>>str;
    vector<int> prefix(n),suffix(n);
    set<char> s;
    for(int i=0;i<n;i++){
        s.insert(str[i]);
        prefix[i]=s.size();
    }
    s.clear();
    for(int i=n-1;i>=0;i--){
        s.insert(str[i]);
        suffix[i]=s.size();
    }
    int ans=0,maxo=0;
    for(int i=0;i<n-1;i++){
        ans=prefix[i]+suffix[i+1];
        maxo=max(maxo,ans);
    }
    cout<<maxo<<endl;
    return 0;
}
int main()
{
    int testCase=1;
    cin>>testCase;
    while(testCase--){
        solve();
    }
    return 0;
}