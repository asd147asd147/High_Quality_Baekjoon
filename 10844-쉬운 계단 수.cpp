#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int dp[N][10];
    dp[0][0] = 0;
    for(int i = 1; i < 10; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i < N; i++){
        dp[i][0] = dp[i-1][1];
        for(int j = 1; j < 9; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
        dp[i][9] = dp[i-1][8];
    }

    int ans = 0;
    for(int i = 0; i < 10; i++){
        ans += dp[N-1][i];
        ans = ans % 1000000000;
    }
    cout << ans;
	return 0;
}
