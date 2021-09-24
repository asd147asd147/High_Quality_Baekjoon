#include <bits/stdc++.h>

using namespace std;

int N, M;
int maze[1002][1002];
int mem[500003] = {0,};
int visited[1002][1002];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= M+1; j++){
            maze[i][j] = 2;
            visited[i][j] = 0;
        }
	}
	for(int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= M; j++){
            maze[i][j] = s[j-1]-'0';
        }
	}
    int cnt = 1;
	for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(maze[i][j] == 0 && visited[i][j] == 0){
                vector<pair<int,int>> path;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                while(!q.empty()){
                    auto p = q.front();
                    path.push_back(p);
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int y = p.first + dy[k];
                        int x = p.second + dx[k];
                        if(y <= 0 || y >= N+1 || x <= 0 || x >= M+1) continue;
                        if(maze[y][x] == 0 && visited[y][x] == 0){
                            q.push({y,x});
                            visited[y][x] = 1;
                        }
                    }
                }
                for(auto p : path){
                    visited[p.first][p.second] = cnt;
                }
                mem[cnt] = path.size() % 10;
                cnt++;
            }
        }
	}
	for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(maze[i][j] == 1){
                set<int> s;
                for(int k = 0; k < 4; k++){
                    s.insert(visited[i+dy[k]][j+dx[k]]);
                }
                int sum = 0;
                for(auto t : s){
                    sum += mem[t];
                }
                maze[i][j] = (sum+1) % 10;
            }
        }
	}

	for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << maze[i][j];
        }
        cout <<endl;
	}

	return 0;
}
