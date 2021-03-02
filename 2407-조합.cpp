#include <bits/stdc++.h>

using namespace std;

int n,m;
unsigned long long dp[101][101][4];
unsigned long long mod = 10000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dp[i][0][0] = 1;
        dp[i][i][0] = 1;

        dp[i][0][1] = 0;
        dp[i][i][1] = 0;

        dp[i][0][2] = 0;
        dp[i][i][2] = 0;
    }

    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i; j++)
            for(int k = 0; k < 3; k++)
                dp[i][j][k] = 0;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            for(int k = 0; k < 3; k++){
                dp[i][j][k] += dp[i-1][j-1][k] + dp[i-1][j][k];
                dp[i][j][k+1] += dp[i][j][k]/mod;
                dp[i][j][k] %= mod;
            }
        }
    }

    for(int k = 0; k < 3; k++){
        if(dp[n][m][2-k] == 0) continue;
        cout << dp[n][m][2-k];
    }
	return 0;
}
