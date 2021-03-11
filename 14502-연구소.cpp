#include <bits/stdc++.h>

using namespace std;

int N,M,ans=0;
int lab[10][10];
bool visited[10][10];
vector<pair<int,int>> available;
vector<pair<int,int>> virus;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


void bfs(){
    int v_cnt = 0;
    fill(&visited[0][0], &visited[9][10],0);
    queue<pair<int,int>> q;
    for(auto v : virus){
        q.push(v);
        visited[v.first][v.second] = 1;
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int y = p.first + dy[i];
            int x = p.second + dx[i];
            if(!lab[y][x] && !visited[y][x]){
                visited[y][x] = 1;
                v_cnt++;
                q.push({y,x});
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if(!lab[i][j]) cnt++;
        }
    }
    ans = max(cnt-v_cnt, ans);
}

void check(int idx, int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i = idx; i < available.size()-2+cnt; i++){
        lab[available[i].first][available[i].second] = 1;
        check(i+1,cnt+1);
        lab[available[i].first][available[i].second] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i = 0; i < N+2; i++)
        for(int j = 0; j < M+2; j++)
            lab[i][j] = 1;

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            cin >> lab[i][j];
            if(!lab[i][j])
                available.push_back({i,j});
            else if(lab[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }

    for(int i = 0; i < available.size()-2; i++){
        lab[available[i].first][available[i].second] = 1;
        check(i+1,1);
        lab[available[i].first][available[i].second] = 0;
    }
    cout << ans;

	return 0;
}
