#include <iostream>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;

    char board[M][N];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    int MIN = 64;
    for(int i = 0; i < M-7; i++){
        for(int j = 0; j < N-7; j++){
            int cnt = 0;
            char c = 'B';
            for(int m = 0; m < 8; m++){
                for(int n = 0; n < 8; n++){
                    if(board[i+m][j+n] != c) cnt++;
                    c == 'B' ? c = 'W' : c = 'B';
                }
                c == 'B' ? c = 'W' : c = 'B';
            }
            MIN = min(MIN,min(cnt, 64-cnt));
        }
    }
    cout <<MIN;

	return 0;
}
