#include <bits/stdc++.h>
#define INF 900'000'000
using namespace std;

int N,M,S,E;
vector<vector<pair<int,int>>> dist;
vector<int> visited;
vector<vector<int>> min_path;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int dijkstra(){
    priority_queue<tuple<int,int,vector<int>>> pq;
    int min_dist = 0;
    pq.push({0,S,{S}});
    visited[S] = 1;
    while(!pq.empty()){
        auto p = pq.top();
        if(get<1>(p) == E){
            if(min_dist == 0){
                min_path.push_back(get<2>(p));
                min_dist = -get<0>(p);
            }
            else if(min_dist == -get<0>(p)){
                min_path.push_back(get<2>(p));
            }
            else{
                return -get<0>(p);
            }
        }
        pq.pop();
        visited[get<1>(p)] = 1;
        for(auto d : dist[get<1>(p)]){
            if(visited[d.first]) continue;
            if(d.second == INF) continue;
            get<2>(p).push_back(d.first);
            pq.push({get<0>(p)-d.second,d.first,get<2>(p)});
        }
    }
    if(pq.empty()) return 0;

    return 0;
}

void find_path(int x){
    if(x == S) return;
    int idx = lower_bound(dist[min_path[x]].begin(), dist[min_path[x]].end(), make_pair(x,0), comp) - dist[min_path[x]].begin();
    dist[min_path[x]][idx] = make_pair(x,INF);
    find_path(min_path[x]);
}

void solve(){
    min_path.clear();
    min_path.resize(N+1);
    visited.clear();
    visited.resize(N+1);
    int minDist = dijkstra();
    if(minDist == 0){
        cout << -1 << "\n";
        return;
    }
    find_path(E);
    while(1){
        for(int i = 0; i <= N; i++){
            visited[i] = 0;
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

