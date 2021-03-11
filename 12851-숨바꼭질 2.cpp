#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    vector<pair<int,int>> visited(100001,{0,100001});
    cin >> N >> M;

    queue<pair<int,int>> bfs;
    bfs.push({N,0});
    visited[N] = {0,0};
    bool vaild = true;
    while(!bfs.empty()){
        auto p = bfs.front();
        bfs.pop();
        if(visited[p.first].second == p.second){
            visited[p.first].first++;
        }
        else if(visited[p.first].second > p.second){
            visited[p.first].second = p.second;
            visited[p.first].first = 1;
        }
        if(visited[M].first > 0){
            vaild = false;
        }

        if(p.first != 0){
            if(!visited[p.first-1].first && vaild){
                bfs.push({p.first-1, p.second+1});
            }
        }
        if(p.first < 100000){
            if(!visited[p.first+1].first && vaild){
                bfs.push({p.first+1, p.second+1});
            }
        }
        if(0 < 2*p.first && 2*p.first <= 100000 && p.first < M){
            if(!visited[p.first*2].first && vaild){
                bfs.push({p.first*2, p.second+1});
            }
        }

    }
    cout << visited[M].second << "\n" << visited[M].first;

	return 0;
}
