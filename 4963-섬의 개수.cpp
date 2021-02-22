#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[53][53];
int w,h;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

int main(){
    cin >> w >> h;
    while(w+h !=0 ){
        for(int i = 0; i < h+2; i++){
            for(int j = 0; j < w+2; j++){
                map[i][j] = 0;
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i+1][j+1];
            }
        }
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < h+2; i++){
            for(int j = 0; j < w+2; j++){
                if(map[i+1][j+1]){
                    map[i+1][j+1] = 0;
                    q.push(make_pair(i+1,j+1));
                    cnt++;
                }
                while(!q.empty()){
                    pair<int,int> pos = q.front();
                    q.pop();
                    for(int k = 0; k < 8; k++){
                        if(map[pos.first+dy[k]][pos.second+dx[k]]){
                            map[pos.first+dy[k]][pos.second+dx[k]] = 0;
                            q.push(make_pair(pos.first+dy[k],pos.second+dx[k]));
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";

        cin >> w >> h;
    }

	return 0;
}
