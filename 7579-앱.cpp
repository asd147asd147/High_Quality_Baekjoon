#include <bits/stdc++.h>

using namespace std;

int N, sum = 0;
long long M;
long long dp[10001] = {0,};
pair<long long,int> m[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> m[i].first;
    for(int i = 0; i < N; i++){
        cin >> m[i].second;
        sum += m[i].second;
    }

    for(int i = 0; i < N; i++){
        for(int s = sum; s-m[i].second >= 0; s--){
            dp[s] = max(dp[s], dp[s-m[i].second] + m[i].first);
        }
    }
    for(int i = 0; i <= sum; i++){
        if(dp[i] >= M){
            cout << i << " ";
            break;
        }
    }

	return 0;
}
