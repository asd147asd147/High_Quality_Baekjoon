#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool visited[100001] = {false,};
    int N,M;
    cin >> N >> M;
    visited[N] = true;
    queue<int> bfs;
    bfs.push(N);
    int ans = 0,cnt = 0;
    int size = 1;
    while(!bfs.empty()){
        int pos = bfs.front();
        if(pos == M) break;
        bfs.pop();
        if(pos!=0 && !visited[pos-1]){
            bfs.push(pos-1);
            visited[pos-1] = true;
        }
        if(pos!=100000 && !visited[pos+1]){
            bfs.push(pos+1);
            visited[pos+1] = true;
        }
        if(0 < 2*pos && 2*pos <= 100000 && !visited[2*pos] && pos < M){
            bfs.push(2*pos);
            visited[2*pos] = true;
        }
        cnt++;
        if(cnt == size){
            cnt = 0;
            size = bfs.size();
            ans++;
        }
    }
    cout << ans;

	return 0;
}
