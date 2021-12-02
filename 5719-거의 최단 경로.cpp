#include <bits/stdc++.h>
#define INF 900'000'000
using namespace std;

int N,M,S,E;
vector<vector<pair<int,int>>> dist;
vector<int> min_path, visited;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int dijkstra(){
    priority_queue<tuple<int,int,int>> pq;
    pq.push({0,S,-1});
    visited[S] = 1;
    while(!pq.empty()){
        auto p = pq.top();
        min_path[get<1>(p)] = get<2>(p);
        if(get<1>(p) == E){
            return -get<0>(p);
        }
        pq.pop();
        visited[get<1>(p)] = 1;
        for(auto d : dist[get<1>(p)]){
            if(visited[d.first]) continue;
            if(d.second == INF) continue;
            pq.push({get<0>(p)-d.second,d.first,get<1>(p)});
        }
    }
    if(pq.empty()) return 0;

    return 0;
}

void find_path(int x){
    if(x == S) return;
    auto idx = lower_bound(dist[min_path[x]].begin(), dist[min_path[x]].end(), make_pair(x,0), comp) - dist[min_path[x]].begin();
    dist[min_path[x]][idx] = INF;
    find_path(min_path[x]);
}

void solve(){
    min_path.clear();
    min_path.resize(N+1);
    visited.clear();
    visited.resize(N+1);
    int minDist = dijkstra();
    find_path(E);
    while(1){
        for(int i = 0; i <= N; i++){
            min_path[i] = visited[i] = 0;
        }
        int curDist = dijkstra();
        if(curDist == 0){
            cout << -1 << "\n";
            return;
        }
        if(minDist < curDist){
            cout << curDist << "\n";
            return;
        }
        find_path(E);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin >> N >> M;
        if(N + M == 0) break;
        cin >> S >> E;
        dist.clear();
        dist.resize(N+1);
        for(int i = 0; i < M; i++){
            int U,V,P;
            cin >> U >> V >> P;
            dist[U].push_back({V,P});
        }
        solve();
    }

    return 0;
}

