#include <iostream>

using namespace std;

int N;
int board[15][15];

int isValid(int j, int k){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += board[j][i];
    }
    for(int i = 0; i < N; i++){
        sum += board[i][k];
    }
    return !sum;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = 0;

    for(int i = 0; i < N; i++){
        board[0][i] = 1;
        for(int j = 1; j < N; ){
            for(int k = 0; k < N; k++){
                if(isValid(j,k)){
                    board[j][k] = 1;
                }
                else{
                    continue;
                }
            }
        }
    }

	return 0;
}
