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
    int tp = N;
    while(0 < tp && tp <= 100000){
        if(0 < 2*tp && 2*tp <= 100000 && !visited[2*tp]){
            bfs.push(2*tp);
            visited[2*tp] = true;
        }
        tp *= 2;
    }
    int ans = 0, cnt = 0;
    int size = bfs.size();
    while(!bfs.empty()){
        int pos = bfs.front();
        bfs.pop();
        if(pos == M) break;
        if(pos!=0 && !visited[pos-1]){
            bfs.push(pos-1);
            visited[pos-1] = true;
            tp = pos-1;
            while(0 < tp && tp <= 100000){
                if(0 < 2*tp && 2*tp <= 100000 && !visited[2*tp]){
                    bfs.push(2*tp);
                    visited[2*tp] = true;
                }
                tp *= 2;
            }
        }
        if(pos!=100000 && !visited[pos+1]){
            bfs.push(pos+1);
            visited[pos+1] = true;
            tp = pos+1;
            while(0 < tp && tp <= 100000){
                if(0 < 2*tp && 2*tp <= 100000 && !visited[2*tp]){
                    bfs.push(2*tp);
                    visited[2*tp] = true;
                }
                tp *= 2;
            }
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
