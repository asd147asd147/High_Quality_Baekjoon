#include <bits/stdc++.h>

using namespace std;

bool room[18][18];

pair<int,int> m[3] = {{0,1},{1,0},{1,1}};

int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N;
	for(int i = 0; i < N+2; i++)
        for(int j = 0; j < N+2; j++)
            room[i][j] = 1;

	for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            cin >> room[i][j];
        }
	}
	int cnt = 0;
	queue<tuple<int,int,int>> bfs;
	bfs.push({1,2,0});
	while(!bfs.empty()){
        auto pos = bfs.front();
        bfs.pop();
        if(get<0>(pos) == N && get<1>(pos) == N){
            cnt++;
            continue;
        }
        int y,x;
        bool valid = true;
        for(int i = 0; i < 2; i++){
            y = get<0>(pos) + m[i].first;
            x = get<1>(pos) + m[i].second;
            if(room[y][x] != 1){
                if(get<2>(pos) == 1 && i == 1 || get<2>(pos) == 0 && i == 0 || get<2>(pos) == 2)
                    bfs.push({y,x,i});
            }
            else valid = false;
        }
        y = get<0>(pos) + m[2].first;
        x = get<1>(pos) + m[2].second;
        if(room[y][x] != 1 && valid){
            bfs.push({y,x,2});
        }
	}
	cout << cnt;

	return 0;
}
