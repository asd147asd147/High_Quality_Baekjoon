#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;
    vector<bool> visited(N,false);
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        queue<int> bfs;
        bfs.push(i);
        visited[i] = true;
        while(!bfs.empty()){
            int j = bfs.front();
            bfs.pop();
            for(auto b : graph[j]){
                if(!visited[b]) bfs.push(b),visited[b]=true;
            }
        }
        ans++;
    }
    cout << ans;

	return 0;
}
