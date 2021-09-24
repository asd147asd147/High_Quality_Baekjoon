#include <bits/stdc++.h>

using namespace std;

vector<int> visited(26, 0);
vector<string> board;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int R, C;
int ans = 0;

void backtraking(int y, int x, int cnt){
    ans = max(ans, cnt);
    for(int k = 0; k < 4; k++){
        int sy = y + dy[k];
        int sx = x + dx[k];
        if(sy < 0 || sx < 0 || sy >= R || sx >= C) continue;
        if(visited[board[sy][sx] - 'A'] == 0){
            visited[board[sy][sx] - 'A'] = 1;
            backtraking(sy, sx, cnt+1);
            visited[board[sy][sx] - 'A'] = 0;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        board.push_back(s);
	}
    visited[board[0][0] - 'A'] = 1;
	backtraking(0,0, 1);
    cout << ans;
	return 0;
}
