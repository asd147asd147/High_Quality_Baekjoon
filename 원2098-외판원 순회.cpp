#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> vec(16,vector<int>(16));
int dp[16][1 << 16];

int tsp(int cur, int state){
    if(dp[cur][state] != -1) return dp[cur][state];

    if(state == (1 << N) - 1){
        if(vec[cur][0] != 0) return vec[cur][0];
        else return 987654321;
    }
    dp[cur][state] = 987654321;
    for(int i = 0; i < N; i++){
        if(vec[cur][i] && !(state & (1 << i))){
            dp[cur][state] = min(dp[cur][state],tsp(i, state | (1 << i)) + vec[cur][i]);
        }
    }
    return dp[cur][state];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> vec[i][j];

    memset(dp,-1,sizeof(dp));
    cout << tsp(0,1);

	return 0;
}
