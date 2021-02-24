#include <bits/stdc++.h>

using namespace std;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
short box[102][102][102];
int N,M,H;

bool zeroCheck(){
    bool c = false;
    for(int k = 1; k < H+1; k++){
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < M+1; j++){
                if(box[k][i][j]==0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for(int k = 0; k < H+2; k++)
        for(int i = 0; i < N+2; i++)
            for(int j = 0; j < M+2; j++)
                box[k][i][j] = -1;

    queue<tuple<int,int,int>> tomato;
    for(int k = 1; k < H+1; k++){
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < M+1; j++){
                cin >> box[k][i][j];
                if(box[k][i][j] == 1){
                    tomato.push(make_tuple(k,i,j));
                }
            }
        }
    }

    int day = 0;
    int cnt = 0;
    int size = tomato.size();
    if(!zeroCheck()){
        cout << 0;
        return 0;
    }
    while(!tomato.empty()){
        tuple<int,int,int> pos = tomato.front();
        tomato.pop();
        for(int i = 0; i < 6; i++){
            int z = get<0>(pos)+dz[i];
            int y = get<1>(pos)+dy[i];
            int x = get<2>(pos)+dx[i];
//            cout << z << y << x << endl;
            if(box[z][y][x] == 0){
                box[z][y][x] = 1;
                tomato.push(make_tuple(z,y,x));
            }
        }
        cnt++;
        if(cnt==size){
            size = tomato.size();
            cnt = 0;
            day++;
        }
    }
    for(int k = 1; k < H+1; k++){
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < M+1; j++){
                if(box[k][i][j] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << day-1;

	return 0;
}
