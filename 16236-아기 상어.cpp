#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

typedef struct __shark{
    int x,y,size,eat=0;
    __shark(int s){size = s;}
} shark;

int N,t=0;
int aqua[23][23];
bool visited[23][23];
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
            aqua[i][j] = INF;
        }
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            cin >> aqua[i][j];
            if(aqua[i][j] == 9){
                baby.y = i; baby.x = j;
                aqua[i][j] = 0;
            }
            else if(aqua[i][j] > 0){
                fish[aqua[i][j]]++;
            }
        }
    }
    int level = 1;
    bool possible = 1;
    while(accumulate(fish+1,fish+level+1,0) > 0 && possible){
        queue<pair<int,int>> q;
        for(int i = 1; i < N+1; i++)
            for(int j = 1; j < N+1; j++)
                visited[i][j] = 0;
        q.push(make_pair(baby.y,baby.x));
        visited[baby.y][baby.x] = 1;
        int dist = -1;
        while(!q.empty()){
            int q_size = q.size();
            set<pair<int,int>> eat;
            for(int i = 0; i < q_size; i++){
                pair<int,int> pos = q.front();
                q.pop();
                if(0 < aqua[pos.first][pos.second] && aqua[pos.first][pos.second] <= level){
                    eat.insert(make_pair(pos.first,pos.second));
                }
                for(int k = 0; k < 4; k++){
                    int x = pos.second + dx[k];
                    int y = pos.first + dy[k];
                    if(aqua[y][x] <= baby.size && visited[y][x] == 0){
                        q.push(make_pair(y,x));
                        visited[y][x] = 1;
                    }
                }
            }
            dist++;
            if(eat.size() > 0){
                t+=dist;
                pair<int,int> pos = *(eat.begin());
                fish[aqua[pos.first][pos.second]]--;
                aqua[pos.first][pos.second] = 0;
                baby.y = pos.first, baby.x = pos.second;
                baby.eat++;
                if(baby.eat==baby.size){
                    baby.eat = 0;
                    baby.size++;
                    level++;
                }
                break;
            }
            else if(q.empty()){
                possible = 0;
                break;
            }
        }
    }
    cout << t;

	return 0;
}
