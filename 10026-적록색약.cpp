#include <bits/stdc++.h>

using namespace std;

char img1[103][103];
char img2[103][103];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < N+2; j++){
            img1[i][j] = img2[i][j] = 'N';
        }
    }
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            char c;
            cin >> c;
            img1[i][j] = img2[i][j] = c;
        }
    }
    vector<queue<pair<int,int>>> bfs(3);
    map<char,int> RGB;
    RGB['R'] = 0, RGB['G'] = 1, RGB['B'] = 2, RGB['N'] = 3;
    int normal = 0, lesion = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            if(img1[i][j] == 'N') continue;
            int color = RGB[img1[i][j]];
            bfs[color].push(make_pair(i,j));
            img1[i][j] = 'N';
            while(!bfs[color].empty()){
                int y = bfs[color].front().first;
                int x = bfs[color].front().second;
                bfs[color].pop();
                for(int k = 0; k < 4; k++){
                    if(RGB[img1[y+dy[k]][x+dx[k]]] != color) continue;
                    bfs[color].push(make_pair(y+dy[k],x+dx[k]));
                    img1[y+dy[k]][x+dx[k]] = 'N';
                }
            }
            normal++;
        }
    }
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            if(img2[i][j] == 'N') continue;
            int color = RGB[img2[i][j]];
            bfs[color].push(make_pair(i,j));
            img2[i][j] = 'N';
            while(!bfs[color].empty()){
                int y = bfs[color].front().first;
                int x = bfs[color].front().second;
                bfs[color].pop();
                for(int k = 0; k < 4; k++){
                    if(color == 1 || color == 0){
                        if(RGB[img2[y+dy[k]][x+dx[k]]] != 0 && RGB[img2[y+dy[k]][x+dx[k]]] != 1) continue;
                    }
                    else{
                        if(RGB[img2[y+dy[k]][x+dx[k]]] != color) continue;
                    }
                    bfs[color].push(make_pair(y+dy[k],x+dx[k]));
                    img2[y+dy[k]][x+dx[k]] = 'N';
                }
            }
            lesion++;
        }
    }
    cout << normal << " " << lesion;


	return 0;
}
