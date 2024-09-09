#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N, D;
    cin >> N >> D;
 
    vector<int> P(N);
    for(int i = 0; i < N; ++i) {
        cin >> P[i];
    }
 
    sort(P.rbegin(), P.rend());
 
    int players = 0;  
    int i = 0;   
    int wins = 0; 
 
    while(i<N && players<=N){
        int x = ceil((D+1) / (P[i]*1.0));
            players += x;
            if(players<=N){
                wins++;
            }
    i++;
    }
    cout << wins << endl;
}
