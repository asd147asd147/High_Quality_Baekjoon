#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tomato[1003][1003];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M,N;
    cin >> M >> N;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            tomato[i][j] = -1;
        }
    }

    queue<pair<int,int>> pos;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            cin >> tomato[i][j];
            if(tomato[i][j]==1) pos.push(make_pair(i,j));
        }
    }
    int ans = 0;
    int cnt = 0;
    int size = pos.size();
    while(!pos.empty()){
        pair<int,int> tmp = pos.front();
        pos.pop();
        for(int i = 0; i < 4; i++){
            int y = tmp.first+dy[i];
            int x = tmp.second+dx[i];
            if(tomato[y][x] == 0){
                pos.push(make_pair(y,x));
                tomato[y][x] = 1;
            }
        }
        cnt++;
        if(cnt == size){
            ans++;
            size = pos.size();
            cnt = 0;
        }
    }
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if(tomato[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans-1;

	return 0;
}
