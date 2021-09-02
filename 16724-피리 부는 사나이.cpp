#include <bits/stdc++.h>

using namespace std;

map<char, int> arrow = {
    {'D', 0},
    {'U', 1},
    {'L', 2},
    {'R', 3},
};

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,M;
	cin >> N >> M;

    string maze[N];
    int visited[N][M];

	for(int i = 0; i < N; i++){
        cin >> maze[i];
	}

	for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = 0;
        }
	}

	int cnt = 1;
	for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j]){
                vector<pair<int,int>> path;
                int x = 0, y = 0;
                path.push_back({i,j});
                visited[i][j] = cnt;
                int direct = arrow[maze[i+y][j+x]];
                x += dx[direct];
                y += dy[direct];

                while(visited[i+y][j+x] == 0){
                    path.push_back({i+y, j+x});
                    visited[i+y][j+x] = cnt;
                    direct = arrow[maze[i+y][j+x]];
                    x += dx[direct];
                    y += dy[direct];
                }
                if(visited[i+y][j+x] != cnt){
                    for(auto p : path){
                        visited[p.first][p.second] = visited[i+y][j+x];
                    }
                }
                else{
                    cnt++;
                }
            }
        }
	}
	cout << cnt-1;

	return 0;
}
