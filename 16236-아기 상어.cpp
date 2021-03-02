#include <bits/stdc++.h>

using namespace std;

typedef struct __shark{
    int x,y,size,eat=0;
    __shark(int s){size = s;}
} shark;

int N,t=0;
int aqua[23][23];
shark baby(2);
int fish[7] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < N+2; j++){
            aqua[i][j] = 8;
        }
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            cin >> aqua[i][j];
            if(aqua[i][j] == 9){
                baby.y = i; baby.x = j;
            }
            else if(aqua[i][j] > 0){
                fish[aqua[i][j]]++;
            }
        }
    }
    int level = 1;
    while(fish[level] > 0){
        queue<pair<int,int>> q;
        q.push(make_pair(baby.y,baby.x));
        while(!q.empty()){
            pair<int,int> pos = q.front();
            for(int k = 0; k < 4; k++){
                int x = pos.second + dx[k];
                int y = pos.first + dy[k];
                if(aqua[y][x] <= baby.size){
                    q.push(make_pair(y,x));
                }
            }
        }
    }

	return 0;
}
