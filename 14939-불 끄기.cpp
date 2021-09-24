#include <bits/stdc++.h>

using namespace std;

vector<string> init_board(10);
int N = 10;
vector<int> vec;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 1000;
int c = 0;

void flip(int i, int j, vector<string> &board){
    if(board[i][j] == '#'){
        board[i][j] = 'O';
    }
    else{
        board[i][j] = '#';
    }

    for(int k = 0; k < 4; k++){
        int sx = j + dx[k];
        int sy = i + dy[k];
        if(sx < 0 || sx >= N || sy < 0 || sy >= N) continue;
        if(board[sy][sx] == '#'){
            board[sy][sx] = 'O';
        }
        else{
            board[sy][sx] = '#';
        }
    }
}

void func(){
    if(vec.size() == N){
        vector<string> board = init_board;
        c++;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(vec[i]){
                flip(0,i, board);
                cnt++;
            }
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i-1][j] == 'O'){
                    flip(i,j,board);
                    cnt++;
                }
            }
            for(int j = 0; j < N; j++){
                if(board[i-1][j] == 'O') return;
            }
        }
        for(int j = 0; j < N; j++){
            if(board[N-1][j] == 'O') return;
        }
        ans = min(ans, cnt);

        return;
    }
    vec.push_back(0);
    func();
    vec.pop_back();
    vec.push_back(1);
    func();
    vec.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < N; i++){
        cin >> init_board[i];
	}

    func();

//    cout <<c <<endl;
    cout << (ans==1000 ? -1 : ans);

	return 0;
}
