#include <iostream>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    int dp[K][N+1];

    for(int i = 0; i < K; i++){
        for(int j = 0; j < N+1; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < N+1; i++)
        dp[0][i] = 1;


    for(int i = 1; i < K; i++){
        for(int j = 0; j < N+1; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%1000000000;
            }
        }
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[K-1][N];
	return 0;
}
