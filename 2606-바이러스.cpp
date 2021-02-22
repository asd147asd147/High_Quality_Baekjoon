#include <bits/stdc++.h>

using namespace std;

queue<int> q;
bool visited[101] = {false,};

int main(){
    int C,N,a,b;
    cin >> C >> N;
    int com[C+1][C+1];
    for(int i = 0; i <= C; i++){
        for(int j = 0; j <= C; j++){
            com[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        com[a][b] = com[b][a] = 1;
    }

    int cnt = 0;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 1; i <= C; i++){
            if(com[t][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
    cout << cnt;
	return 0;
}
