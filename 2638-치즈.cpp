#include <bits/stdc++.h>

using namespace std;

int N,M,T = 0;
int vacuum = 0;
int board[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> cheese;

void check_vacuum(queue<pair<int,int>> q){
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int y = pos.first + dy[i];
            int x = pos.second + dx[i];
            if(y >= 0 && x >= 0 && y < N && x < M){
                if(board[y][x] == 2){
                    board[y][x] = 0;
                    q.push({y,x});
                    vacuum--;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                board[i][j] = 2;
                vacuum++;
            }
            else if(board[i][j] == 1){
                cheese.push({i,j});
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    board[0][0] = 0;
    check_vacuum(q);
    while(!cheese.empty()){
        q = queue<pair<int,int>>();
        queue<pair<int,int>> melt;
        int c_size = cheese.size();
        for(int k = 0; k < c_size; k++){
            auto p = cheese.front();
            cheese.pop();
            int near = 0;
            for(int i = 0; i < 4; i++){
                int y = p.first + dy[i];
                int x = p.second + dx[i];
                if(board[y][x] == 0) near++;
            }
            if(near >= 2){
                melt.push(p);
            }
            else{
                cheese.push(p);
            }
        }
        while(!melt.empty()){
            auto p = melt.front();
            melt.pop();
            board[p.first][p.second] = 0;
            q.push(p);
        }
        if(!q.empty()){
            check_vacuum(q);
        }
        T++;
    }
    cout << T;


	return 0;
}
