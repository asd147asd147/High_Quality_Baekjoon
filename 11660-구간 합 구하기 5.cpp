#include <bits/stdc++.h>

using namespace std;

int N,M;
int dp[1026][1026];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i <= N; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 2; j <= N; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] += dp[i-1][j];
        }
    }
    int x1,x2,y1,y2;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1] << "\n";
    }


	return 0;
}
