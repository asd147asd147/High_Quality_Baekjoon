#include <bits/stdc++.h>
#define INF 500000

using namespace std;

int N,M,dist=INF;

int maze[1003][1003];
bool visited[2][1003][1003];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
    queue<tuple<int,int,int>> q;
    q.push({1,1,0});
    visited[0][1][1] = 1;
    int cnt = 0, size = q.size(), d = 0;
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int state = get<2>(q.front());
        if(y == N && x == M){
            dist = d+1;
            return;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            if(maze[y+dy[i]][x+dx[i]] == 0 && visited[state][y+dy[i]][x+dx[i]] == 0){
                q.push({y+dy[i],x+dx[i],state});
                visited[state][y+dy[i]][x+dx[i]] = 1;
            }
            else if(maze[y+dy[i]][x+dx[i]] == 1 && state == 0){
                q.push({y+dy[i],x+dx[i],1});
            }
        }
        cnt++;
        if(cnt == size){
            cnt = 0;
            size = q.size();
            d++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            maze[i][j] = 2;
            visited[0][i][j] = 0;
            visited[1][i][j] = 0;
        }
    }

    string s;
    for(int i = 1; i < N+1; i++){
        cin >> s;
        for(int j = 1; j < M+1; j++){
            maze[i][j] = s[j-1] - '0';
        }
    }
    if(N == 1 && M == 1){
        cout << 1;
        return 0;
    }
    bfs();
    if(dist == INF)
        cout << -1;
    else
        cout << dist;

	return 0;
}
