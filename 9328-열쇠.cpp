#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void solve(){
    string m[103];
    bool visited[103][103];
    int key = 0;
    int ans = 0;
    int H,W;
    cin >> H >> W;

    string s;
    for(int i = 1; i <= H; i++){
        cin >> s;
        m[i] = " " + s;
    }

    cin >> s;
    if(s != "0"){
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                visited[i][j] = false;
                for(int k = 0; k < s.size(); k++){
                    key = key | (1 << (s[k] - 'a'));
                    if(s[k] - 32 == m[i][j]){
                        m[i][j] = '.';
                    }
                }
            }
        }
    }
    queue<pair<int,int>> q;
    for(int i = 1; i <= H; i++){
        if(m[i][1] != '*') q.push({i,1});
        if(m[i][W] != '*') q.push({i,W});
    }
    for(int i = 2; i <= W-1; i++){
        if(m[1][i] != '*') q.push({1,i});
        if(m[H][i] != '*') q.push({H,i});
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if('A' <= m[p.first][p.second] && m[p.first][p.second] <= 'Z'){
            continue;
        }
        else if('a' <= m[p.first][p.second] && m[p.first][p.second] <= 'z'){
            if(!(key & (1 << (m[p.first][p.second] - 'a')))){
                key = key | (1 << (m[p.first][p.second] - 'a'));
                for(int i = 1; i <= H; i++){
                    for(int j = 1; j <= W; j++){
                        if(m[p.first][p.second] - 32 == m[i][j]){
                            m[i][j] = '.';
                            for(int k = 0; k < 4; k++){
                                int y = i + dy[k];
                                int x = j + dx[k];
                                if(x >= 1 && x <= W && y >= 1 && y <= H){
                                    if(visited[y][x]){
                                        q.push({y,x});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(m[p.first][p.second] == '$'){
            ans++;
            m[p.first][p.second] = '.';
        }

        for(int k = 0; k < 4; k++){
            int y = p.first + dy[k];
            int x = p.second + dx[k];
            if(x >= 1 && x <= W && y >= 1 && y <= H){
                if(m[y][x] != '*' && !visited[y][x]){
                    q.push({y,x});
                }
            }
        }
        visited[p.first][p.second] = true;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

	return 0;
}
