#include <bits/stdc++.h>

using namespace std;

int N,ans;
int sticker[2][100001];
int dp[3][100001];

void solve(){
    cin >> N;
    int t;
    ans = 0;
    for(int i = 0; i < 2 ; i++){
        for(int j = 1; j <= N; j++){
            cin >> sticker[i][j];
        }
    }

    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for(int i = 1; i <= N; i++){
        dp[0][i] = max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = max(dp[0][i-1],dp[2][i-1]) + sticker[0][i];
        dp[2][i] = max(dp[0][i-1],dp[1][i-1]) + sticker[1][i];
    }

    cout << max({dp[0][N], dp[1][N], dp[2][N]})<< "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

	return 0;
}

