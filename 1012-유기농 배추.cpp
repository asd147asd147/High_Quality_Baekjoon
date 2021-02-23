#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int solve(){
    int cnt = 0;
    bool board[52][52];
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            board[i][j] = false;
        }
    }
    for(int k = 0; k < K; k++){
        int x,y;
        cin >> x >> y;
        board[y+1][x+1] = true;
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            queue<pair<int,int>> bug;
            if(board[i][j]) bug.push(make_pair(i,j)), cnt++;
            while(!bug.empty()){
                pair<int,int> pos = bug.front();
                bug.pop();
                board[pos.first][pos.second] = false;
                for(int i = 0; i < 4; i++){
                    if(board[pos.first+dy[i]][pos.second+dx[i]]) bug.push(make_pair(pos.first+dy[i],pos.second+dx[i]));
                }
            }
        }
    }
    return cnt;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        cout << solve() << "\n";
    }
	return 0;
}
