#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;

    int map[M][N];
    int dp[M][N];

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> dp[i][j];
        }
    }

    int dp[0][0] = 1;
    for(int i = 1; i < N; i++){
        if(map[0][i-1] > map[0][i]){
            dp[0][i] = 1;
        }
        else{
            break;
        }
    }
    for(int j = 1; j < M; j++){
        if(map[j-1][0] > map[j][0]){
            dp[j][0] = 1;
        }
        else{
            break;
        }
    }

	return 0;
}
