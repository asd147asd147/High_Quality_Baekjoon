#include <bits/stdc++.h>

using namespace std;

int R,C,T;
int room[52][52];
vector<int> cond;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void diffusion(){
    vector<pair<int,int>> mic;
    for(int i = 1; i < R+1; i++){
        for(int j = 1; j < C+1; j++){
            if(room[i][j] >= 5) mic.push_back({i,j});
        }
    }
    vector<tuple<int,int,int>> q;
    for(int i = 0; i < mic.size(); i++){
        int cnt = 0;
        for(int k = 0; k < 4; k++){
            int y = mic[i].first + dy[k];
            int x = mic[i].second + dx[k];
            int e = room[mic[i].first][mic[i].second] / 5;
            if(room[y][x] >= 0){
                cnt++;
                q.push_back({y,x,e});
            }
        }
        room[mic[i].first][mic[i].second] -= (room[mic[i].first][mic[i].second] / 5)*cnt;
    }

    for(int i = 0; i < q.size(); i++){
        room[get<0>(q[i])][get<1>(q[i])] += get<2>(q[i]);
    }
}

void airCondition(){
    for(int i = cond[0]-1; i > 1; i--){
        room[i][1] = room[i-1][1];
    }
    for(int i = 1; i < C; i++){
        room[1][i] = room[1][i+1];
    }
    for(int i = 1; i < cond[0]; i++){
        room[i][C] = room[i+1][C];
    }
    for(int i = C; i > 2; i--){
        room[cond[0]][i] = room[cond[0]][i-1];
    }
    room[cond[0]][2] = 0;

    for(int i = cond[1]+1; i < R; i++){
        room[i][1] = room[i+1][1];
    }
    for(int i = 1; i < C; i++){
        room[R][i] = room[R][i+1];
    }
    for(int i = R; i > cond[1]; i--){
        room[i][C] = room[i-1][C];
    }
    for(int i = C; i > 2; i--){
        room[cond[1]][i] = room[cond[1]][i-1];
    }
    room[cond[1]][2] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> T;

	for(int i = 0; i < R+2; i++)
        for(int j = 0; j < C+2; j++)
            room[i][j] = -2;

    for(int i = 1; i < R+1; i++){
        for(int j = 1; j < C+1; j++){
            cin >> room[i][j];
            if(room[i][j] == -1)
                cond.push_back(i);
        }
    }

    for(int t = 0; t < T; t++){
        diffusion();
        airCondition();
    }

    int sum = 0;
    for(int i = 1; i < R+1; i++){
        for(int j = 1; j < C+1; j++){
            if(room[i][j] > 0) sum+=room[i][j];
        }
    }
    cout << sum;
	return 0;
}
