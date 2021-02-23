#include <iostream>

using namespace std;

typedef struct __info {
    unsigned int num = 0;
    int N, M;
} INFO;

int main(){
    int N;
    cin >> N;

    INFO dp[N][N];

    for(int i = 0; i < N; i++){
        cin >> dp[i][i].N >> dp[i][i].M;
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < N-i; j++){
            unsigned int min_num = 2147483647;
            int min_N = 500, min_M = 500;
            for(int k = 0; k < i; k++){
                if(min_num >= dp[j][k].N * dp[j][k].M * dp[k+1][i+j].M + dp[j][k].num + dp[k+1][i+j].num){
                    min_num = dp[j][k].N * dp[j][k].M * dp[k+1][i+j].M + dp[j][k].num + dp[k+1][i+j].num;
                    min_N = dp[j][k].N;
                    min_M = dp[k+1][i+j].M;
                }
            }
            dp[j][i+j].num = min_num;
            dp[j][i+j].N = min_N;
            dp[j][i+j].M = min_M;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j].num << " ";
        }
        cout << endl;
    }for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j].N << " ";
        }
        cout << endl;
    }for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j].M << " ";
        }
        cout << endl;
    }

    cout << dp[0][N-1].num;

	return 0;
}
