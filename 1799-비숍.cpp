#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int N;
int ans[2] = {0,};
bool visited1[20] = {0,};
bool visited2[20] = {0,};

void dfs(int cnt, int x, int y, int color){
    if(x >= N){
        x = x % 2 ? 0 : 1;
        y++;
    }
    if(y >= N){
        ans[color] = max(ans[color], cnt);
        return;
    }
    if(board[y][x] && !visited1[x + y] && !visited2[x-y+N]){
        visited1[x+y] = true;
        visited2[x-y+N] = true;
        dfs(cnt+1, x+2, y, color);
        visited1[x+y] = false;
        visited2[x-y+N] = false;
    }
    dfs(cnt, x+2, y, color);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}

